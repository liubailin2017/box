#include"content.h"
#include<iostream>
content::content(map *m){
    this->m = m;
    for(int i = 0; i< (m->w)*(m->h); i++) {
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

    for(int i = 0; i < m->w * m->h; i++) {
        if(i % m->w == 0) std::cout<<std::endl;
        m->blocks()[i].display(0);
    }
    std::cout<<std::endl; 
}

map::map() {

}

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
    int n = m->w * m->h;
    for(int i = 0; i< n; i++) { 
        if(m->blocks()[i]._rear()->type() == BOX)
            if(m->blocks()[i]._rear()->_lay() == nullptr || m->blocks()[i]._rear()->_lay() ->type() != INTEND)
                 isf = false;
    }
    return isf;
}

int main() {

/* 8: 目的地 ☆
 4: 墙壁  ■
 2: 箱子  □
 1: 玩家  ♀
 0: 空地
 10:箱子已在目的地  ★
 9:人在目的地上  ♂ 
 */
/**最外面一圈只能使用墙壁(4)*/
    #include"_maps.cpp"
    for(int i = 0; i< _LEVEL; i++){
        map m;   
        m.read(_MAPS[i]);
        content c(&m);
        char in;
        bool isq = false;
        bool isf = false;
        while(!isq && !isf) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
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
    std::cout << "恭喜你,完成了所有关卡!"<<std::endl;
    return 0;
}