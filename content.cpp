#include"content.h"
#include<iostream>
content::content(map *m){
    this->m = m;
    for(int i = 0; i< (m->w)*(m->h); i++) {
        if(m->blocks()[i].cover != nullptr && m->blocks()[i].cover->type() == PERSON){
            p = (person *)((m->blocks()+i)->cover); 
        }
    }
}

content::~content(){
}

void content::display() {
    for(int i = 0; i < m->w * m->h; i++) {
        if(i % m->w == 0) std::cout<<std::endl;
        m->blocks()[i].display(0);
    }
    std::cout<<std::endl; 
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
    int map1[182/*13*14*/] = {//创建一个地图
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,// 0: 空地
        4,9,4,10,4,4,4,4,4,4,4,4,4,4,// 1: 目的地  ☆
        4,4,4,4,4,4,8,4,4,4,4,4,4,4,// 2: 墙壁    ■
        4,4,4,4,4,4,2,4,4,4,4,4,4,4,// 4: 箱子  □
        4,4,4,4,4,4,0,4,4,4,4,4,4,4,// 8: 玩家    ♀
        4,4,4,8,2,0,1,0,2,8,4,4,4,4,// 16:箱子已在目的地  ★
        4,4,4,4,4,4,0,4,4,4,4,4,4,4,// 32:人在目的地上  ♂
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