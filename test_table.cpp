#include"table.h"
#include <gtest/gtest.h>

TEST(table, can_create_table)
{
	ASSERT_NO_THROW(table(100));
}

TEST(table, can_add_to_table)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	ASSERT_NO_THROW(m.add(p));
}

TEST(table, can_add_to_table1)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_NO_THROW(m.add(q));
}

TEST(table, can_find_in_table)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_EQ(m.find(p), 1);
}

TEST(table, can_find_in_table1)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_EQ(m.find(q), 0);
}

TEST(table, can_find_in_table2)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	ASSERT_EQ(m.find(q), 1);
}

TEST(table, can_pop_in_table)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_NO_THROW(m.pop(p));
	ASSERT_EQ(m.find(p), 0);
}

TEST(table, can_pop_in_table1)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	m.pop(p);
	m.add(p);
	m.pop(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	m.pop(q);
	m.add(p);
	m.add(q);
	m.pop(p);
	ASSERT_EQ(m.find(q), 1);
	ASSERT_EQ(m.find(p), 0);
}

TEST(table, can_pop_in_table2)
{
	table m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	m.pop(p);
	ASSERT_NO_THROW(m.pop(p));
}