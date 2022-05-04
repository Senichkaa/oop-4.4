//Pair.cpp
#include "Pair.h"

Pair::Pair()
	:a(0),b(0)
{
}

Pair::Pair(double a, double b)
	: a(a), b(b)
{
}

Pair::Pair(const Pair& v)
	: a(v.a), b(v.b)
{
}
