#ifndef _h_SDLC_Component
#define _h_SDLC_Component
#include<SDL2/SDL.h>
class SDLC_Component;
class SDLC_Context;

#include"SDLC_Event.h"
    /*
    如图 控件结构 
    1
    |
    2----3-----4---D
    |    |     |
    5-6  7-8-9 E-F
    |            |
    A-B-C        G
    */
class SDLC_Component
{
protected:
    int id;
    int x;
    int y;
    int width;
    int height;
    bool isvisible;
    int upLock;
    SDL_Surface *surface;

    /* 控件上下文环境 */
    SDLC_Context *context;
    /* 下一个兄弟组件 */
    SDLC_Component *brother;
    /* 上一个兄弟组件 */
    SDLC_Component *prebrother;

    /* 子组件  */
    SDLC_Component *child;
    /* 父组件 */
    SDLC_Component *parent;

    /* 鼠标事件处理器 */
    Handler mouseButtonHandler;
    /* 鼠标移出事件处理器 */
    OutHandler outHandler;
    /* 鼠标移入事件处理器 */
    InHandler inHandler;
    /* 时钟事件处理器 */
    StrickHandler strickHandler; /* Note ： 时钟为 调用 上下文的strick() 函数产生 */
    /* 背景色 */
    Uint32 bgcolor;
    /* 是否可移动 */
    bool _movable;

    int intervalc;
    int interval;
    
    /* 是否可被升起， 移动到所有组件的最上方 */
    bool canRaise;

public:
    bool isRoot();
    /* 
        默认的事件处理(所有的事件都是通过这些函数间接调用事件处理器)
        当其它继承自这个基本组件的衍生组件时可重写这些函数实现自己的效果 
     */
    virtual bool defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp);
    virtual void defaultOutHandler(SDLC_Component *cmp);
    virtual void defaultInHandler(SDLC_Component *cmp);
    virtual void defaultStrickHandler(SDLC_Component *cmp);
    /* 绝对位置 */
    int abx();
    int aby();
    /* 相对位置 */
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    
    SDLC_Context* _context();

    /* 尾结点 */
    SDLC_Component* rear();
    /* 长兄节点 */
    SDLC_Component* header();

    virtual bool movable();
    
    /* 设置背景色 */
    virtual void setbgcolor(Uint32 bg);
    virtual Uint32 getBgcolor();

    void setMovable(bool v);
    void setRaise(bool v);
    /*  时钟 */
    void strick();
    void setInterval(int i,StrickHandler h); 

    virtual void setListener(Handler handler);
    virtual void setOutHandler(OutHandler outHandler);
    virtual void setInHandler(InHandler outHandler);


    int getId();
    /* api */
    
    /* 判断是否处理些事件
    返回：
    0 不处理事件
    1 处理事件
    2 鼠标事件 当前点为透明
    */
    virtual int fliterEvent(const SDL_Event& event) ;
    /* 事件分发 */
    virtual bool dispatch(const SDL_Event& event);
    virtual bool handleEvent(const SDL_Event& event);

    /* 可见性 */
    virtual bool visible();
    virtual void setvisible(bool isvisible);

    virtual void setchild(SDLC_Component *cmp);
    virtual void setbrother(SDLC_Component *cmp);

    /* 添加儿子结点 */
    virtual void addComponent(SDLC_Component *cmp);

    virtual void setPostion(int x,int y);
    virtual void setSize(int width,int height);

//    virtual void ondraw(SDL_Surface* surface);
    /* 更新背景 */
    virtual void updateSurface();

    /* 把当前surface 更新到 上下文的surface上面 */
    virtual void display();
    virtual SDLC_Component *findById(int id); /* 在儿子节点下查找 */
    virtual SDLC_Component *removeById(int id); 


    virtual void raise();

    SDLC_Component(SDLC_Context *context);
    SDLC_Component(SDLC_Context *context,int w,int d);
    SDLC_Component(SDLC_Context *context,int x,int y,int w,int d);
    SDLC_Component(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg);
    
    ~SDLC_Component();
    friend class SDLC_Context;
};

#endif