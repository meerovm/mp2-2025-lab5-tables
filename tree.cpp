#ifndef _tree
#include "tree.h"
#define _tree
#endif

#ifndef _polinom
#include "polinom.h"
#define _polinom
#endif

#ifndef _stack
#include "stack.h"
#endif

rbtree::rbtree() {
	r = nullptr;
}

rbtree::~rbtree() {
	Stack<nd*> q;
	if (r != nullptr) {
		nd* w;
		q.Push(r);
		while (!q.IsEmpty()) {
			w = q.Pop();
			if (w->l != nullptr) {
				q.Push(w->l);
			}
			if (w->r != nullptr) {
				q.Push(w->r);
			}
			delete w;
		}
	}
}

void rbtree::balance_add(nd* v) {
	while ((v->pr != nullptr) && (v->pr->pr != nullptr) && (v->pr->c == 0)) {
		if ((v->pr == v->pr->pr->l)) {
			nd* d = v->pr->pr->r;
			if ((d != nullptr) && (d->c == 0)) {
				v->pr->c = 1;
				d->c = 1;
				v->pr->pr->c = 0;
				v = v->pr->pr;
			}
			else {
				if (v == v->pr->r) {
					v = v->pr;
					rotatel(v);
				}
				v->pr->c = 1;
				v->pr->pr->c = 0;
				rotater(v->pr->pr);
			}
		}
		else {
			nd* d = v->pr->pr->l;
			if ((d != nullptr) && (d->c == 0)) {
				v->pr->c = 1;
				d->c = 1;
				v->pr->pr->c = 0;
				v = v->pr->pr;
			}
			else {
				if (v == v->pr->l) {
					v = v->pr;
					rotater(v);
				}
				v->pr->c = 1;
				v->pr->pr->c = 0;
				rotatel(v->pr->pr);
			}
		}
	}
	r->c = 1;
}

void rbtree::rotatel(nd* v) {
	nd* q = v->r;
	v->r = q->l;
	if (q->l != nullptr) {
		q->l->pr = v;
	}
	q->pr = v->pr;
	if (v->pr == nullptr) {
		r = q;
	}
	else {
		if (v == v->pr->l) {
			v->pr->l = q;
		}
		else {
			v->pr->r = q;
		}
	}
	q->l = v;
	v->pr = q;
};

void rbtree::rotater(nd* v) {
	nd* q = v->l;
	v->l = q->r;
	if (q->r != nullptr) {
		q->r->pr = v;
	}
	q->pr = v->pr;
	if (v->pr == nullptr) {
		r = q;
	}
	else {
		if (v == v->pr->r) {
			v->pr->r = q;
		}
		else {
			v->pr->l = q;
		}
	}
	q->r = v;
	v->pr = q;
};

void rbtree::add(polinom& p) {
	nd* v = new nd(p, 0);
	if (r == nullptr) {
		r = v;
	}
	else {
		nd* q = r;
		nd* w = q;
		while (q != nullptr) {
			w = q;
			if (p < *q->t) {
				q = q->l;
			}
			else {
				if (p == *q->t) {
					return;
				}
				q = q->r;
			}
		}
		v->pr = w;
		if (*v->t < *w->t) {
			w->l = v;
		}
		else {
			w->r = v;
		}
		balance_add(v);
	}
}

