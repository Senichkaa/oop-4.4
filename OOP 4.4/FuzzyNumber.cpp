//FuzzyNumber.cpp
#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	:Pair(),x(0)
{
}

FuzzyNumber::FuzzyNumber(double a, double b, double x)
{
	if (x > (x - a) && (x + b) > x)
	{
		set_a(a);
		set_b(b); 
		set_x(x);
	}
	else
	{
		set_a(0);
		set_b(0);
		set_x(0);
	}
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	:Pair(v),x(v.x)
{
}

FuzzyNumber FuzzyNumber::operator=(const FuzzyNumber& r)
{
	this->set_a(r.get_a());
	this->set_b(r.get_b());
	return this;
}

FuzzyNumber FuzzyNumber::operator+(const FuzzyNumber& F)
{
	this->set_x(get_x() + F.get_x());
	this->set_a(get_x() + F.get_x() - get_a() - F.get_a());
	this->set_b(get_x() + F.get_x() + get_b() + F.get_b());
	return this;
}

FuzzyNumber FuzzyNumber::operator-(const FuzzyNumber& F)
{
	this->set_x(get_x() - F.get_x());
	this->set_a(get_x() - F.get_x() - get_a() - F.get_a());
	this->set_b(get_x() - F.get_x() + get_b() + F.get_b());
	return this;
}

FuzzyNumber FuzzyNumber::operator*(const FuzzyNumber& F)
{
	this->set_x(get_x() * F.get_x());
	this->set_a(get_x() * F.get_x() - F.get_x() * get_a() - get_x()
		* F.get_a() - get_a() * F.get_a());
	this->set_b(get_x() * F.get_x() + F.get_x() * get_b() + get_x()
		* F.get_b() + get_b() * F.get_b());
	return this;
}

FuzzyNumber FuzzyNumber::operator/(const FuzzyNumber& F)
{
	if (F.get_x() > 0 && (F.get_x() + F.get_b()) > 0 
		&& (F.get_x() - F.get_a()) > 0)
	{
		this->set_x(get_x() / F.get_x());
		this->set_a((get_x() - get_a()) / (F.get_x() + F.get_b()));
		this->set_b((get_x() + get_b()) / (F.get_x() - F.get_a()));
	}
	else
	{
		cout << "FuzzyNumbers can not be divided" << endl;
	}
	return this;
}

ostream& FuzzyNumber::Print(ostream& out) const
{
	out << "(" << get_a() << ";" << x << ";" << get_b() << ")" << endl;
	return out;
}

istream& FuzzyNumber::Insert(istream& in)
{
	double x;
	double l;
	double r;
	do
	{
		cout << "x: "; in >> x;
		cout << "l: "; in >> l;
		cout << "r: "; in >> r;
	} while (!(x>(x-1)&&(x+r)>x));
	this->set_x(x);
	this->set_a(l);
	this->set_b(r);
	return in;
}

FuzzyNumber operator/(int a, const FuzzyNumber& F)
{
	FuzzyNumber& T(0, 0, 0);
	T.set_x(a / F.get_x());
	T.set_a(a / (F.get_x() + F.get_a()));
	T.set_b(a / (F.get_x() - F.get_b()));
	return T;
}
