#include"block.h"
class box:public block
{
private:
    /* data */
public:
    virtual int type();
    virtual void display(int t );
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
