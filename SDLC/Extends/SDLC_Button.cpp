
#include"SDLC_Button.h"
#include"../sdltool.h"
#include"../SDLC_Context.h"
#include<SDL2/SDL_ttf.h>


void SDLC_Button::updateSurface() {
    switch (status)
    {
    case STATUS_NOMAL:
        setbgcolor(bgc);
        break;
    case STATUS_IN:
    case STATUS_UP:
    case STATUS_SELECt:
        setbgcolor(bgc);
        sdltool::line(surface,0,height,width,height,bgc_down,10);
        break;
    case STATUS_OUT:
        setbgcolor(bgc);
        break;
    case STATUS_DOWN:
        setbgcolor(bgc_down);
        break;
    default:
        break;
    }
    SDL_BlitSurface(surface_text,NULL,surface,NULL);
}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text):SDLC_Button(context,text,0) {

}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text,Uint32 bg):SDLC_Button(context,text,24,bg) {
  
}

SDLC_Button::SDLC_Button(SDLC_Context *context,char *text,int size,Uint32 bg):SDLC_Button(context,0,0,0,0,bg) {
    this->text = text;
    ttf = TTF_OpenFont("def.ttf",size);
    SDL_Color color = {255,255,0};
    surface_text = TTF_RenderUTF8_Solid(ttf,text,color);
    setSize(surface_text->w,surface_text->h);
    setbgcolor(bg);
}

SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d):SDLC_Button(context,x,y,w,d,0xffff00ff) {

}
SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg):SDLC_Component(context,x,y,w,d,bg),surface_text(NULL),ttf(NULL),status(STATUS_NOMAL) {
    bgc_down = 0xffffffff;
    bgc = bg;
    bgc_in = 0xff00ffff;
}

SDLC_Button::~SDLC_Button() {
    if(ttf) TTF_CloseFont(ttf);
    ttf = NULL;
    if(surface_text) SDL_free(surface_text);
}

void SDLC_Button::setText(std::string text) {
    SDL_Color color = {255,255,0};
    this->text = text;
    if(surface_text) SDL_free(surface_text);
    surface_text = TTF_RenderUTF8_Solid(ttf,text.c_str(),color);
    setSize(surface_text->w,surface_text->h);
}

void SDLC_Button::setFSize(int size)  {
    if(ttf) TTF_CloseFont(ttf);
    ttf = TTF_OpenFont("def.ttf",size);
    SDL_Color color = {255,255,0};
    surface_text = TTF_RenderUTF8_Solid(ttf,text.c_str(),color);    
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
