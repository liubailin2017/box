#include"palette.h"
#include<iostream>
palette::palette(int w,int h,int box_w,int box_h):w(w),h(h),box_w(box_w),box_h(box_h),c(0){
    surface = SDL_CreateRGBSurface(0,box_w*w,box_h*h,32,rmask,gmask,bmask,0);
    data = new Uint8[w*h];
    if(surface == NULL) {
        std::cout<<"SDL_CreateRGBsuface create failure on palette.cpp"<<std::endl;
    }
}
palette::palette(int x,int y):palette(x,y,30,30){};
palette::palette():palette(30,30){

};

template <typename T>
void __swap_( T& s, T& d) {
    T t = s;
    s = d;
    d = t; 
}

palette& palette::operator=(palette &&plt) {
    __swap_(w,plt.w);
    __swap_(h,plt.h);
    __swap_(box_w,plt.box_w);
    __swap_(box_h,plt.box_h);
    __swap_(c,plt.c);
    __swap_(surface,plt.surface);
    __swap_(data,plt.data);
    return *this;
}

palette& palette::operator=(palette &plt) {
    w = plt.w;
    h=plt.h;
    box_w=plt.box_w;
    box_h = plt.box_h;
    c = plt.c;
    if(surface)
        SDL_FreeSurface(surface);
    surface = SDL_DuplicateSurface(plt.surface);
    if(data) 
        delete[] data;
    data = new Uint8[w*h];
    memcpy(data,plt.data,w*h);
    return *this;
}

palette::~palette(){
    if(surface) {
        SDL_FreeSurface(surface);
        surface = NULL;
    }

    if(data) {
        delete[] data;
        data = NULL;
    }
}

bool palette::isfinsh(){
    if(c > w*h-1){
        return true;
    }else {
        return false;
    }
}
#include<string.h>
void palette::reset() {
    if(c == 0)
        memset(data,0,w*h);
    else
        memset(data,0,c);
    c = 0;
}

void palette::setsize(int bw,int bh) {
    box_w = bw;
    box_h = bh;
    SDL_Surface*tmp = surface;
    surface = SDL_CreateRGBSurface(0,box_w*w,box_h*h,32,rmask,gmask,bmask,0);
    SDL_BlitScaled(tmp,NULL,surface,NULL);
    SDL_FreeSurface(tmp);
}

bool palette::paint_(SDL_Surface *s) {
    if(!isfinsh()) {
        if(s){
            SDL_Rect trg={c%w*box_w,c/w*box_h,box_w,box_h};
            SDL_Rect src = {0,0,s->w,s->h};
            SDL_BlitScaled(s,&src,surface,&trg);
        }
        return true;
    }
    return false;
}

bool palette::paint(SDL_Surface *s) {
    if(paint_(s)){
        c++;
        return true;
    }
    return false;
}

int datafilter(int s) {
    if(s == 8 ) s = 0;
    if(s == 1 ) s = 0;
    return s;
}

bool palette::paint_(SDL_Surface *s,int d){
    if(paint_(s)) {
       data[c] += datafilter(d); 
       return true;
    }else {
        return false;
    }
}

bool palette::paint(SDL_Surface *s,int d) {
    if(paint_(s,d)) {
        c++;
        return true;
    }else {
        return false;
    }
}

    
SDL_Surface* palette::getSuface() {
    return surface;
}

Uint8* palette::getData() {
    return data;
}

int palette::getW() {
    return w;
}

int palette::getH() {
    return h;
}
int palette::getBoxW() {
    return box_w;
}

int palette::getBoxH() {
    return box_h;
}
