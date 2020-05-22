#ifndef _SDLC_Button_h_Extends_
#define _SDLC_Button_h_Extends_
#include"SDLC_Label.h"
#include<string>
#include<SDL2/SDL_ttf.h>

/* 按下状态 */
#define STATUS_DOWN 1
/* 鼠标进入状态 */ 
#define STATUS_IN 2
/* 鼠标移出状态 */
#define STATUS_OUT 3
/* 普通状态 */
#define STATUS_NOMAL 0
/* 选中状态 */
#define STATUS_SELECt 4 
#define STATUS_UP 5

class SDLC_Button : public SDLC_Label
{
private:

  Uint32 bgc_down;
  Uint32 bgc_in;
  Uint32 bgc;
  int status;
public:
    virtual void updateSurface();
    SDLC_Button(SDLC_Context *context,char *text);
    SDLC_Button(SDLC_Context *context,char *text,Uint32 bg);
    SDLC_Button(SDLC_Context *context,char *text,int size, Uint32 bg);
    SDLC_Button(SDLC_Context *context,int x,int y,int w,int d);
    SDLC_Button(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg);
    
    virtual bool defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp);
    virtual void defaultOutHandler(SDLC_Component *cmp);
    virtual void defaultInHandler(SDLC_Component *cmp);

    /* 原始的 bgcolor 是临时的背景色 */
    virtual void setbgcolor(Uint32 bgc);
    virtual Uint32 getBgcolor();
    
    virtual ~SDLC_Button();
};
#endif