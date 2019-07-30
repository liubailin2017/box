#include"block.h"
#include<iostream>

#include"../SDLdraw/palette.h"
#include"../SDLdraw/drawlist.h"
extern palette global_palette;


block::block():__type(BLOCK),root(this),rear(this),lay(nullptr),cover(nullptr) {
}

block::~block() {
    if(cover != nullptr){
        if(cover->type() == PERSON) {
            cover->_lay() = NULL;
        }
        else{
             delete cover;
        }
    }
}

void block::setContent(content *c){
  _content = c;
}

content* block::getContent(){
    return _content;
}

block* & block::_root() {
    return root;
}
block* & block::_rear() {
    return rear;
}
block* & block::_lay() {
    return lay;
}
block* & block::_cover() {
    return cover;
}

void block::_cover(block* b) {
    b->lay = this;
    this->cover = b;
    b->root =this->root;
    root->rear = b;
}

block* block::_rmcover() {
    if(rear == root) {
        return nullptr;
    }else {
        block *t = this;
        this->lay->cover = nullptr;
        root->rear = this->lay;
        return t;
    }
}

void block::display(int t) {
  
    if(cover == nullptr) {
        drawobj(&global_palette,this);
        //    std::cout<<B0;
    }else{
        drawobj(&global_palette,this);
        cover->display(t + cover->type());
    }
}

bool block::move(direct d) {
    return false;
}

int block::type() {
    return __type;
}

bool block::cancover() {
    return true;
}

bool block::canpush() {
    return false;
}

