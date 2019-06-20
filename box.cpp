#include "box.h"
#include "content.h"
#include <iostream>
box::box():block::block() {
    __type = BOX;
}

int box::type() {
    return __type;
}
bool box::move(direct d) {
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "box:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->_w();

     block *c = nullptr;
     block *t = nullptr;
    switch (d) {
        case UP:
            c = root - w;
            t = _rmcover();
            c->_rear()->_cover(t);
            break;
        case RIGHT:
            c = root + 1;
            t = _rmcover();
            c->_rear()->_cover(t);
            break;
        case DOWN:
            c = root + w;
            t = _rmcover();
            c->_rear()->_cover(t);
            break;
        case LEFT:
            c = root - 1;
            t = _rmcover();
            c->_rear()->_cover(t);
            break;
    }
}
void box::display(int t) {
    switch (t) {
    case  BLOCK+INTEND+BOX:
        std::cout<<B10;
        break;
    case BLOCK+BOX:
        std::cout<<B2;
        break;
    default:
        std::cout<<Er;
        break;
    }
}
bool box::canpush() {
    return true;
}
bool box::cancover() {
    return false;
}

wall::wall():block::block(){
    __type = WALL;
}
int wall::type() {
    return __type;
}
void wall::display(int t) {
    std::cout<<B4;
}
bool wall::canpush() {
    return false;
}
bool wall::cancover() {
    return false;
}
bool wall::move(direct d) {return false;}

intend::intend():block::block() {
    __type = INTEND;
}
int intend::type() {
    return __type;
}

void intend::display(int t) {
   if(cover == nullptr) {
       std::cout<<B8;
   }else {
       cover->display(t+cover->type());
   }
}
bool intend::move(direct d) {return false;}