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
#include "SDLC/Extends/SDLC_Button.h"
#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"


#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

#include"GlobalData.h"

GameGloabalResouce GloabalData; /* 全局变量初始化 */


#include"mainhand.h"
#include"snakehand.h"
int main(int argc,char* agrv[]) {
    int ticket ;


    
    drawlist_init_img();

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
#include"menu_event.h"
GameGloabalResouce::GameGloabalResouce():global_w(SDL_CreateWindow("hello,world",
                                        SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                        _WIDTH,_HEIGHT,
                                        SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN)),
                                    isInit(SDLC_Init()),
                                    context(SDLC_Context(global_w)),
                                    topbar(Toolbar(&context)),
                                    m(map()),
                                    c(content(&m)),
                                    leve(0),
                                    isq(false),img_help(Helpbar(&context))
{
  
    context.addComponent(&topbar);
    SDLC_Component *sc = new SDLC_Button(&context,"重新开始",0xff223355);
    sc->setListener(&event_replay_level);
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"上一关",0xff223355);
    sc->setListener(&event_pre_level); 
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"下一关",0xff223355);  
    sc->setListener(&event_next_level);
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"地图编辑器",0x22333333);
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"帮助",0xff009922);  
    sc->setListener(&event_help);
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"切换游戏",0xff993322);  
    sc->setListener(&event_change_game);
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context," ",0xff000000);  
    topbar.addComponent(sc);
    sc = new SDLC_Button(&context,"后退一步",0xff33ff22);  
    sc->setListener(&event_back);
    topbar.addComponent(sc);
    bmapload();
    context.addComponent(&img_help); 
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
