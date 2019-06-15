#include "block.h"

class person:public block {

    private :
        direct _inter_push_dir;
        
    public:
        person();
        virtual void display(int t);
        virtual void push();
        virtual bool move(direct d);
        virtual int type();
};