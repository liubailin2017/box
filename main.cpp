#include<iostream>
#include<string>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>

int _WIDTH =960;
int _HEIGHT =640;

#include "SDLC/SDLC_log.h"
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"
#include "SDLC/Extends/Image.h"

#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"


#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

#include"GlobalData.h"

GameGloabalResouce GloabalData;


#include"mainhand.h"

int main(int argc,char* agrv[]) {
    int ticket ;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    drawlist_init_img();
    GloabalData.global_w= SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    main_init();
    GloabalData.loadMainHandle();
    SDL_Event event;
    loadleve(GloabalData.leve, GloabalData.c);
    GloabalData.global_palette.reset();
    GloabalData.c.display();

    ticket = SDL_GetTicks();
    while (!GloabalData.isq)
    {
        while(SDL_PollEvent(&event)) {
            GloabalData.context.dispatch(event);
            if(event.type==SDL_KEYDOWN) break;
        }

        int t = SDL_GetTicks() ;
        if(SDL_GetTicks() - ticket > 30) {
                GloabalData.context.updateWindow();  
                ticket = SDL_GetTicks();
                GloabalData.context.strick();
        }
        if(SDL_GetTicks()-t < 10){
           SDL_Delay(10);
        }
    }
    
    SDL_DestroyWindow(GloabalData.global_w);
    main_save();
    return 0;
}


GameGloabalResouce::GameGloabalResouce() :m(map()),c(content(&m)),leve(0),context(SDLC_Context(NULL)),topbar(SDLC_Component(&context,0,0,_WIDTH,_HEIGHT/10,0x7712ff55)) {
    topbar.setMovable(true);
    topbar.setListener(hand_evet);
    context.addComponent(&topbar);
}

void GameGloabalResouce::loadMainHandle() {
    context.setListener(draw_main);
    context.setListener(main_hand);
    context.setInterval(5,mainstrick);
}
