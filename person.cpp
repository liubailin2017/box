#include"person.h"
#include"content.h"
#include<iostream>

person::person():block::block() {
    __type = PERSON;
}
person::~person() {
        if(lay != nullptr) lay->_cover() = nullptr;
        if(cover != nullptr){
            delete cover;
    }
}

void person::display(int t){
    t -= BLOCK;
    switch(t) {
        case PERSON :
            std::cout<<B1;
            break;
        case INTEND + PERSON:
            std::cout<<B9;
            break;
    }
}
bool person::back_move(direct d) {
     int ism =false;
    int isp = false;
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->_w();
     _inter_push_dir = d;

     block *c = nullptr;
     block *t = nullptr;
    switch (d) {
        case UP:
            if((root - w)->_rear()->cancover()) {
                ism  = true;
                c = root - w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case RIGHT:
            if((root+1)->_rear()->cancover()) {
                ism  = true;
                c = root + 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case DOWN:
            if( (root + w)->_rear()->cancover()) {
                ism  = true;
                c = root + w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case LEFT:
            if( (root - 1)->_rear()->cancover()){
                ism  = true;
                c = root - 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
    }
    return ism;
}

bool person::move(direct d){
    int ism =false;
    int isp = false;
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->_w();
     _inter_push_dir = d;

     block *c = nullptr;
     block *t = nullptr;
    switch (d) {
        case UP:
            if( (isp = push()) || (root - w)->_rear()->cancover()) {
                ism  = true;
                c = root - w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case RIGHT:
            if( (isp=push()) || (root+1)->_rear()->cancover()) {
                ism  = true;
                c = root + 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case DOWN:
            if( (isp=push())|| (root + w)->_rear()->cancover()) {
                ism  = true;
                c = root + w;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
        case LEFT:
            if( (isp=push())|| (root - 1)->_rear()->cancover()){
                ism  = true;
                c = root - 1;
                t = _rmcover();
                c->_rear()->_cover(t);
            }
            break;
    }
    int s = _inter_push_dir;
    if(isp)
        s |= _PUSH_BYTE;
    if(ism)
        root->getContent()->pushm(s);
    return ism;
}

bool person::push() {
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person::push:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->_w();

    bool ispush =false;
    switch (_inter_push_dir)
    {
    case LEFT:
        if((root -1)->_rear()->canpush() && (root-2)->_rear()->cancover()) {
            (root-1)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    case RIGHT:
        if((root+1)->_rear()->canpush() && (root+2)->_rear()->cancover()) {
             (root+1)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    case UP:
        if((root-w)->_rear()->canpush() && (root-2*w)->_rear()->cancover()) {
             (root-w)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    break;
    case DOWN:
        if((root+w)->_rear()->canpush() && (root+2*w)->_rear()->cancover()) {
             (root+w)->_rear()->move(_inter_push_dir);
            ispush = true;
        }
        break;
    }
    return ispush;
}

bool person::pull() {
    content * cnt = root ->getContent();
    
    if(cnt == nullptr) {
        std::cout<< "person::pull:null content"<<std::endl;
        return false;
    }

    int w = cnt->getmap()->_w();

    bool ispull = false;
//  block *t;
//  block *m;
//  block* b;
//  block *d1,*d2,*d3,*d4;
//  int si;
    switch (_inter_push_dir)
    {
    case LEFT:
            (root+2)->_rear()->move(_inter_push_dir);
            ispull = true;
        break;
    case RIGHT:
            (root-2)->_rear()->move(_inter_push_dir);
            ispull = true;
        break;
    case UP:
            (root+2*w)->_rear()->move(_inter_push_dir);
            ispull = true;
        break;
    break;
    case DOWN:
             (root-2*w)->_rear()->move(_inter_push_dir);
            ispull = true;
        break;
    }
    return ispull;
}

int person::type() {
    return __type;
}

