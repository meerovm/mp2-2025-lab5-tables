#include"umas.h"
#include <gtest/gtest.h>

TEST(umas, can_create_umas)
{
	ASSERT_NO_THROW(umas(100));
}

TEST(umas, can_add_to_umas)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	ASSERT_NO_THROW(m.add(p));
}

TEST(umas, can_add_to_umas1)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_NO_THROW(m.add(q));
}

TEST(umas, can_find_in_umas)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_EQ(m.find(p), 1);
}

TEST(umas, can_find_in_umas1)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_EQ(m.find(q), 0);
}

TEST(umas, can_find_in_umas2)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	ASSERT_EQ(m.find(q), 1);
}

TEST(umas, can_pop_in_umas)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_NO_THROW(m.pop(p));
	ASSERT_EQ(m.find(p), 0);
}

TEST(umas, can_pop_in_umas1)
{
	umas m(100);
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

TEST(umas, can_pop_in_umas2)
{
	umas m(100);
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	m.pop(p);
	ASSERT_NO_THROW(m.pop(p));
}