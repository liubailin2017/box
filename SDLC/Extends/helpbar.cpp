#include"helpbar.h"
#include"../SDLC_Context.h"
Helpbar::Helpbar(SDLC_Context *context): SDLC_Image(context){
    load("help");
    setMovable(true);
    setvisible(false);
    setPostion((context->getWidth() - width)/2,(context->getHeight()-height)/2);
}

/* 当点击事件送到时，而不响应，就隐藏(Helpbar 如果放在根层，则只有点 context 才能触发隐藏) */
int Helpbar::fliterEvent(const SDL_Event& event) {
    int rs = SDLC_Component::fliterEvent(event);

    if(event.type == SDL_MOUSEBUTTONDOWN && rs == 0) {
        setvisible(false);
    }
    return rs;
}
