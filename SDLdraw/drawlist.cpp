#include"drawlist.h"
#include"palette.h"

#include"../src/person.h"

#include"../src/block.h"

#include<iostream>
#include<SDL2/SDL_image.h>

static SDL_Surface* sufaceB0;
static SDL_Surface* sufaceB1;// "♀"
static SDL_Surface* sufaceB2;// "□"
static SDL_Surface* sufaceB4;// "■"
static SDL_Surface* sufaceB8;// "☆"
static SDL_Surface* sufaceB10;// "★"
static SDL_Surface* sufaceB9;// "♂"

static SDL_Surface* surface_b1[10]={0};

void drawlist_init_img() {
    if(!(sufaceB0 = IMG_Load("img/space.png")))
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB1 =  IMG_Load("img/person.png")))
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB2 =  IMG_Load("img/box.png") ))
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB4 =  IMG_Load("img/wall.png")))
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB8 =  IMG_Load("img/intend.png"))) 
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB10 = IMG_Load("img/box_intend.png")))
        std::cout<<SDL_GetError()<<std::endl;
    if(!(sufaceB9 =  IMG_Load("img/person_intend.png")))
        std::cout<<SDL_GetError()<<std::endl;

    for(int i = 0; i< 10; i++) {
        
        std::string filename("img/Character");
        filename+=((char)('0'+i));
        filename+=".png";
        surface_b1[i] = IMG_Load(filename.c_str());
        if(!surface_b1[i]) std::cout<<SDL_GetError()<<std::endl;
    }
}

void drawPerson(palette *p,person *prsn) {

    switch(prsn->_status()) {
        case FU0:
            p->paint(surface_b1[7]);
            break;
        case FU1:
            p->paint(surface_b1[8]);
            break;
        case FU2:
            p->paint(surface_b1[9]);
            break;
        case FD0:
            p->paint(surface_b1[4]);
            break;
        case FD1:
            p->paint(surface_b1[5]);
            break;
        case FD2:
            p->paint(surface_b1[6]);
            break;
        case FL0:
            p->paint(surface_b1[0]);
            break;
        case FL1:
            p->paint(surface_b1[1]);
            break;
        case FR0:
            p->paint(surface_b1[2]);            
            break;
        case FR1:
            p->paint(surface_b1[3]);            
            break;

    }
}

void drawobj(palette *p,block* obj){
    switch (obj->type())
    {
        case BLOCK:
            if(obj->_cover())
                p->paint_(sufaceB0);
            else
                p->paint(sufaceB0);
            break;
        case PERSON:
            drawPerson(p,(person*)obj);
            break;
        case BOX:
            if(obj->_lay()->type()==INTEND) {
                p->paint(sufaceB10);
            }else {
                p->paint(sufaceB2);
            }
            break;
        case WALL:
                p->paint(sufaceB4);
            break;
        case INTEND:
            if(obj->_cover())
                p->paint_(sufaceB8);
            else
                p->paint(sufaceB8);
            break;
        default:
            break;
    }
}

#include"../GlobalData.h"

extern GameGloabalResouce GloabalData;

void SDLdraw_update() {
        SDL_Surface* win_surface  = SDL_GetWindowSurface(GloabalData.global_w);
        SDL_BlitSurface(GloabalData.global_palette.getSuface(),NULL,win_surface,NULL);
//        SDL_UpdateWindowSurface(GloabalData.global_w);
}
