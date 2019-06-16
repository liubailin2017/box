#ifndef _h_content_
#define _h_content_
#include "person.h"
#include "block.h"
#include "box.h"
class map;

class content
{
private:
    person *p;
    map *m;
public:
    map* getmap();
    content(map *m);
    void display();
    person *_p();
    void actinput(direct d);
    bool isfinsh();
    ~content();
};

class map
{
private:
    block  b[182];
    int w;
    int h;
public:
    map();
    int _w();
    int _h();
    void read(int d[]);
    block* blocks();
  
};

#endif