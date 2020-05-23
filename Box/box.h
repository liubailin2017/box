#ifndef _h_block_
#define _h_block_
#include"block.h"
class box:public block
{
private:
    /* data */
public:
    box();
    virtual int type();
    virtual void display(int t );
    virtual bool move(direct d);

    virtual bool canpush();
    virtual bool cancover();
};

class wall:public block
{
private:
    /* data */
public:
    wall();
    virtual int type();
    virtual void display(int t );
    
    virtual bool canpush(); /* 不能推动 */
    virtual bool cancover(); /* 不能覆盖 */
    virtual bool move(direct d); 
};

class intend:public block
{
private:
    /* data */
public:
    intend();
    virtual int type();
    virtual void display(int t );
    virtual bool move(direct d);
};
#endif

