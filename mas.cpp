#include "mas.h"
#include<algorithm>
#include<iostream>
mas::mas(const size_t s) : sz(s), l(0) {
    t = new polinom[sz];
}
mas::~mas() { delete[] t; }
    
void mas::add(const polinom& p) {
    if (l >= sz) {
        throw std::out_of_range("count of element more the size");
    }
    polinom *q = std::lower_bound(t, t + l, p);
    size_t i = std::distance(t, q);
    if (!(t[i] == p)) {
        for (int j = l; j > i; j--) {
            t[j] = t[j - 1];
        }
        t[i] = p;
        l++;
    }
}

void mas::pop(const polinom& p) {
    polinom* q = std::lower_bound(t, t + l, p);
    if (q != t + l) {
        size_t i = std::distance(t, q);
        if ((i < l) && (t[i] == p)) {
            for (; i < l - 1; i++) {
                t[i] = t[i + 1];
            }
            l--;
        }
    }
}
bool mas::find(const polinom& p) {
    polinom* i = std::lower_bound(t, t + l, p);
    if ((i != t + l) && (*i == p)) {
        return 1;
    }
    return 0;
}

std::ostream& operator <<(std::ostream& out, const mas& a) {
    for (int i = 0; i < a.l; i++) {
        out << a.t[i] << " ";
    }
    return out;
};

