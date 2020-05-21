#include "Image.h"
#include "SDL2/SDL_image.h"

#include"iostream"

void SDLC_Image::updateSurface() { 
    SDLC_Component::updateSurface();

    if(img) {
        SDL_BlitScaled(img,NULL,surface,NULL);
    }
}

void SDLC_Image::load(char name[]) {
    if(img) SDL_free(img);
    img = IMG_Load(name);
    if(!img) {
       std::cout << IMG_GetError() << std::endl;
       return;
    }
    SDL_SetSurfaceBlendMode(img,SDL_BLENDMODE_BLEND);
    this->setSize(img->w,img->h);
}


SDLC_Image::SDLC_Image(SDLC_Context *context):SDLC_Image(context,0,0) { }
SDLC_Image::SDLC_Image(SDLC_Context *context,int w,int d):SDLC_Image(context,0,0,w,d){}
SDLC_Image::SDLC_Image(SDLC_Context *context,int x,int y,int w,int d):SDLC_Image(context,x,y,w,d,0x00000000){}
SDLC_Image::SDLC_Image(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg):SDLC_Component(context,x,y,w,d,bg),img(NULL){};

SDLC_Image::~SDLC_Image() {
    if(img) SDL_free(img);
    img = NULL;
};
