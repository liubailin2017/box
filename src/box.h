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
    
    virtual bool canpush();
    virtual bool cancover();
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

