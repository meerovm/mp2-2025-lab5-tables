#ifndef _polinom
#include"polinom.h"
#define _polinom
#endif

struct nd {
    polinom* t;
    nd* l;
    nd* r;
    nd* pr;
    bool c;
    nd (polinom& p,  bool cc, nd*ppr = nullptr, nd* ll = nullptr, nd* rr = nullptr) {
        t = new polinom(p);
        l = ll;
        pr = ppr;
        r = rr;
        c = cc;
    }
};
class rbtree {
private:
    nd* r;
    void balance_add(nd* v);
    void balance_pop(nd* v);
    void rotatel(nd* v);
    void rotater(nd* v);
public:
    rbtree();
    ~rbtree();
    void add(polinom& p);
    void pop(polinom& p);
    bool find(polinom& p);
    friend std::ostream& operator <<(std::ostream& out, const rbtree& a);
};