#ifndef _H_BLOCK_
#define _H_BLOCK_
#include "base.h"
class content;
class block /* 其实这是一个双向链表 */
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

    block* & _root(); /* 头 */
    block* & _rear(); /*尾 */
    block* & _lay();  /* 返回 这个对象覆盖的对象 */
    block* & _cover();  /* 返回覆盖在这个对象上的对象 */

    void   _cover(block *);/* 覆盖上一个对象 */
    block* _rmcover(); /* 移除这个对象  return this */

    virtual void display(int t ); /* 把这个对象 打印到模版 如果是图形界面 则画图，如果是控制台，则打印符号 */
    virtual bool canpush(); /* 是否可推动 */
    virtual bool cancover(); /* 是否可被覆盖 */
    virtual bool move(direct d); /* 移动 */
    virtual int type(); /* 类型 */ 
    void setContent(content *);
    content* getContent();
    friend class map;
    friend class content;
};

#endif

