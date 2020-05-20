
#include"SDLC_Button.h"
#include"../sdltool.h"
#include"../SDLC_Context.h"
void SDLC_Button::updateSurface() {
 //nothing
}

// SDLC_Button::SDLC_Button(SDLC_Context *context,char *text) {

// }
// SDLC_Button::SDLC_Button(SDLC_Context *context,char *text,Uint32 bg) {

// }
SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d):SDLC_Button(context,x,y,w,d,0xffff00ff) {

}
SDLC_Button::SDLC_Button(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg):SDLC_Component(context,x,y,w,d,bg) {
    bgc_down = 0xffffffff;
    bgc = bg;
    bgc_in = 0xff00ffff;
}
    
void SDLC_Button::setText(std::string text) {
    
}

bool SDLC_Button::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {
    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        setbgcolor(bgc_down);
        break;
    case SDL_MOUSEBUTTONUP:
        setbgcolor(bgc);
        defaultInHandler(this);
    default:
        break;
    }
    return SDLC_Component::defaultmouseButtonHandler(event,cmp);
}

void SDLC_Button::defaultOutHandler(SDLC_Component *cmp) {
    setbgcolor(bgc);
    SDLC_Component::defaultOutHandler(cmp);
}

void SDLC_Button::defaultInHandler(SDLC_Component *cmp) {
    sdltool::line(surface,0,0,width,0,bgc_down,10);
    context->notifyUpdate();
    
    SDLC_Component::defaultInHandler(cmp);
}
