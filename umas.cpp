
#include "umas.h"
#include <stdexcept> 

umas::umas(const size_t s) : sz(s) {
    t = new polinom[sz];
    l = 0;
}
umas::~umas() { delete[] t; }
void umas::add(const polinom& p) {
    if (l < sz) {
        if (!find(p)) {
            t[l] = p;
            l++;
        }
    }
    else {
        throw std::out_of_range("count of element more the size");
    }
}
void umas::pop(const polinom& p) {
    for (int i = 0; i < l; i++) {
        if (t[i] == p) {
            t[i] = t[l - 1];
            l--;
            return;
        }
    }
}
bool umas::find(const polinom& p) {
    for (int i = 0; i < l; i++) {
        if (t[i] == p) {
            return 1;
        }
    }
    return 0;
}

std::ostream& operator <<(std::ostream& out, const umas& a) {
    for (int i = 0; i < a.l; i++) {
        out << a.t[i] << " ";
    }
    return out;
};