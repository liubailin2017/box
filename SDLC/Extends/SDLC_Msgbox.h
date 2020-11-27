#ifndef _SDLC_Msgbox_h_Extends_
#define _SDLC_Msgbox_h_Extends_
#include"../SDLC_Com_Radius.h"
#include"../SDLC_Context.h"
#include"SDLC_Label.h"
#include"SDLC_Button.h"
class SDLC_Msgbox : public SDLC_Com_Radius
{
private:
    SDLC_Button* btn1;
    SDLC_Button* btn2;
    SDLC_Label* label;
public:
    SDLC_Msgbox(SDLC_Context *context); 

    //virtual int fliterEvent(const SDL_Event& event);
    // SDLC_Msgbox(SDLC_Context *context,char *msg,int btnc, char* text[],Handler cb,void *arg);
    virtual int fliterEvent(const SDL_Event& event); /* 捕获所有事件 */
    void show(char *msg,Handler cb);
    virtual ~SDLC_Msgbox();
};


#endif