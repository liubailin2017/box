#ifndef _SDLC_Label_h_Extends_
#define _SDLC_Label_h_Extends_
#include "../SDLC_Component.h"
#include<string>
#include<SDL2/SDL_ttf.h>

class SDLC_Label : public SDLC_Component
{
  
protected:
  SDL_Surface *surface_text; 
  TTF_Font* ttf;
  std::string text;
  Uint32 text_color;

public:
    virtual void updateSurface();
    SDLC_Label(SDLC_Context *context,char *text);
    SDLC_Label(SDLC_Context *context,int fsize,char *text); 
    SDLC_Label(SDLC_Context *context,char *text,Uint32 color); 
    SDLC_Label(SDLC_Context *context,char *text,int fsize,Uint32 color); 

    void setText(std::string text);
    void setFSize(int size);
    void setColor(Uint32 color);

    virtual ~SDLC_Label();
};
#endif