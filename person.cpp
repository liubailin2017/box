#include"person.h"
#include<iostream>

person::person() {
    
}

void person::display(int t){
    t -= BLOCK;
    switch(t) {
        case PERSON :
            std::cout<<"♀";
            break;
        case INTEND + PERSON:
            std::cout<<"♂";
            break;
    }
}

bool person::move(direct d){ 
     _inter_push_dir = d;
    if(lay == nullptr) return false;
}

void person::push() {

}

int person::type() {
    return PERSON;
}
