#include "table.h" 
size_t table::h1(polinom& t) {
        size_t res = 0;
        int x = 41;
        size_t n = t.p.CheckSize();
        node* q = t.p.next;
        for (int i = 0; i < n; i++) {
            res = (res * x + std::hash<double>{}(q->k)) % sz;
            q = q->next;
        }
        return res;
}
size_t table::h2(polinom& t) {
        size_t res = 0;
        int x = 37;
        size_t n = t.p.CheckSize();
        node* q = t.p.next;
        for (int i = 0; i < n; i++) {
            res = (res * x + std::hash<double>{}(q->k)) % sz;
            q = q->next;
        }
        return res;
}
table::table(const size_t s) : sz(s) {
        m = new polinom[sz];
        f = new int[sz];
        for (int i = 0; i < s; i++) { f[i] = 0; }
}
table::~table() {
        delete []m;
        delete [] f;
}
bool table::find(polinom& p) {
        size_t x = h1(p)%sz;
        size_t t = h2(p)%(sz - 1) + 1;
        size_t i = 0;
        while (i < sz && f[(x + i * t)%sz] != 0) {
            if (f[(x + i * t)%sz] == 1) {
                if (m[(x + i * t)%sz] == p) {
                    return 1;
                }
            }
            i++;
        }
        return 0;
}

void table::add(polinom& p) {
    if (!find(p)) {
        size_t x = h1(p) % sz;
        size_t t = h2(p) % (sz - 1) + 1;
        size_t i = 0;
        while (i < sz) {
            if (f[(x + i * t) % sz] <= 0) {
                m[(x + i * t) % sz] = p;
                f[(x + i * t) % sz] = 1;
                return;
            }
            i++;
        }
    }
}

void table::pop(polinom& p) {
        size_t x = h1(p)%sz;
        size_t t = h2(p)%(sz - 1) + 1;
        size_t i = 0;
        while (f[(x + i * t) % sz] != 0) {
            if (f[(x + i * t) % sz] == 1) {
                if (m[(x + i * t) % sz] == p) {
                    f[(x + i * t) % sz] = -1;
                    return;
                }
            }
            i++;
        }
}

std::ostream& operator <<(std::ostream& out, const table& a) {
    for (int i = 0; i < a.sz; i++) {
        if (a.f[i] == 1) {
            out << a.m[i] << " ";
        }
    }
    return out;
};