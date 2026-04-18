//test of new class features

#include"polinom.h"
#include <gtest/gtest.h>

TEST(polinom, can_compare_polinom1)
{
	std::string a("x^2+3");
	polinom p(a);
	std::string b("3 + x^2");
	polinom q(b);
	ASSERT_EQ(p==q, 1);
}

TEST(polinom, can_compare_polinom2)
{
	std::string a("x^2+3");
	polinom p(a);
	std::string b("4 + x^2");
	polinom q(b);
	ASSERT_EQ(p == q, 0);
}

TEST(polinom, can_compare_polinom3)
{
	std::string a("x^2+3+132.2xyz3");
	polinom p(a);
	std::string b("3 + x^2+132.2xyz3");
	polinom q(b);
	ASSERT_EQ(p == q, 1);
}


TEST(polinom, can_compare_polinom4)
{
	std::string a("4xyz3");
	polinom p(a);
	std::string b("56xyz3");
	polinom q(b);
	ASSERT_EQ(p < q, 1);
}

TEST(polinom, can_compare_polinom5)
{
	std::string a("6xyz3");
	polinom p(a);
	std::string b("56xyz3");
	polinom q(b);
	ASSERT_EQ(p > q, 0);
}


TEST(polinom, can_compare_polinom6)
{
	std::string a("8xy-4xyz3");
	polinom p(a);
	std::string b("56xyz3");
	polinom q(b);
	ASSERT_EQ(p < q, 1);
}

TEST(randpolinom, can_create_randpolinom)
{
	ASSERT_NO_THROW(randpolinom m{});
}

TEST(randpolinom, can_create_randpolinom1)
{
	randpolinom m{};
	for (int i = 0; i < 100; i++) {
		ASSERT_NO_THROW(m.getrandpolinom());
	}
}