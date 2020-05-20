#ifndef _SDLC_Button_h_Extends_
#define _SDLC_Button_h_Extends_
#include "../SDLC_Component.h"
#include<string>
class SDLC_Button : public SDLC_Component
{
private:
  SDL_Surface *btn_text; 
  std::string text;

  Uint32 bgc;
  Uint32 bgc_down;
  Uint32 bgc_in;
  Uint32 bgc_out;
public:
    virtual void updateSurface();
    SDLC_Button(SDLC_Context *context,char *text);
    SDLC_Button(SDLC_Context *context,char *text,Uint32 bg);
    SDLC_Button(SDLC_Context *context,int x,int y,int w,int d);
    SDLC_Button(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg);
    virtual bool defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp);
    virtual void defaultOutHandler(SDLC_Component *cmp);
    virtual void defaultInHandler(SDLC_Component *cmp);   
    void setText(std::string text);
};
#endif