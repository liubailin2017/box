
#include"SDLC_Button.h"
#include"../sdltool.h"
#include"../SDLC_Context.h"
#include<SDL2/SDL_ttf.h>


void SDLC_Button::updateSurface() {
    switch (status)
    {

    case STATUS_IN:
    case STATUS_UP:
    case STATUS_SELECt:
        SDLC_Component::setbgcolor(bgc);
        sdltool::line(surface,0,getHeight(),getWidth(),getHeight(),bgc_in,10);
        break;
    case STATUS_NOMAL:
    case STATUS_OUT:
        SDLC_Component::setbgcolor(bgc);
        break;
    case STATUS_DOWN:
        SDLC_Component::setbgcolor(bgc_down);
        break;
    default:
        break;
    }
    SDL_BlitSurface(surface_text,NULL,surface,NULL);
    context->notifyUpdate();
}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text):SDLC_Button(context,text,0xFFFFFFFF) {}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text,Uint32 bg):SDLC_Button(context,text,24,bg) {}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text,int size,Uint32 bg):SDLC_Label(context,size,text) {
    setbgcolor(bg);
    bgc = bg; 


        Uint32 tmp = bgc;
        int r = tmp &0xff;
        int g = (tmp >> 8) & 0xff; 
        int b = (tmp >> 16) & 0xff;
        int a = 0xff;

        r  =  r > 20? r/10*6  : 0;
        g  =  g > 20? g/10*6 : 0;
        b  =  b > 20? b/10*6: 0;
    
        tmp = a;
        tmp = tmp << 8;
        
        tmp += b;
        tmp = tmp << 8;
        
        tmp += g;
        tmp = tmp << 8;
        
        tmp += r;

        bgc_down = tmp;


    bgc_in = bgc_down;
}

// SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d):SDLC_Button(context,x,y,w,d,0xffff00ff) {}

// SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg):SDLC_Label(context,NULL),status(STATUS_NOMAL) {
//     bgc_down = 0xAA0000FF;
//     bgc_in = 0xAAFFFFFF;
//     setPostion(x,y);
//     setSize(w,d);
//     setbgcolor(bg);
//     bgc = bg;
    
// }

SDLC_Button::~SDLC_Button() {
 }


bool SDLC_Button::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {
    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        status = STATUS_DOWN;
        break;
    case SDL_MOUSEBUTTONUP:
        status = STATUS_UP; 
    default:
        break;
    }
    context->notifyUpdate();
    return SDLC_Component::defaultmouseButtonHandler(event,cmp);
}

void SDLC_Button::defaultOutHandler(SDLC_Component *cmp) {
    status = STATUS_OUT;
    context->notifyUpdate();
    SDLC_Component::defaultOutHandler(cmp);
}

void SDLC_Button::defaultInHandler(SDLC_Component *cmp) {
    status = STATUS_IN;
    context->notifyUpdate();
    SDLC_Component::defaultInHandler(cmp);
}

void SDLC_Button::setbgcolor(Uint32 bgc) {
    this->bgc = bgc;
    SDLC_Component::setbgcolor(bgc);
}

Uint32 SDLC_Button::getBgcolor() {
    return bgc;
}