#include"bfs.h"
namespace tool
{

bfs::bfs():_w(0),_h(0),map(nullptr),print(nullptr){}

bfs::~bfs() {
    if(print) delete[] print;
}


void bfs::set(char *map,int w,int h) {
    setMap(map);
    setSize(w,h);
}

void bfs::setMap(char* map) {
    this->map = map;
}

void bfs::setSize(int w,int h) {
    _w = w;
    _h = h;
    if(print) delete[] print;
    print = new char[w*h];
}

pos* bfs::_BFS(pos s,pos t,queue<pos>& q) {
    if(!map) return nullptr;
    if( *(map+t.y*_w+t.x) || *(map+s.y*_w+s.x)) return nullptr;
    
    q.push(s);

    pos *tmp = q._peek();
    q.pop();

    while (tmp)
    {
        if(*tmp == t) return tmp;
        if(
            (tmp->y >=0 && tmp->y<_h && (tmp->x+1) >=0 && (tmp->x+1) < _w)
            &&
            map[(*tmp).y*_w+(*tmp).x+1] == 0
            &&
            !print[(*tmp).y*_w+(*tmp).x+1]) {
                pos tmp2;
                tmp2.pre = tmp;
                tmp2.x = (*tmp).x+1;
                tmp2.y = (*tmp).y;
                q.push(tmp2);
                print[(*tmp).y*_w+(*tmp).x+1] = 1;
            }
        if(
            (tmp->y >=0 && tmp->y<_h && (tmp->x-1) >=0 && (tmp->x-1) < _w)
            &&
            map[(*tmp).y*_w+(*tmp).x-1] == 0
            &&
            !print[(*tmp).y*_w+(*tmp).x-1]) {
                pos tmp2;
                tmp2.pre = tmp;
                tmp2.x = (*tmp).x-1;
                tmp2.y = (*tmp).y;
                q.push(tmp2);
                print[(*tmp).y*_w+(*tmp).x-1] = 1;
            }
        
        if(
            ( (tmp->y+1) >=0 && (tmp->y+1)<_h && tmp->x >=0 && tmp->x < _w)
            &&
            map[((*tmp).y+1)*_w+(*tmp).x] == 0
            &&
            !print[((*tmp).y+1)*_w+(*tmp).x]) {
                pos tmp2;
                tmp2.pre = tmp;
                tmp2.x = (*tmp).x;
                tmp2.y = (*tmp).y+1;
                q.push(tmp2);
                print[((*tmp).y+1)*_w+(*tmp).x] = 1;
            }
            
        if(
            ( (tmp->y-1) >=0 && (tmp->y-1)<_h && tmp->x >=0 && tmp->x < _w)
            &&
            map[((*tmp).y-1)*_w+(*tmp).x] == 0
            &&
            !print[((*tmp).y-1)*_w+(*tmp).x]) {
                pos tmp2;
                tmp2.pre = tmp;
                tmp2.x = (*tmp).x;
                tmp2.y = (*tmp).y-1;
                q.push(tmp2);
                print[((*tmp).y-1)*_w+(*tmp).x] = 1;
            }
            tmp = q._peek();
            q.pop();
    }
    return nullptr;
}

#include<string.h>
pos* bfs::BFS(pos s,pos t,queue<pos>& q) {
    memset(print,0,_w*_h);
    return   _BFS(t,s,q);
}

bool pos::operator==(const pos &t) {
    if(t.x == x && t.y == y) 
        return true;
    else
        return false;
}
#include"src/base.h"
pos::pos():x(-1),y(-1),pre(nullptr) {};
int pos::action(const pos& cur) {
    if(cur.x - x == 1 && cur.y == y) {
        return LEFT;
    }
    if(cur.x - x == -1 && cur.y == y) {
        return RIGHT;
    }
    if(cur.y - y == 1 && cur.x == x) {
        return UP;
    }
    if(cur.y - y == -1 && cur.x == x) {
        return DOWN;
    }
    return -1;
}
    
} // namespace tool
