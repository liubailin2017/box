#include"base.h"

class block
{

private:
    
public:
    block *lay;
    block *cover;
    block();
    ~block();

    virtual void display(int t );
    virtual bool canpush();
    virtual bool cancover();
    virtual bool move(direct d);
    virtual int type();

};

