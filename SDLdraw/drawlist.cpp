#include"drawlist.h"
#include"palette.h"
#include<iostream>
#include<SDL2/SDL_image.h>
SDL_Surface* sufaceB0;
SDL_Surface* sufaceB1;// "♀"
SDL_Surface* sufaceB2;// "□"
SDL_Surface* sufaceB4;// "■"
SDL_Surface* sufaceB8;// "☆"
SDL_Surface* sufaceB10;// "★"
SDL_Surface* sufaceB9;// "♂"
void drawlist_init_img() {
    if(sufaceB0 = IMG_Load("img/space.png"))
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB1 =  IMG_Load("img/person.png"))
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB2 =  IMG_Load("img/box.png") )
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB4 =  IMG_Load("img/wall.png"))
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB8 =  IMG_Load("img/intend.png")) 
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB10 = IMG_Load("img/box_intend.png"))
        std::cout<<SDL_GetError()<<std::endl;
    if(sufaceB9 =  IMG_Load("img/person_intend.png"))
        std::cout<<SDL_GetError()<<std::endl;
}

void drawperson(palette *p) {
        p->paint(sufaceB1);
}

void drawperson_intend(palette *p) {
         p->paint(sufaceB9);
}

void drawbox(palette *p) {
     p->paint(sufaceB2);
}

void drawbox_intend(palette *p){
         p->paint(sufaceB10);
}
void drawintend(palette *p){
     p->paint(sufaceB8);
}

void drawwall(palette *p) {
         p->paint(sufaceB4);
}

void drawspace(palette *p){
         p->paint(NULL);
}