void rbtree::balance_pop(nd* v) {
	while ((v != nullptr) && (v != r) && (v->c == 1)) {
		if (v == v->pr->l) {
			nd* w = v->pr->r;
			if ((w->c == 0) && w != nullptr) {
				w->c = 1;
				v->pr->c = 0;
				rotatel(v->pr);
				w = v->pr->r;
			}
			if (((w->l == nullptr) || (w->l->c == 1)) && ((w->r != nullptr) && (w->r->c == 1))) {
				if (w != nullptr) {
					w->c = 0;
				}
				v = v->pr;
			}
			else {
				if ((w->r == nullptr) ||(w->r->c == 1)){
					if (w->l != nullptr) {
						w->l->c = 1;
					}
					if (w != nullptr) {
						w->c = 0;
					}
					rotater(v->pr);
					w = v->pr->r;
				}
				if (w != nullptr) {
					w->c = v->pr->c;
				}
				v->pr->c = 1;
				if (w->r != nullptr) {
					w->r->c = 1;
				}
				rotatel(v->pr);
				break;
			}
		}
		else {
			if (v->pr->l != nullptr) {
				nd* w = v->pr->l;
				if (w->c == 0) {
					w->c = 1;
					v->pr->c = 0;
					rotater(v->pr);
					w = v->pr->l;
				}
				if ((w->l != nullptr) && (w->r != nullptr) && (w->l->c == 1) && (w->r->c == 1)) {
					w->c = 0;
					v = v->pr;
				}
				else {
					if ((w->l == nullptr) || (w->l->c == 1)) {
						if (w->r != nullptr) {
							w->r->c = 1;
						}
						if (w != nullptr) {
							w->c = 0;
						}
						rotatel(v->pr);
						w = v->pr->l;
					}
					if (w != nullptr) {
						w->c = v->pr->c;
					}
					v->pr->c = 1;
					if (w->l != nullptr) {
						w->l->c = 1;
					}
					rotater(v->pr);
					break;
				}
			}
		}
	}
	if (r != nullptr) {
		r->c = 1;
	}
}

void rbtree::pop(polinom& p) {
	nd* v = nullptr;
	if (r == nullptr) {
		return;
	}
	else {
		nd* q = r;
		while (q != nullptr) {
			if (p < *q->t) {
				q = q->l;
			}
			else {
				if (p == *q->t) {
					v = q;
					break;
				}
				else {
					q = q->r;
				}
			}
		}
	}
	if (v == nullptr) {
		return;
	}
	nd* w = nullptr;
	nd* q = nullptr;
	bool f = v->c;

	if (v->l == nullptr) {
		w = v->r;
		if (v->pr == nullptr) {
			r = v->r;
		}
		else {
			if (v == v->pr->l) {
				v->pr->l = v->r;
			}
			else {
				v->pr->r = v->r;
			}
		}
		if (v->r != nullptr) {
			v->r->pr = v->pr;
		}
	}
	else {
		if (v->r == nullptr) {
			w = v->l;
			if (v->pr == nullptr) {
				r = v->l;
			}
			else {
				if (v == v->pr->l) {
					v->pr->l = v->l;
				}
				else {
					v->pr->r = v->l;
				}
			}
			if (v->l != nullptr) {
				v->l->pr = v->pr;
			}
		}
		else {
			q = v->r;
			while (q->l != nullptr) {
				q = q->l;
			}
			f = q->c;
			w = q->r;
			if (q->pr != v) {
				if (q->pr->l == q) { 
					q->pr->l = q->r;
				}
				else {
					q->pr->r = q->r;
				}
				if (q->r != nullptr) { 
					q->r->pr = q->pr; 
				}
				q->r = v->r;
				q->r->pr = q;
			}
			if (v->pr == nullptr) { 
				r = q;
			}
			else {
				if (v == v->pr->l) { 
					v->pr->l = q; 
				}
				else { 
					v->pr->r = q; 
				}
			}

			q->pr = v->pr;
			q->l = v->l;
			q->l->pr = q;
			q->c = v->c;
		}
	}
	if (f == 1) {
		balance_pop(w);
	}
	delete v;
}

bool rbtree::find(polinom& p) {
	if (r == nullptr) {
		return 0;
	}
	else {
		nd* q = r;
		while (q != nullptr) {
			if (p < *q->t) {
				q = q->l;
			}
			else {
				if (p == *q->t) {
					return 1;
				}
				else {
					q = q->r;
				}
			}
		}
		return 0;
	}
}

std::ostream& operator <<(std::ostream& out, const rbtree& a) {
	Stack<nd*> q;
	if (a.r != nullptr) {
		nd* w;
		q.Push(a.r);
		while (!q.IsEmpty()) {
			w = q.Pop();
			if (w->l != nullptr) {
				q.Push(w->l);
			}
			if (w->r != nullptr) {
				q.Push(w->r);
			}
			out << *w->t << " ";
		}
	}
	return out;
}
