#include"mas.h"
#include <gtest/gtest.h>

TEST(mas, can_create_mas)
{
	ASSERT_NO_THROW(mas(100));
}

TEST(mas, can_add_to_mas)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	ASSERT_NO_THROW(m.add(p));
}

TEST(mas, can_add_to_mas1)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_NO_THROW(m.add(q));
}

TEST(mas, can_find_in_mas)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_EQ(m.find(p), 1);
}

TEST(mas, can_find_in_mas1)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_EQ(m.find(q), 0);
}

TEST(mas, can_find_in_mas2)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	ASSERT_EQ(m.find(q), 1);
}

TEST(mas, can_pop_in_mas)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_NO_THROW(m.pop(p));
	ASSERT_EQ(m.find(p), 0);
}

TEST(mas, can_pop_in_mas1)
{
	mas m(100);
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

TEST(mas, can_pop_in_mas2)
{
	mas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	m.pop(p);
	ASSERT_NO_THROW(m.pop(p));
}