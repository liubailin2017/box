#ifndef _image_h_Extends_
#define _image_h_Extends_
#include "../SDLC_Component.h"
#include "string"
class SDLC_Image : public SDLC_Component
{
private:
  SDL_Surface *img;
public:
    virtual void updateSurface();
    SDLC_Image(SDLC_Context *context);
    SDLC_Image(SDLC_Context *context,int w,int d);
    SDLC_Image(SDLC_Context *context,int x,int y,int w,int d);
    SDLC_Image(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg);
    virtual ~SDLC_Image();
    void load(char name[]);

};
#endif