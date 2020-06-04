#ifndef _h_SDLC_Com_Radius
#define _h_SDLC_Com_Radius
#include<SDL2/SDL.h>
#include"SDLC_Component.h"

class SDLC_Com_Radius: public SDLC_Component
{

private:
    int radius;
public:
    void setRadius(int r);
    int getRadius();

    /* override */
    void updateSurface();
    SDLC_Com_Radius(SDLC_Context *context);
    SDLC_Com_Radius(SDLC_Context *context,int w,int d);
    SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d);
    SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg);

    SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg,int r);
};

#endif