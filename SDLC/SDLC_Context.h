#ifndef _h_SDLC_Context
#define _h_SDLC_Context
#include<SDL2/SDL.h>
#include"SDLC_Event.h"
class SDLC_Component;

class SDLC_Context;
/* 
事件处理回调
*/
typedef bool (*HandleFun)(const SDL_Event &event,SDLC_Context *context);

typedef void (*UpdateBg)(SDL_Surface* surface);
class SDLC_Context {
private :
    int status[10];
    /*用于生成id,使id不重复 */
    bool shouldRepatint;
    int cid;
    int width;
    int height;
    SDL_Surface *surface;
    SDL_Window *window;
    SDLC_Component *components;
    SDLC_Component *curCmp;
    SDLC_Component *curMvCmp;
    SDLC_Component *focusCmp;
    UpdateBg updateBg;
    HandleFun onhandle;

    StrickHandler strickHandler;

    int interval;
    int intervalc;

public:
    SDLC_Context(SDL_Window *w);

    int getWidth();
    int getHeight();
    
    int generateId();
    bool fliterEvent(const SDL_Event& event);
    
    /* 事件分发给字控件 */
    bool dispatch(const SDL_Event& event);

    /* 更新上下文的 window */
    void update(SDL_Window *w);
    /* 更新 width height 以及surface 用于在窗口大小变更时调用 */
    void update();

    /*  添加组件 */
    SDLC_Component* addComponent(SDLC_Component *component);
    SDLC_Component *findById(int id);
    SDLC_Component *removeById(int id);
    /* 设置主要的处理监听 */
    void setListener(HandleFun handler);
    /* 设置更新背景时的监听 */
    void setListener(UpdateBg handler);

    /* 设置定时调用函数 
    每调用i次strick() 回调一次 h回调函数 */
    void setInterval(int i,StrickHandler h);

    /* 驱动时钟 */
    void strick();
    void resetIntervalc();
    void notifyUpdate();

    void updateWindow();



    friend class SDLC_Component;
};
bool SDLC_Init();
#endif
