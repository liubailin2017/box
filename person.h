#ifndef _h_person_
#define _h_person_ 
#include"block.h"
class person:public block {

    private :
        direct _inter_push_dir;
    public:
        person();
        virtual void display(int t);
        virtual bool push();
        virtual bool move(direct d);
        virtual bool back_move(direct d);
        virtual int type();
        virtual bool pull(); //推返回就对应着拉
};
#endif