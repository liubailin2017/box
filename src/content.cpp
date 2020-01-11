#include"content.h"
#include<iostream>

#include"../SDLdraw/drawlist.h"

direct btranf(direct d) {
    if(d == RIGHT)
        return LEFT;
    else if(d == LEFT)
        return RIGHT;
    else if(d == UP ) 
        return DOWN;
    else /* if(d = DOWN)*/
        return UP;
}

void content::back() {
    int t = popm();
    if(t == -1) return ;
    bool ispull = ((_PUSH_BYTE & t) == _PUSH_BYTE);
    direct d = btranf((direct)((~_PUSH_BYTE) & t));
    
    _p()->back_move(d);
    if(ispull){
        _p()->pull();
    }
}

void content::init(){
    for(int i = 0; i< (m->_w())*(m->_h()); i++) {
        m->blocks()[i].setContent(this); 
        if(m->blocks()[i].cover != nullptr && m->blocks()[i].cover->type() == PERSON) {
            if(p) {
                delete p;
                //if(p->lay) delete  p;
            }
            p = (person *)(m->blocks()[i].cover);
        }
    }
    memery.clear();
}

content::content(map *m):m(m),p(NULL){
    init();
}

content::~content(){
    if(p!= nullptr)
        delete p;
}
person* content::_persion() {
    return p;
}
map* content::getmap(){
    return m;
}

person *content::_p(){
    return p;
}

void content::display() {
    for(int i = 0; i < m->_w() * m->_h(); i++) {
        m->blocks()[i].display(0);
        //if((i+1) % m->_w() == 0) std::cout<<std::endl;
    }
}

map::map(): b(NULL),w(0),h(0){//max size 448 as  28*16
}

map::~map() {
    if(b) delete[] b;
}

int map::_w() { return w; }
int map::_h() {return h; }

block* map::blocks(){
    return b;
}

void map::read(int d[]) {
    w=d[0];
    h=d[1];
    printf("%d %d\n",w,h);
    if(b) delete[] b;
    b =(block*) new block[w*h];
    int offset = 2;
    for(int i = 0; i< w*h; i++) {
        switch (d[i+offset]) {
            case BLOCK:
                break;
            case PERSON:
                b[i].rear->_cover(new person);
                break;
            case BOX:
                b[i].rear->_cover(new box); 
                break;
            case WALL:
                b[i]._cover(new wall); 
                break;
            case INTEND:
                b[i].rear->_cover(new intend);
                break;
            case PERSON + INTEND :
                b[i].rear->_cover(new intend); 
                b[i].rear->_cover(new person);
                break;
            case BOX + INTEND :
                b[i].rear->_cover(new intend); 
                b[i].rear->_cover(new box);
                break;
        }
    }
}


bool content::actinput(direct d){
    if(p==nullptr) {
        std::cout<<"content::actinput: nullptr err"<<std::endl;
        return false;
    }
    p->befor_move(d);
    bool result = p->move(d);
 //   std::cout << result<<std::endl;
    return result;
}

bool content::isfinsh() {
    bool isf = true;
    int n = m->_w() * m->_h();
    for(int i = 0; i< n; i++) { 
        if(m->blocks()[i]._rear()->type() == BOX)
            if(m->blocks()[i]._rear()->_lay() == nullptr || m->blocks()[i]._rear()->_lay() ->type() != INTEND)
                 isf = false;
    }
    return isf;
}

void content::pushm(int d){ 
    memery.push_back(d);
}

int content::popm() {
    if(memery.empty()) 
        return -1;
    else {
        int t = memery.back();
        memery.pop_back();
        return t;
    }
}

int content::popf() {
    if(memery.empty()) 
        return -1;
    else {
        int t = memery.front();
        memery.pop_front();
        return t;
    }
}

int content::msize() {
    return memery.size();
}

