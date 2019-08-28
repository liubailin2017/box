#include<iostream>
#include "mainhand.h"

MainHandResouce mainHandleRes;

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

#include"src/_maps.h"


extern int _WIDTH;
extern int _HEIGHT;
extern GameGloabalResouce GloabalData;

void draw_main(SDL_Surface *surface) {

        SDLdraw_update();
}

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
void print(tool::pos *s,char *map,int _W,int _H) {
    if(!s) printf("null\n");
    while(s) {
        printf("(%d,%d)->",s->x,s->y);
        s= s->pre;
    }
    printf("\n");
}
bool main_hand(const SDL_Event& event,SDLC_Context *context) {
    switch (event.type) {            
        case SDL_WINDOWEVENT:
        switch (event.window.event)
        {
            case SDL_WINDOWEVENT_RESIZED:
                        _WIDTH = event.window.data1;
                        _HEIGHT = event.window.data2;
                        GloabalData.topbar.setSize(_WIDTH,_HEIGHT/10);
                        GloabalData.topbar.setPostion(0,0);
                        GloabalData.global_palette.setsize(_WIDTH/ GloabalData.m._w(),_HEIGHT/ GloabalData.m._h());
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
            
            mainHandleRes.path = NULL;

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

        case SDL_MOUSEBUTTONDOWN:{
            if(event.button.button == 1) {
                GloabalData.global_palette.reset();
                GloabalData.c.display();
                // for(int i = 0; i< GloabalData.global_palette.getW()* GloabalData.global_palette.getH();i++){
                //     if(i% GloabalData.global_palette.getW() == 0){
                //         printf("|\n|");
                //     }
                //     printf("%2d", GloabalData.global_palette.getData()[i]);
                // }
                // printf("\n--------update-----------\n");

                int boxw = GloabalData.global_palette.getBoxW();
                int boxh = GloabalData.global_palette.getBoxH();
                int x,y;
                x = event.button.x/boxw;
                y = event.button.y/boxh;
                int w = GloabalData.global_palette.getW();
                int h = GloabalData.global_palette.getH();
                mainHandleRes._bfs.set((char*)GloabalData.global_palette.getData(),w,h);
                if(GloabalData.global_palette.getData()[w*y+x] == 2) GloabalData.global_palette.getData()[w*y+x] = 0;
                tool::pos s = GloabalData.c._persion()->getPostion();
                tool::pos t; t.x = x;t.y = y;
                mainHandleRes.qpos.clean();
                mainHandleRes.path = mainHandleRes._bfs.BFS(s,t,mainHandleRes.qpos);
                //print(mainHandleRes.path,(char*)GloabalData.global_palette.getData(),w,h);
            }else if(event.button.button == 3){
                GloabalData.c.back();
                GloabalData.global_palette.reset();
                GloabalData.c.display();
                GloabalData.context.notifyUpdate(); 
            }
        }
        break;
        case SDL_QUIT: 
            GloabalData.isq =true;
            break;
        default:
            break;
    }
    return true;
}

void mainstrick(SDLC_Component *cmp) {
    if(cmp) return;

    if(mainHandleRes.path && mainHandleRes.path->pre) {
        GloabalData.c.actinput((direct)mainHandleRes.path->pre->action(*(mainHandleRes.path)));
        mainHandleRes.path = mainHandleRes.path->pre;
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
    GloabalData.context.update(GloabalData.global_w);
    FILE *f = fopen("data.sav","rb+");
    if(f){
        fread(flag,sizeof(flag),1,f);
        fclose(f);
    }
    GloabalData.mleve = sizeof(_MAPS_def)/(_SIZE*sizeof(int));

}

void main_save() {
    FILE* f = fopen("data.sav","wb+");
    if(f){
        fwrite(flag,sizeof(flag),1,f);
        fclose(f);
    }
}

MainHandResouce::MainHandResouce(): path(NULL){
}
