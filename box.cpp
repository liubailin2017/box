#include "box.h"
#include "content.h"
#include <iostream>

int box::type(){
    return BOX;
}

bool box::move(direct d){
    int w = getContent()->getmap()->w;
    
    switch (d)
    {
    case UP:
         
        break;
    
    default:
        break;
    }
}

void box::display(int t) {
    switch (t)
    {
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

int wall::type(){
    return WALL;
}

void wall::display(int t) {
    std::cout<<"■";
}

int intend::type(){
    return INTEND;
}

void intend::display(int t) {
   if(cover == nullptr) {
       std::cout<<"☆";
   }else {
       cover->display(t+cover->type());
   }
}
