#include"base.h"
#ifndef _H_BLOCK_
#define _H_BLOCK_
class block //其实这是一个双向链表
{

private:
    block *root = nullptr;
    block *rear = nullptr;
protected:    
    block *lay = nullptr;
    block *cover = nullptr;
public:
    void   _cover(block *);
    block* _rmcover();

    block();
    ~block();

    virtual void display(int t );
    virtual bool canpush();
    virtual bool cancover();
    virtual bool move(direct d);
    virtual int type();

    friend class map;
    friend class content;
};

#endif