#include<iostream>
#include<string>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>


#include "SDLC/SDLC_log.h"
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"
#include "SDLC/Extends/Image.h"
#include "SDLC/Extends/SDLC_Button.h"
#include"box/base.h"
#include"box/block.h"
#include"box/person.h"
#include"box/box.h"
#include"box/content.h"


#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

#include"GlobalData.h"

GameGloabalResouce GloabalData; /* 全局变量初始化 */

#include"Box/_maps.h"/* flag */
void main_init() { 
    FILE *f = fopen("data.sav","rb+");
    if(f){
        fread(flag,sizeof(flag),1,f);
        fclose(f);
    }
}

void main_save() {
    FILE* f = fopen("data.sav","wb+");
    if(f){
        fwrite(flag,sizeof(flag),1,f);
        fclose(f);
    }
}
int main(int argc,char* agrv[]) {

    SDL_Event event;

    drawlist_init_img();

    main_init();
    
    while (!GloabalData.isq)
    {

        while(SDL_PollEvent(&event)) {        
            SDL_LockMutex(GloabalData.mutex);
            GloabalData.context.dispatch(event); 
            SDL_UnlockMutex(GloabalData.mutex);
        }
        SDL_Delay(10);
    }

    SDL_DestroyWindow(GloabalData.global_w);
    main_save();
    return 0;
}

int strick_thread(void *ptr)
{
    int ticket = SDL_GetTicks();
    SDLC_Context *context = &GloabalData.context;
    while (!GloabalData.isq)
    {
        if(SDL_GetTicks() - ticket > 30) {

                /* 只要一加锁这个函数就会阻塞  未知原因
                SDL_SetWindowTitle(GloabalData.global_w,"hello,world"); 
                */
                ticket = SDL_GetTicks();
                SDL_LockMutex(GloabalData.mutex);  
                context->updateWindow(); 
                context->strick();          
                SDL_UnlockMutex(GloabalData.mutex);

        }
     
        SDL_Delay(10);
    }
    
    return 0;
}