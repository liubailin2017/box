#include"palette.h"
#include<iostream>
palette::palette(int x,int y,int box_w,int box_h):x(x),y(y),box_w(box_w),box_h(box_h),c(0){
    surface = SDL_CreateRGBSurface(0,box_w*x,box_h*y,32,rmask,gmask,bmask,amask);
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
    surface = SDL_CreateRGBSurface(0,box_w*x,box_h*y,32,rmask,gmask,bmask,amask);
}

palette::~palette(){
    if(surface)
        SDL_free(surface);
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
bool palette::paint(SDL_Surface *s) {
    if(!isfinsh()) {
        if(s){
            SDL_Rect trg={c%x*box_w,c/x*box_h,box_w,box_h};
            SDL_Rect src = {0,0,s->w,s->h};
            SDL_BlitScaled(s,&src,surface,&trg);
        }
        c++;
        return true;
    }
    std::cout<<"pain faiure on palette.cpp"<<std::endl;
    return false;
}
SDL_Surface* palette::getSuface() {
    return surface;
}