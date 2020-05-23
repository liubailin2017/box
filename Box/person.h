#ifndef _h_person_
#define _h_person_ 
#include"block.h"
enum PERSON_STATUS{
        FU0=0,FU1,FU2,FD0=10,FD1,FD2,FL0=20,FL1,FR0=30,FR1
};
#include"../bfs.h"
class person:public block {

    private :
        direct _inter_push_dir; /* 人物方向 */
        PERSON_STATUS status; /* 状态 上下左右 ... */
        virtual bool push();  /* 朝人物方向推 false 没推动 true 推动*/
    public:
        person();
        virtual ~person();
        /* 把当前对象绘制到模版上 */
        virtual void display(int t);
        virtual void befor_move(direct d); /* 主要用来改变状态 于真正游戏 意义不大 */
        virtual bool move(direct d); /* 移动 ，如果有障碍就产生推的动作 */
        virtual void after_move(direct d);/* 主要用来改变状态 于真正游戏 意义不大 */
        virtual bool back_move(direct d); /* 用于拉的移动 ，不会产生推的动作 */
        virtual int type();
        virtual int _status();
        virtual bool pull(); /* 推返回就对应着拉 */
        virtual tool::pos getPostion();
};
#endif

