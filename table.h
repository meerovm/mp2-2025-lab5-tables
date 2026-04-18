#ifndef _polinom
#include "polinom.h"
#define _polinom
#endif
class table {
private:
    const size_t sz;
    polinom* m;
    int* f;
    size_t h1(polinom& t);
    size_t h2(polinom& t);
public:
    table(const size_t s = 10000007);
    ~table();
    bool find(polinom& p);
    void add(polinom& p);
    void pop(polinom& p);
    friend std::ostream& operator <<(std::ostream& out, const table& a);
};
