#ifndef toolbfs_h
#define toolbfs_h

namespace tool {

template<class T> class queue;
typedef struct pos{
    int x;
    int y;
    struct pos* pre;
    pos();
    int action(const pos& curPos);
    bool operator==(const pos &t);
}pos;

class bfs
{
private:
    int _w;
    int _h;
    char *map;
    char *print;
    pos* _BFS(pos s,pos t,queue<pos>& q);
public:
    void set(char *map,int w,int h);
    void setMap(char* map);
    void setSize(int w,int h);
 
    pos* BFS(pos s,pos t,queue<pos>& q);

    bfs();
    virtual ~bfs();
};

template<class T>
class queue{
    private:
    T* t;
    int r;
    int l;
    int tmpsize;
    public : 
    queue():queue(20481) {}
    queue(int size):r(0),l(0),tmpsize(size+1) {
        t = new T[tmpsize];
    }
    
    virtual ~queue() {
        if(t != nullptr) {
            delete[] t;
        }
    }

    int size() {
        return (r + tmpsize - l) % tmpsize;
    }
    bool isEmpty() {
        if(size() == 0) 
            return true;
        else
            return false;
    }

    bool isfull() {
        if(size() == tmpsize-1) 
            return true;
        else 
            return false;
    }

    bool push(T _t) {
        if(!isfull()) {
            int p = (r+1+tmpsize) % tmpsize;
            t[p] = _t;
            r = p;
            return true;
        }
        return false;
    }

    T peek() {
            return t[(l+tmpsize+1) % tmpsize];
    }

    T* _peek() {
        if(isEmpty())
            return nullptr;
        else
            return t + (l+tmpsize+1) % tmpsize;
    }
    T* _peekrear() {
        if(isEmpty())
            return nullptr;
        else
            return t + (r+tmpsize) % tmpsize;
    }

    bool pop() {
        if(isEmpty()) {
            return false;
        }else {
            l = (l+1+tmpsize)%tmpsize;
            return true;
        }
    }

    void clean() {
        l =  r = 0;
    }
};

} // namespace tool

#endif //toolbfs_h
