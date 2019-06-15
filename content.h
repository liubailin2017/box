#include"person.h"
#include"box.h"
class map;

class content
{
private:
    person *p;
    map *m;
public:
    content(map *m);
    void display();
    ~content();
};

class map
{
private:
    block  b[182];
public:
    const int w = 14,h = 13;
    void read(int d[]);
    block* blocks();
};

