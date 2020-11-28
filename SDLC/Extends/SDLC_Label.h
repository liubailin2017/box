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

    virtual void setText(std::string text);

    void setFSize(int size);
    void setColor(Uint32 color);
    virtual ~SDLC_Label();
};

/* Unicode */
class SDLC_WLabel : public SDLC_Component
{
  
protected:
  SDL_Surface *surface_text; 
  TTF_Font* ttf;
  std::wstring text;
  Uint32 text_color;
public:
    virtual void updateSurface();
    SDLC_WLabel(SDLC_Context *context,wchar_t *text);
    SDLC_WLabel(SDLC_Context *context,int fsize,wchar_t *text); 
    SDLC_WLabel(SDLC_Context *context,wchar_t *text,Uint32 color); 
    SDLC_WLabel(SDLC_Context *context,wchar_t *text,int fsize,Uint32 color); 

    virtual void setText(std::wstring text);

    void setFSize(int size);
    void setColor(Uint32 color);
    virtual ~SDLC_WLabel();
};

#endif