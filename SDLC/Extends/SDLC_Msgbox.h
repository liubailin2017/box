#ifndef _SDLC_Msgbox_h_Extends_
#define _SDLC_Msgbox_h_Extends_
#include "../SDLC_Component.h"
#include"../SDLC_Context.h"

typedef void (*Msgbox_cb)(int n,void *arg); /* 第几个按钮被选中 */

class SDLC_Msgbox
{
private:
    Msgbox_cb cb;
    void* arg;
public:
    SDLC_Msgbox(SDLC_Context *context,char *msg,Msgbox_cb cb,void *arg); 
    SDLC_Msgbox(SDLC_Context *context,char *msg,int btnc, char* text[],Msgbox_cb cb,void *arg);
    virtual int fliterEvent(const SDL_Event& event); /* 捕获所有事件 */
    virtual ~SDLC_Msgbox();
};


#endif