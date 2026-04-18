#include"tree.h"
#include <gtest/gtest.h>

// tests 
TEST(rbtree, can_create_rbtree)
{
	ASSERT_NO_THROW(rbtree{});
}

TEST(rbtree, can_add_to_rbtree)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	ASSERT_NO_THROW(m.add(p));
}

TEST(rbtree, can_add_to_rbtree1)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_NO_THROW(m.add(q));
}

TEST(rbtree, can_find_in_rbtree)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_EQ(m.find(p), 1);
}

TEST(rbtree, can_find_in_rbtree1)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	ASSERT_EQ(m.find(q), 0);
}

TEST(rbtree, can_find_in_rbtree2)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	ASSERT_EQ(m.find(q), 1);
}

TEST(rbtree, can_pop_in_rbtree)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	ASSERT_NO_THROW(m.pop(p));
	ASSERT_EQ(m.find(p), 0);
}

TEST(rbtree, can_pop_in_rbtree1)
{
	rbtree m{};
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

TEST(rbtree, can_pop_in_rbtree2)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	m.pop(p);
	ASSERT_NO_THROW(m.pop(p));
}

TEST(rbtree, can_pop_in_rbtree3)
{
	rbtree m{};
	std::string a("x^2+3");
	polinom p(a);
	m.add(p);
	std::string b("x^2+4");
	polinom q(b);
	m.add(q);
	std::string c("x^2+5");
	polinom r(c);
	m.add(r);
	ASSERT_EQ(m.find(r), 1);
	m.pop(r);
	ASSERT_EQ(m.find(r), 0);
}