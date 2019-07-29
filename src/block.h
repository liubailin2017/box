#ifndef _H_BLOCK_
#define _H_BLOCK_
#include "base.h"
class content;
class block //其实这是一个双向链表
{

private:
  
    content *_content;
protected:
    int __type;
    
    block *root;
    block *rear;

    block *lay;
    block *cover;
public:

    block();
    virtual ~block();

    block* & _root();
    block* & _rear();
    block* & _lay();
    block* & _cover();

    void   _cover(block *);
    block* _rmcover();

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

