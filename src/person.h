#ifndef _h_person_
#define _h_person_ 
#include"block.h"
enum PERSON_STATUS{
        FU0=0,FU1,FU2,FD0=10,FD1,FD2,FL0=20,FL1,FR0=30,FR1
};
class person:public block {

    private :
        direct _inter_push_dir;
        PERSON_STATUS status;
        virtual bool push();
    public:
        person();
        virtual ~person();
        virtual void display(int t);
        virtual void befor_move(direct d);
        virtual bool move(direct d);
        virtual void after_move(direct d);
        virtual bool back_move(direct d);
        virtual int type();
        virtual int _status();
        virtual bool pull(); //推返回就对应着拉
};
#endif

