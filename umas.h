#ifndef _polinom
#include "polinom.h"
#define _polinom
#endif

class umas {
private:
    polinom* t;
    const size_t sz;
    size_t l;
public:
    umas(const size_t s);
    ~umas();
    void add(const polinom& p);
    void pop(const polinom& p);
    bool find(const polinom& p);
    friend std::ostream& operator <<(std::ostream& out, const umas& a);
};
