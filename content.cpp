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

#ifdef _WIN32
#include<conio.h>
#else
#include <termio.h>

char getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
 
     if (tcgetattr(fd, &tm) < 0) {
          return -1;
     }
 
     tm_old = tm;
     cfmakeraw(&tm);
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {
          return -1;
     }
 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
          return -1;
     }
    
     return ch;
}
#endif

int main() {

    #include"_maps.h"
    bool isq = false;
    int _LEVEL = sizeof(_MAPS_def)/_SIZE;
    for(int i = 0; i< _LEVEL && !isq; i++) {
        map m;   
        m.read(_MAPS_def[i]);
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
        std::cout << "****回退(b)方向控制（asdw)****"<<std::endl;

        in = getch();
      
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
    if(!isq)
        std::cout << "恭喜你,完成了所有关卡!"<<std::endl;
    else 
        std::cout <<"再见!"<<std::endl;
    getch();
    return 0;
}
