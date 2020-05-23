
#include"SDLC_Label.h"
#include"../sdltool.h"
#include"../SDLC_Context.h"
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL.h>

void SDLC_Label::updateSurface() {
    SDLC_Component::updateSurface();
    SDL_BlitSurface(surface_text,NULL,surface,NULL);
}

SDLC_Label::SDLC_Label(SDLC_Context *context,char *text):SDLC_Label(context,text,12,0xFFFFFFFF) {}

SDLC_Label::SDLC_Label(SDLC_Context *context,int fsize,char *text):SDLC_Label(context,text,fsize,0xFFFFFFFF) {}

SDLC_Label::SDLC_Label(SDLC_Context *context,char *text,Uint32 color):SDLC_Label(context,text,12,color) { }

SDLC_Label::SDLC_Label(SDLC_Context *context,char *text,int fsize,Uint32 text_color):SDLC_Component(context),text_color(text_color),surface_text(NULL),ttf(NULL){
    setbgcolor(0);
    ttf = TTF_OpenFont("def.ttf",fsize);  
    setText(text);
}

SDLC_Label::~SDLC_Label() {
    if(ttf) TTF_CloseFont(ttf);
    ttf = NULL;
    if(surface_text) SDL_free(surface_text);
}

void SDLC_Label::setText(std::string text) {
    SDL_Color color = {text_color&0xff,text_color>>8 & 0xff ,text_color >> 16 & 0xff};
    this->text = text;

    if(surface_text) SDL_free(surface_text);
    surface_text = TTF_RenderUTF8_Solid(ttf,text.c_str(),color);
    setSize(surface_text->w,surface_text->h);
}

void SDLC_Label::setFSize(int size)  {
    SDL_Color color = {text_color&0xff,text_color>>8 & 0xff ,text_color >> 16 & 0xff};

    if(ttf) TTF_CloseFont(ttf);
    ttf = TTF_OpenFont("def.ttf",size);
    
    if(surface_text) SDL_free(surface_text);
    surface_text = TTF_RenderUTF8_Solid(ttf,text.c_str(),color);
    setSize(surface_text->w,surface_text->h);   
}
 
