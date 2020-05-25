
#include "edithand.h"
#include"GlobalData.h"
#include"SDLC/Extends/SDLC_Label.h"
static SDLC_Label *msg = NULL;

void edit_hand_init() {
    msg = new SDLC_Label(&GloabalData.context,"地图编辑功能作者还未完成，请用记事本手动编辑map.txt 文件来编辑地图",24,0xff666666);  
    GloabalData.context.addComponent(msg);
    msg->setPostion((GloabalData.context.getWidth()-msg->getWidth())/2,(GloabalData.context.getHeight()-msg->getHeight())/2);
}

void edit_hand_exit() {
    if(msg) GloabalData.context.removeById(msg->getId());
    delete msg;
    msg == NULL;
}

void edit_strick(SDLC_Component *cmp) {
    GloabalData.context.notifyUpdate();
}

#include<cstring>
void edit_draw_main(SDL_Surface *surface) {
    if(SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface);
    }
    for(int i = 0; i< surface->w*surface->h; i++) {
        Uint32 tmp = *((Uint32*)(surface->pixels)+i);
        int r = tmp &0xff;
        int g = (tmp >> 8) & 0xff; 
        int b = (tmp >> 16) & 0xff;
        int a = 0xff;

        r  =  r > 20? r/10*9  : 0;
        g  =  g > 20? g/10*9 : 0;
        b  =  b > 20? b/10*9: 0;
    
        tmp = a;
        tmp = tmp << 8;
        
        tmp += b;
        tmp = tmp << 8;
        
        tmp += g;
        tmp = tmp << 8;
        
        tmp += r;

        *((Uint32*)(surface->pixels)+i) = tmp;
    }
    if(SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }
}

bool edit_main_hand(const SDL_Event& event,SDLC_Context *context) {
    switch (event.type)
    {
        case SDL_QUIT: 
            GloabalData.isq =true;
            break;
        default:
            break;
    }
    return true;
}