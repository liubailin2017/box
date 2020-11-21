#ifndef EXtends_SDLC_Example_h
#define EXtends_SDLC_Example_h
#include"../SDLC_Com_Radius.h"

class SDLC_Example :public SDLC_Com_Radius
{
    private:
 
    int dx;
    int dy;
    public:
    SDLC_Example(SDLC_Context* context,int r);
    virtual bool defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp);
    virtual void defaultStrickHandler(SDLC_Component *cmp);

};


#endif