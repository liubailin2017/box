#ifndef _H_BLOCK_
#define _H_BLOCK_
#include "base.h"
class content;
class block //其实这是一个双向链表
{

private:

    content *_content;
protected: 
    block *root = nullptr;
    block *rear = nullptr;

    block *lay = nullptr;
    block *cover = nullptr;
public:

    block* _root();
    block* _rear();
    block* _lay();
    block* _cover();

    void   _cover(block *);
    block* _rmcover();

    block();
    ~block();

    virtual void display(int t );
    virtual bool canpush();
    virtual bool cancover();
    virtual bool move(direct d);
    virtual int type();
    void setContent(content *);
    content* getContent();
    friend class map;
    friend class content;
};

#endif