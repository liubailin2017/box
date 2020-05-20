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
#include"snakehand.h"
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
    snake_init();
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
            
        }

        int t = SDL_GetTicks();
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
//    context.addComponent(&topbar);
    bmapload();

}
#include"snakehand.h"
void GameGloabalResouce::loadMainHandle() {
    context.setListener(draw_main);
    context.setListener(main_hand);
    context.setInterval(1,mainstrick);
    // snake_init();
    // context.setListener(snake_draw_main);
    // context.setListener(snake_main_hand);
    // context.setInterval(10,snake_strick);
}

void GameGloabalResouce::changeHandle(int id) {
    switch (id)
    {
    case 1:
        context.setListener(draw_main);
        context.setListener(main_hand);
        context.setInterval(1,mainstrick);
        break;
    case 2:
        context.setListener(snake_draw_main);
        context.setListener(snake_main_hand);
        context.setInterval(10,snake_strick);
    break;
    default:
        break;
    }
}

#include"src/_maps.h"
#include<string.h>

void fromDef(int *len/* output */, int* **bmap /* output */) {
    *bmap = new int*[_LEN];
    for(int i = 0; i< _LEN; i++) {
        int w = _MAPS_def[i][0];
        int h = _MAPS_def[i][1];
        (*bmap)[i] = new int[w*h+2];
        memcpy((*bmap)[i],_MAPS_def[i],sizeof(int)*(w*h+2));
    }
    *len = _LEN;
}
#include<stdio.h>
void fromFile(int* len/* output */, int* **bmap /* output */) {
    FILE *fmap = fopen("map.txt","r");
    if(!fmap) {
       fromDef( len, bmap);
       return ;
    }
    fscanf(fmap,"%d,",len);
    *bmap = new int*[*len];
    for(int i = 0; i< *len; i++) {
        int w;
        fscanf(fmap,"%d,",&w);
        int h;
        fscanf(fmap,"%d,",&h);
        (*bmap)[i] = new int[w*h+2];
        (*bmap)[i][0] = w;
        (*bmap)[i][1] = h;
        for(int j = 0 ;j < w*h; j++) {
            int t;
            if(j%w == 0) printf("\n"); 
            fscanf(fmap,"%d,",&t);
            (*bmap)[i][j+2] = t;
            printf("%d,",t);
         
        }
    }
    fclose(fmap);
}

void GameGloabalResouce::bmapload() {
    if(bmap.bmap) {
        for(int i = 0; i< bmap.cnt_map; i++) {
            delete[] bmap.bmap[i];
        }
        delete[] bmap.bmap;
        bmap.bmap = nullptr;
        bmap.cnt_map = 0;
    }
    //fromDef(&bmap.cnt_map,&bmap.bmap);
    fromFile(&bmap.cnt_map,&bmap.bmap);
    
}
