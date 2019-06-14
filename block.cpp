#include"block.h"
#include<iostream>
block::block(){

}

block::~block(){
    block *p,*t;
    p = cover;
    
    while(p != nullptr) {
        t = cover->cover;
        if(t->type() != PERSON)
            delete p;
        p = t;
    }
}

void block::display(int t) {
    if(cover == nullptr) {
        std::cout<<"X";
    }else{
        cover->display(type());
    }
}

bool block::move(direct d) {

}

int block::type() {
    return BLOCK;
}

bool block::cancover() {
    return true;
}

bool block::canpush() {
    return false;
}
