#include "box.h"
#include "content.h"
#include <iostream>

int box::type() {
    return BOX;
}

bool box::move(direct d) {
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "box:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->w;

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
        std::cout<<"★";
        break;
    case BLOCK+BOX:
        std::cout<<"□";
        break;
    default:
        std::cout<<"F";
        break;
    }
}

bool box::canpush() {
    return true;
}

bool box::cancover() {
    return false;
}

int wall::type() {
    return WALL;
}

void wall::display(int t) {
    std::cout<<"■";
}
bool wall::canpush() {
    return false;
}
bool wall::cancover() {
    return false;
}

int intend::type() {
    return INTEND;
}

void intend::display(int t) {
   if(cover == nullptr) {
       std::cout<<"☆";
   }else {
       cover->display(t+cover->type());
   }
}
