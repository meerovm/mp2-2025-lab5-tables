// list from lab4 polinom
#include <stdexcept>
#include <ostream>

struct node {
	int t;
	double k;
	node* next;
	const double eps = 0.000000001;
	bool operator < (const node& a) { return (t - a.t) < 0; }
	bool operator > (const node& a) { return (t - a.t) > 0; }
	bool operator == (const node& a) { return (((t - a.t) == 0) && (abs((k - a.k)) < eps)); }
	bool operator == (int c) { return (k == c); }

	node operator * (const node& a) {
		if ((a.t % 10 + t % 10) > 9) {
			throw std::invalid_argument("degree of z must be less than 10");
		}
		if (((a.t / 10) % 10 + (t / 10) % 10) > 9) {
			throw std::invalid_argument("degree of y must be less than 10");
		}
		if (((a.t / 100) % 10 + (t / 100) % 10) > 9) {
			throw std::invalid_argument("degree of x must be less than 10");
		}
		node q = node(a);
		q.k = a.k * k;
		q.t = a.t + t;
		return q;
	}

	node operator + (const node& a) {
		if (a.t != t) {
			throw std::invalid_argument("degrees in sum must be equal");
		}
		node q = node(*this);
		q.k = a.k + k;
		q.t = a.t;
		return q;
	}

	node(int a = 0, double b = 0, node* n = 0) {
		if (a > 999) {
			throw std::invalid_argument("degree must be less than 10");
		}
		t = a;
		k = b;
		next = n;
	}

	node(int c_x, int c_y, int c_z, double b, node* n = 0) {
		if (c_x > 9) {
			throw std::invalid_argument("degree of x must be less than 10");
		}
		if (c_y > 9) {
			throw std::invalid_argument("degree of y must be less than 10");
		}
		if (c_z > 9) {
			throw std::invalid_argument("degree of z must be less than 10");
		}
		t = c_x * 100 + c_y * 10 + c_z;
		k = b;
		next = n;
	}

	node(const node& a)
	{
		t = a.t;
		k = a.k;
		next = nullptr;
	}

	~node() {}
};


class list {
private:
	size_t sz;
public:
	node* next;

	list();

	list(const list& a);

	list& operator=(const list& a);

	bool is_empty() const;

	void push(const node& el);

	void pop(const node& el);

	size_t CheckSize() const;

	~list();

	friend std::ostream& operator <<(std::ostream& out, const list& a);
};
