#ifndef _polinom
#include "polinom.h"
#define _polinom
#endif

class mas {
private:
    polinom* t;
    const size_t sz;
    int l = 0;
public:
    mas(const size_t s);
    ~mas();
    void add(const polinom& p);
    void pop(const polinom& p);
    bool find(const polinom& p);
    friend std::ostream& operator <<(std::ostream& out, const mas& a);
};

