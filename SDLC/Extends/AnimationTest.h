#include"../SDLC_Component.h"


typedef struct RECTS {
  SDL_Rect *rect;
  int len;
};
class AnimationTest : public SDLC_Component
{
private:
  SDL_Surface *src; /* 原始图*/
  RECTS rects;
  int cur;
public:
    
    virtual void updateSurface();
    AnimationTest(SDLC_Context *context);
    virtual void defaultStrickHandler(SDLC_Component *cmp);

    friend void animation(SDLC_Component *cmp);
};
