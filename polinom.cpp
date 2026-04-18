// polinom from lab4 polinom
#include"polinom.h"
polinom::polinom(std::string& s) : p{} {
	int q = 0;
	int k = 1;
	int k_1 = 0;
	int k_2 = 0;
	int l_2 = 0;
	int p_x = 0;
	int p_y = 0;
	int p_z = 0;
	double k_3 = 0;
	char c;
	for (auto it = s.begin(); it != s.end(); it++) {
		c = *it;
		node a{};
		if (c != ' ') {
			switch (q) {
			case 0:
				switch (c) {
				case '-':
					q = 1;
					k = -1;
					break;

				case 'x':
					p_x = 1;
					q = 5;
					k_3 = 1;
					break;
				case 'y':
					q = 8;
					p_y = 1;
					k_3 = 1;
					break;
				case 'z':
					q = 11;
					p_z = 1;
					k_3 = 1;
					break;
				case '0':
					q = 4;
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 2;
					k_1 = k_1 * 10 + int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;

			case 1:
				switch (c) {
				case 'x':
					q = 5;
					k_3 = k;
					p_x = 1;
					break;
				case 'y':
					q = 8;
					k_3 = k;
					p_y = 1;
					break;
				case 'z':
					q = 11;
					p_z = 1;
					k_3 = k;
					break;
				case '0':
					q = 4;
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 2;
					k_1 = k_1 * 10 + int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;

			case 2: {
				node a(0, 0, 0, k * k_1, nullptr);
				switch (c) {
				case 'x':
					q = 5;
					k_3 = k * k_1;
					p_x = 1;
					break;
				case 'y':
					p_y = 1;
					q = 8;
					k_3 = k * k_1;
					break;
				case 'z':
					p_z = 1;
					q = 11;
					k_3 = k * k_1;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 2;
					k_1 = k_1 * 10 + int(c) - int('0');
					break;
				case '.':
					q = 3;
					break;
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 3:
				switch (c) {
				case 'x':
					q = 5;
					p_x = 1;
					k_3 = k * (k_1 + (double)k_2 / pow(10, l_2));
					break;
				case 'y':
					q = 8;
					p_y = 1;
					k_3 = k * (k_1 + (double)k_2 / pow(10, l_2));
					break;
				case 'z':
					q = 11;
					p_z = 1;
					k_3 = k * (k_1 + (double)k_2 / pow(10, l_2));
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 3;
					k_2 = k_2 * 10 + int(c) - int('0');
					l_2 += 1;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;

			case 4:
				switch (c) {
				case '.':
					q = 3;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;

			case 5: {
				node a(p_x, p_y, p_z, k_3);
				switch (c) {
				case 'y':
					p_y = 1;
					q = 8;
					break;
				case 'z':
					p_z = 1;
					q = 11;
					break;
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '^':
					q = 6;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 7;
					p_x = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 6: {
				switch (c) {
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 7;
					p_x = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 8: {
				node a(p_x, p_y, p_z, k_3);
				switch (c) {
				case 'z':
					p_z = 1;
					q = 11;
					break;
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '^':
					q = 9;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 10;
					p_y = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 9: {
				switch (c) {
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 10;
					p_y = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 11: {
				node a(p_x, p_y, p_z, k_3);
				switch (c) {
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '^':
					q = 12;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 13;
					p_z = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 12: {
				switch (c) {
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					q = 13;
					p_z = int(c) - int('0');
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 7: {
				node a(p_x, p_y, p_z, k_3);
				switch (c) {
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case 'y':
					p_y = 1;
					q = 8;
					break;
				case 'z':
					p_z = 1;
					q = 11;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 10: {
				node a(p_x, p_y, p_z, k_3);
				switch (c) {
				case '+':
					q = 1;
					p.push(a);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(a);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case 'z':
					q = 11;
					p_z = 1;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}

			case 13: {
				node aaa(p_x, p_y, p_z, k_3);
				switch (c) {
				case '+':
					q = 1;
					p.push(aaa);
					k = 1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case '-':
					q = 1;
					p.push(aaa);
					k = -1;
					k_1 = 0;
					k_2 = 0;
					l_2 = 0;
					p_x = 0;
					p_y = 0;
					p_z = 0;
					k_3 = 0;
					break;
				case 'y':
					q = 8;
					break;
				case 'z':
					q = 11;
					break;
				default:
					std::string M = "Invalid input ";
					M.push_back(c);
					throw std::invalid_argument(M);
				}
				break;
			}
			default:
				std::string M = "Invalid input ";
				M.push_back(c);
				throw std::invalid_argument(M);
			}
		}
	}
	if ((c == '+') || (c == '-')) {
		std::string M = "Invalid input ";
		M.push_back(c);
		throw std::invalid_argument(M);
	}
	if (k_3 != 0) {
		node a(p_x, p_y, p_z, k_3);
		p.push(a);
		k_2 = 0;
		k_1 = 0;
	}
	if (k_2 != 0) {
		node a(p_x, p_y, p_z, k * (k_1 + ((double)k_2) / pow(10, l_2)));
		p.push(a);
		k_2 = 0;
		k_1 = 0;
	}
	if (k_1 != 0) {
		node a(p_x, p_y, p_z, k * k_1);
		p.push(a);
	}
}

polinom::polinom(list& q) { p = q; };

polinom::polinom() : p{} {};

polinom polinom::operator +(const polinom& a) {
	polinom q;
	q.p = p;
	node* t = a.p.next;
	while (t != nullptr) {
		q.p.push(*t);
		t = t->next;
	}
	return q;
}

polinom polinom::operator -(const polinom& a) {
	polinom c;
	c.p = a.p;
	c = c * (-1);
	c = c + polinom(p);
	return c;
}

polinom polinom::operator *(const polinom& a) {
	polinom q;
	node* t = a.p.next;
	while (t != nullptr) {
		node* l = this->p.next;
		while (l != nullptr) {
			q.p.push(node(l->t, l->k, nullptr) * node(t->t, t->k, nullptr));
			l = l->next;
		}
		t = t->next;
	}
	return q;
}

polinom polinom::operator *(const double a) {
	polinom q;
	if (a != 0) {
		q.p = p;
		node* t = q.p.next;
		while (t != nullptr) {
			t->k *= a;
			t = t->next;
		}
		return q;
	}
	return q;
}

polinom::~polinom() {}

std::ostream& operator <<(std::ostream& out, const polinom& a) {
	out << a.p;
	return out;
};

bool polinom::operator==(const polinom& a) {
	node* q = this->p.next;
	node* r = a.p.next;
	while ((q != nullptr) && (r != nullptr)) {
		if (!(*q == *r)) {
			return 0;
		}
		q = q->next;
		r = r->next;
	}
	if ((q != nullptr) || (r != nullptr)) {
		return 0;
	}
	return 1;
}

bool polinom::operator > (const polinom& a) {
	if (p.CheckSize() == 0) { return 0; }
	if (a.p.CheckSize() == 0) { return 1; }
	node* q1 = this->p.next;
	node* q2 = a.p.next;
	int i = 0;
	for (; i < std::min(a.p.CheckSize(), this->p.CheckSize()); i++) {
		if (*q1 > *q2) {
			return 1;
		}
		if (*q1 < *q2) {
			return 0;
		}
		q1 = q1->next;
		q2 = q2->next;
	}
	if (i < this->p.CheckSize()) {
		return 1;
	}
	return 0;
}

bool polinom::operator <(const polinom& a) {
	if (!(*this > a) && !(*this == a)) {
		return 1;
	}
	else {
		return 0;
	}
}

