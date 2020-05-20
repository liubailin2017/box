#include"../SDLC_Component.h"
class AnimationTest : public SDLC_Component
{
private:
  SDL_Surface *imgs[9];

public:
    int cur;
    virtual void updateSurface();
    AnimationTest(SDLC_Context *context);
    virtual void defaultStrickHandler(SDLC_Component *cmp);

    friend void animation(SDLC_Component *cmp);
};
