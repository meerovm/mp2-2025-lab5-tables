// polinom from lab4 polinom
// new: operator >/</=
#ifndef _list
#include "list.h"
#define _list
#endif

#ifndef _str
#include "string"
#define _str
#endif


#include <random>

class polinom {
public:
	list p;
	polinom(std::string& s);

	polinom(list& q);

	polinom();

	polinom operator +(const polinom& a);

	polinom operator -(const polinom& a);

	polinom operator *(const polinom& a);

	polinom operator *(const double a);

	bool operator==(const polinom& a);

	bool operator > (const polinom& a);

	bool operator <(const polinom& a);
	~polinom();

	friend std::ostream& operator <<(std::ostream& out, const polinom& a);
};

class randpolinom {
private:
	std::mt19937 gd;
	std::uniform_real_distribution<double> d;
	std::mt19937 x;
	std::uniform_int_distribution<int> dx;
	std::mt19937 y;
	std::uniform_int_distribution<int> dy;
	std::mt19937 z;
	std::uniform_int_distribution<int> dz;
	std::mt19937 c;
	std::uniform_real_distribution<double> dc;
public:
	randpolinom(unsigned int aa = 777, double l = 0.0, double r = 1000000.0) :gd(aa), d(l, r), x(aa + 1), dx(0, 9), y(aa + 2), dy(0, 9), z(aa + 3), dz(0, 9), c(aa + 4), dc(0, 30) {	}
	polinom getrandpolinom() {
		polinom p;
		for (int i = 0; i < dc(c); i++) {
			std::string s;
			int a = dx(x) % 10;
			s += std::to_string(d(gd));
			if (a != 0) {
				s += "x";
				s += std::to_string(a);
			}
			a = dy(y) % 10;
			if (a != 0) {
				s += "y";
				s += std::to_string(a);
			}
			a = dz(z) % 10;
			if (a != 0) {
				s += "z";
				s += std::to_string(a);
			}
			p = p + polinom(s);
		}
		return p;
	}
};