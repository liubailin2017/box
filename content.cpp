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


void content::display() {
      m->blocks()[48]._rear()->move(UP);
      
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
    int map1[182/*13*14*/] = {
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,9,4,10,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,8,4,4,4,4,4,4,4, 
        4,4,4,4,4,4,2,4,4,4,4,4,4,4, 
        4,4,4,4,4,4,0,4,4,4,4,4,4,4, 
        4,4,4,8,2,0,1,0,2,8,4,4,4,4,
        4,4,4,4,4,4,0,4,4,4,4,4,4,4,
        4,4,4,4,4,4,2,4,4,4,4,4,4,4,
        4,4,4,4,4,4,8,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    };
    map m;   
    m.read(map1);
    content c(&m);
    c.display();
}