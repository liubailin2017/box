#include"palette.h"
#include<iostream>
palette::palette(int x,int y,int box_w,int box_h):x(x),y(y),box_w(box_w),box_h(box_h),c(0){
    surface = SDL_CreateRGBSurface(0,box_w*x,box_h*y,32,rmask,gmask,bmask,0);
    if(surface == NULL) {
        std::cout<<"SDL_CreateRGBsuface create failure on palette.cpp"<<std::endl;
    }
}
palette::palette(int x,int y):palette(x,y,30,30){};
palette::palette():palette(30,30){};

palette& palette::operator=(const palette &plt){
    x = plt.x;
    y=plt.y;
    box_w=plt.box_w;
    box_h = plt.box_h;
    c = plt.c;
    SDL_FreeSurface(surface);
    surface = SDL_CreateRGBSurface(0,box_w*x,box_h*y,32,rmask,gmask,bmask,0);
    return *this;
}

palette::~palette(){
    if(surface)
        SDL_FreeSurface(surface);
    surface = NULL;
}

bool palette::isfinsh(){
    if(c > x*y-1){
        return true;
    }else {
        return false;
    }
}
void palette::reset() {
    c = 0;
}
void palette::setsize(int w,int h) {
    box_w = w;
    box_h = h;
    SDL_Surface*tmp = surface;
    surface = SDL_CreateRGBSurface(0,box_w*x,box_h*y,32,rmask,gmask,bmask,0);
    SDL_BlitScaled(tmp,NULL,surface,NULL);
    SDL_FreeSurface(tmp);
}
bool palette::paint_(SDL_Surface *s) {
    if(!isfinsh()) {
        if(s){
            SDL_Rect trg={c%x*box_w,c/x*box_h,box_w,box_h};
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
SDL_Surface* palette::getSuface() {
    return surface;
}