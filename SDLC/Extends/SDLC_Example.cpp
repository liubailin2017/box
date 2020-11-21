#include"SDLC_Example.h"
#include"../SDLC_Context.h"
SDLC_Example::SDLC_Example(SDLC_Context* context,int r):SDLC_Com_Radius(context,0,0,r*2,r*2,0x66883456) {
    setRadius(r);
 
    dx = 32;
    dy = 48;
    canRaise = true;

}
    
bool SDLC_Example::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {
    SDLC_Component::defaultmouseButtonHandler(event,cmp);
    return false;
}

void SDLC_Example::defaultStrickHandler(SDLC_Component *cmp) {
 
    if(x > context->getWidth() - getWidth()) dx = -32;
    if(y > context->getHeight() - getHeight()) dy = -48;
    if(x <= 0) dx = 32;
    if(y <= 0) dy = 48;
    x += dx;
    y += dy;
   context->notifyUpdate();
}
