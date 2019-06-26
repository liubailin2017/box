#include"content.h"
#include<iostream>
direct btranf(direct d) {
    if(d == RIGHT) return LEFT;
    if(d == LEFT) return RIGHT;
    if(d == UP ) return DOWN;
    if(d = DOWN) return UP;
}

void content::back() {
    int t = popm();
    if(t == -1) return ;
    bool ispull = ((_PUSH_BYTE & t) == _PUSH_BYTE);
    direct d = btranf((direct)((~_PUSH_BYTE) & t));
    
    _p()->back_move(d);
    if(ispull){
        std::cout <<"pull"<<std::endl;
        _p()->pull();
    }
}

content::content(map *m):m(m){
    for(int i = 0; i< (m->_w())*(m->_h()); i++) {
        m->blocks()[i].setContent(this);
        if(m->blocks()[i].cover != nullptr && m->blocks()[i].cover->type() == PERSON){
            p = (person *)(m->blocks()[i].cover);
        }
    }
}

content::~content(){
    if(p!= nullptr)
        delete p;
}

map* content::getmap(){
    return m;
}

person *content::_p(){
    return p;
}

void content::display() {
    std::cout<<m->_w() <<std::endl<<m->_h() <<std::endl;
    for(int i = 0; i < m->_w() * m->_h(); i++) {
        m->blocks()[i].display(0);
        if((i+1) % m->_w() == 0) std::cout<<std::endl;
    }
}

map::map():w(28),h(16) {
    b =(block*) new block[w*h];
}

map::~map() {
    delete[] b;
}

int map::_w() { return w; }
int map::_h() {return h; }

block* map::blocks(){
    return b;
}

void map::read(int d[]) {
    for(int i = 0; i< w*h; i++) {
        switch (d[i]) {
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
void map::read(int d[],int w,int h) {

    if(w>_w() || h >_h()) {
        delete[] b;
        b =(block*) new block[w*h];
    }
    map::w = w;
    map::h = h;
    read(d);
}

void content::actinput(direct d){
    if(p==nullptr) {
        std::cout<<"content::actinput: nullptr err"<<std::endl;
        return;
    }
    p->move(d);
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

