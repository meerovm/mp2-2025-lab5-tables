#ifndef _mas
#include "mas.h"
#define _mas
#endif

#ifndef _table
#include "table.h"
#define _table
#endif

#ifndef _tree
#include "tree.h"
#define _tree
#endif

#ifndef _umas
#include "umas.h"
#define _umas
#endif

#ifndef _str
#include "string"
#define _str
#endif

#include <chrono>
#include <vector> 
#include <iostream> 



int main() {
	std::vector<polinom> v;
	int l = 1000000;
	umas u(l);
	//mas m(l);
	table tab(l);
	rbtree tr{};
	randpolinom rd;
	polinom p;
	for (int i = 0; i < l / 10; i++) {
		p = rd.getrandpolinom();
		u.add(p);
		//m.add(p);
		tab.add(p);
		tr.add(p);
		v.push_back(p);
	}
	std::mt19937 gen(222);
	std::shuffle(v.begin(), v.end(), gen);

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		u.pop(v[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> pop_umas_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 500; i++) {
	//	m.pop(v[i]);
	//}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> pop_mas_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		tr.pop(v[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> pop_rbtree_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		tab.pop(v[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> pop_table_time = (end - start);
	std::cout << "time to 500 pop in when size of structure 1000000 and 1/10size element" << std::endl;
	std::cout << "mas: " << pop_mas_time.count() << "umas: " << pop_umas_time.count() << "table: " << pop_table_time.count() << "tree: " << pop_rbtree_time.count() << std::endl;


	std::shuffle(v.begin(), v.end(), gen);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		u.add(v[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> add_umas_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 500; i++) {
	//	m.add(v[i]);
	//}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> add_mas_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		tr.add(v[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> add_rbtree_time = (end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) {
		tab.add(v[i]);
	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> add_table_time = (end - start);
	std::cout << "time to 500 add in when size of structure 1000000 and 1/10size element" << std::endl;
	std::cout << "mas: " << add_mas_time.count() << "umas: " << add_umas_time.count() << "table: " << add_table_time.count() << "tree: " << add_rbtree_time.count() << std::endl;
}


//results:
//time to 50 pop in when size of structure 100000 and 1 / 10size element
//mas : 38.9647 umas : 0.206 table : 0.0079 tree : 0.0298
//time to 50 add in when size of structure 100000 and 1 / 10size element
//mas : 34.6138 umas : 0.2111 table : 0.0179 tree : 0.0534

//results2 with short polynom (0-2 monomials). operator > / operator < work limited time
//time to 500 pop in when size of structure 1000000 and 1 / 10size element
//umas : 21.2259 table : 0.1109 tree : 0.5211
//time to 500 add in when size of structure 1000000 and 1 / 10size element
//umas : 25.6303 table : 0.1695 tree : 0.8719

//results3 with long polynom (0-30 monomials). operator > / operator < work long time
//time to 500 pop in when size of structure 1000000 and 1 / 10size element
//umas : 188.993 table : 0.3383 tree : 1.2322
//time to 500 add in when size of structure 1000000 and 1 / 10size element
//umas : 189.494 table : 0.3396 tree : 1.6175