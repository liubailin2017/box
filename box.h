#ifndef _h_block_
#define _h_block_
#include"block.h"
class box:public block
{
private:
    /* data */
public:
    virtual int type();
    virtual void display(int t );
    virtual bool move(direct d);
};

class wall:public block
{
private:
    /* data */
public:
    virtual int type();
    virtual void display(int t );
      
};
 
class intend:public block
{
private:
    /* data */
public:
    virtual int type();
    virtual void display(int t );
};
#endif