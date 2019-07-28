#ifndef _h_content_
#define _h_content_
#include "person.h"
#include "block.h"
#include "box.h"
#include <stack>
class map;

class content
{
private:
    person *p;
    map *m;
    std::deque<int> memery;
protected:

    person *_p();

public:
    map* getmap();
    content(map *m);
    void display();
    void actinput(direct d);
    bool isfinsh();
    
    void pushm(int d);
    int popm(); //-1 表示空
    int popf();
    int msize();
    void back();
    void init();

    ~content();
};

class map
{
private:
    block  *b;
    int w;
    int h;
public:
    map();
    ~map();
    int _w();
    int _h();
    void read(int d[]);
    block* blocks();
  
};

#endif

