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

content::content(map *m){
    this->m = m;
    for(int i = 0; i< (m->_w())*(m->_h()); i++) {
        m->blocks()[i].setContent(this);
        if(m->blocks()[i].cover != nullptr && m->blocks()[i].cover->type() == PERSON){
            p = (person *)(m->blocks()[i].cover);
        }
    }
}

content::~content(){
}
map* content::getmap(){
    return m;
}

person *content::_p(){
    return p;
}

void content::display() {
    //   m->blocks()[48]._rear()->move(UP);
    //   m->blocks()[74]._rear()->move(RIGHT);
    //   m->blocks()[75]._rear()->move(LEFT);
    //   m->blocks()[78]._rear()->move(RIGHT);
    //   m->blocks()[104]._rear()->move(DOWN);

    for(int i = 0; i < m->_w() * m->_h(); i++) {
        if(i % m->_w() == 0) std::cout<<std::endl;
        m->blocks()[i].display(0);
    }
    std::cout<<std::endl; 
}

map::map():w(14),h(13) {
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


void content::actinput(direct d){
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
    memery.push(d);
}

int content::popm() {
    if(memery.empty()) 
        return -1;
    else {
        int t = memery.top();
        memery.pop();
        return t;
    }
}

int main() {

    #include"_maps.cpp"
    bool isq = false;
    for(int i = 0; i< _LEVEL && !isq; i++) {
        map m;   
        m.read(_MAPS[i]);
        content c(&m);
        char in;
        bool isf = false;
        while(!isq && !isf) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        std::cout<<"关卡"<<(i+1)<<std::endl;
        c.display();
        std::cout << "asdw控制方向请输入回车确定:";
        std::cin>>in;
        switch (in)
        {
            case 'w' :
            case 'W' :
               c.actinput(UP);
               break;
            case 's' :
            case 'S' :
                c.actinput(DOWN);
                break;
            case 'a' :
            case 'A' :
                c.actinput(LEFT);
                break;
            case 'd' :
            case 'D' :
                c.actinput(RIGHT);
                break;
            case 'b':
            case 'B':
                c.back();
                break;
            case 'q':
            case 'Q':
                isq = true;
                break;
            default:
                break;
            }
            isf = c.isfinsh();
        }
    }
    if(!isq)std::cout << "恭喜你,完成了所有关卡!"<<std::endl;
    return 0;
}
