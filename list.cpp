// list from lab4 polinom
#ifndef _list
#include "list.h"
#define _list
#endif

list::list() {
	sz = 0;
	next = nullptr;
}

list::list(const list& a) {
	sz = 0;
	next = nullptr;
	node* t = a.next;
	while (t != nullptr) {
		push(*t);
		t = t->next;
	}
}

list& list::operator=(const list& a) {
	this->~list();
	sz = a.sz;
	node* t = a.next;
	node* tt = new node(0, 0, next);
	node* q = tt;
	int f = 0;
	while (t != nullptr) {
		node* v = new node(t->t, t->k, nullptr);
		if (f == 0) {
			next = v;
			q->next = next;
		}
		else {
			q->next = v;
		}
		q = q->next;
		t = t->next;
		f = 1;
	}
	delete tt;
	return *this;
}

bool list::is_empty() const { return (sz == 0); };

void list::push(const node& el) {
	if (next == nullptr) {
		node* n = new node(el);
		n->next = nullptr;
		next = n;
		sz++;
	}
	else {
		node* w = new node(0, 0, next);
		node* n = w;
		int f = 0;
		int ff = 0;
		while (n->next) {
			if (*n->next > el) {
				node* v = new node(el);
				v->next = n->next;
				if (f == 0) {
					next = v;
				}
				else {
					n->next = v;
				}
				sz++;
				break;
			}
			else {
				if (*n->next == el) {
					if ((*n->next + el) == 0) {
						node* v = n->next;
						if (f != 0) {
							if (v->next) {
								n->next = v->next;
								delete v;
							}
							else {
								n->next = nullptr;
								ff = 1;
								delete v;
							}
						}
						else {
							node* v = next;
							next = next->next;
							delete v;
						}
					}
					else {
						n->next->k += el.k;
					}
					break;
				}
				else {
					n = n->next;
				}
			}
			f = 1;
		}
		if ((n->next == nullptr) && (ff == 0)) {
			node* el_1 = new node(el);
			n->next = el_1;
			el_1->next = nullptr;
			sz++;
		}
		delete w;
	}
}

void list::pop(const node& el) {
	sz--;
	node* w = new node(0, 0, next);
	node* n = w;
	int f = 0;
	if (n->next == nullptr) {
		throw std::invalid_argument("Invalid argument in function pop");
	}
	while (n->next) {
		if (*n->next == el) {
			node* v = n->next;
			if (f == 0) {
				next = v->next;
			}
			else {
				if (v != nullptr) {
					n->next = v->next;
				}
				else {
					n->next = nullptr;
				}
			}
			delete v;
			break;
		}
		f = 1;
		n = n->next;
	}
	if (n == nullptr) {
		throw std::invalid_argument("Invalid argument in function pop");
	}
	delete w;
}

size_t list::CheckSize() const { return sz; };

list::~list() {
	sz = 0;
	node* n;
	while (next != nullptr) {
		n = next;
		next = next->next;
		delete n;
	}
}

std::ostream& operator <<(std::ostream& out, const list& a) {
	node* n = a.next;
	int f = 0;
	if (n == nullptr) {
		out << "0";
	}
	while (n) {
		if (f == 0) {
			if (n->k == 1) {
				if (((n->t / 100) % 10 == 0) && ((n->t / 10) % 10 == 0) && ((n->t) % 10 == 0)) {
					out << n->k;
				}
			}
			else {
				if (n->k == -1) {
					out << "-";
					if (((n->t / 100) % 10 == 0) && ((n->t / 10) % 10 == 0) && ((n->t) % 10 == 0)) {
						out << abs(n->k);
					}
				}
				else {
					out << n->k;
				}
			}
		}
		else {
			if (n->k > 0) {
				out << "+";
			}
			if (n->k == 1) {
				if (((n->t / 100) % 10 == 0) && ((n->t / 10) % 10 == 0) && ((n->t) % 10 == 0)) {
					out << n->k;
				}
			}
			else {
				if (n->k == -1) {
					out << "-";
					if (((n->t / 100) % 10 == 0) && ((n->t / 10) % 10 == 0) && ((n->t) % 10 == 0)) {
						out << abs(n->k);
					}
				}
				else {
					out << n->k;
				}
			}
		}
		if ((n->t / 100) % 10 != 0) {
			if ((n->t / 100) % 10 == 1) {
				out << "x";
			}
			else {
				out << "x^" << (n->t / 100) % 10;
			}
		}
		if ((n->t / 10) % 10 != 0) {
			if ((n->t / 10) % 10 == 1) {
				out << "y";
			}
			else {
				out << "y^" << (n->t / 10) % 10;
			}
		}
		if ((n->t) % 10 != 0) {
			if ((n->t) % 10 == 1) {
				out << "z";
			}
			else {
				out << "z^" << (n->t) % 10;
			}
		}
		f = 1;
		n = n->next;
	}
	return out;
};