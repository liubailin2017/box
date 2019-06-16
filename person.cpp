#include"person.h"
#include"content.h"
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
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->w;
     _inter_push_dir = d;

     block *c = nullptr;
     block *t = nullptr;
    switch (d) {
        case UP:
            if(push() || (root - w)->_rear()->cancover()) {
                c = root - w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case RIGHT:
            if(push() || (root+1)->_rear()->cancover()) {
                c = root + 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case DOWN:
            if(push()|| (root + w)->_rear()->cancover()) {
                c = root + w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case LEFT:
            if(push()|| (root - 1)->_rear()->cancover()){
                c = root - 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
    }
    

}

bool person::push() {
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->w;

    bool ispush =false;
    switch (_inter_push_dir)
    {
    case LEFT:
        if( ((root-1)->_cover() == nullptr) || 
        (root -1)->_rear()->canpush() && (root-2)->_rear()->cancover()) {
            (root-1)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    case RIGHT:
        if(((root+1)->_cover() == nullptr) || 
        (root+1)->_rear()->canpush() && (root+2)->_rear()->cancover()) {
             (root+1)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    case UP:
        if(((root-w)->_cover() == nullptr) || 
        (root-w)->_rear()->canpush() && (root-2*w)->_rear()->cancover()) {
             (root-w)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    break;
    case DOWN:
        if(((root+w)->_cover() == nullptr) || 
        (root+w)->_rear()->canpush() && (root+2*w)->_rear()->cancover()) {
             (root+w)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    }
    return ispush;
}

int person::type() {
    return PERSON;
}
