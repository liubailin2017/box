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

#include"src/_maps.h"

void loadleve(int leve,content &c);
void main_init();
void draw_main(SDL_Surface *surface) {

        SDLdraw_update();
}
int size_ = 50;

bool hand_evet(const SDL_Event& event, SDLC_Component *cmp) {
    switch (event.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            cmp->raise();
            break;
        default:
            break;
    }
    return true;
}

bool main_hand(const SDL_Event& event,SDLC_Context *context) {
 switch (event.type) {            
    case SDL_WINDOWEVENT:
    switch (event.window.event)
    {
        case SDL_WINDOWEVENT_RESIZED:
                    _WIDTH = event.window.data1;
                    _HEIGHT = event.window.data2;
                    GloabalData.global_palette.setsize(_WIDTH/ GloabalData.m._w(),_HEIGHT/ GloabalData.m._h());
                    std::cout<<"resize"<<std::endl;
                    break;
        default:
            break;
    }
    break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                GloabalData.c.actinput(UP);
                break;
            case SDLK_LEFT:
                GloabalData.c.actinput(LEFT);
                break;
            case SDLK_RIGHT:
                GloabalData.c.actinput(RIGHT);
                break;
            case SDLK_DOWN:
                GloabalData.c.actinput(DOWN);
                break;
            case SDLK_SPACE:
                GloabalData.c.back();
                break;
            case SDLK_PAGEUP:
                if(GloabalData.leve < GloabalData.mleve-1) { 
                    ++GloabalData.leve;
                    loadleve(GloabalData.leve,GloabalData.c);
                }
                break;
            case SDLK_PAGEDOWN:
                if(GloabalData.leve>0) {
                    GloabalData.leve--;
                    loadleve(GloabalData.leve,GloabalData.c);
                }
                break;
                default:
                
                break;
            }

            if(GloabalData.c.isfinsh()){
                flag[GloabalData.leve] = '*';
                    GloabalData.leve++;
                    GloabalData.leve %= GloabalData.mleve;
                    loadleve(GloabalData.leve,GloabalData.c);
            }
            GloabalData.global_palette.reset();
            GloabalData.c.display();
            GloabalData.context.notifyUpdate();
            break;
            case SDL_QUIT: 
                GloabalData.isq =true;
                break;
            default:
                break;
        }
    return true;
}


int main(int argc,char* agrv[]) {
    int ticket ;

    main_init();

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
    FILE* f = fopen("data.sav","wb+");
    if(f){
        fwrite(flag,sizeof(flag),1,f);
        fclose(f);
    }

    return 0;
}


void loadleve(int leve,content &c) {
    std::string title;
    c.getmap()->read(_MAPS_def[leve]);
    palette p(c.getmap()->_w(),c.getmap()->_h(),_WIDTH/c.getmap()->_w(),_HEIGHT/c.getmap()->_h());
    GloabalData.global_palette = p;
    c.init();
    title = "level:"+std::to_string(leve+1)+"    "+flag[leve];
    SDL_SetWindowTitle(GloabalData.global_w,title.c_str());
}

void main_init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    drawlist_init_img();
    GloabalData.global_w= SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    GloabalData.context.update(GloabalData.global_w);
    FILE *f = fopen("data.sav","rb+");
    if(f){
        fread(flag,sizeof(flag),1,f);
        fclose(f);
    }
}



GameGloabalResouce::GameGloabalResouce() :m(map()),c(content(&m)),leve(0),context(SDLC_Context(NULL)),topbar(SDLC_Component(&context,0,0,_WIDTH,_HEIGHT/10,0x7712ff55)) {
    context.setListener(draw_main);
    context.setListener(main_hand);
    topbar.setMovable(true);
    topbar.setListener(hand_evet);
    context.addComponent(&topbar);
    mleve = sizeof(_MAPS_def)/(_SIZE*sizeof(int));
}