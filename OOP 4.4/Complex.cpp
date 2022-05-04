//Complex.cpp
#include "Complex.h"

Complex::Complex()
	:Pair()
{
}

Complex::Complex(double x, double y)
	:Pair(x,y)
{
}

Complex::Complex(const Complex& v)
	:Pair(v)
{
}

Complex& Complex::Conj() //комплексно спряжене число
{
	this->set_b(-this->get_b());
	return *this;
}

Complex Complex::operator=(const Complex& r)
{
	this->set_a(r.get_a());
	this->set_b(r.get_b());
	return this;
}

Complex Complex::operator+(const Complex& F)
{
	set_a(this->get_a() + (F.get_a()));
	set_b(this->get_b() + (F.get_b()));
	return *this;
}

Complex Complex::operator-(const Complex& F)
{
	set_a(this->get_a() - (F.get_a()));
	set_b(this->get_b() - (F.get_b()));
	return *this;
}

Complex Complex::operator*(const Complex& F)
{
	set_a(this->get_a() * (F.get_a() - get_b() * (F.get_b())));
	set_b(this->get_b() * (F.get_b() + (F.get_a() * get_b())));
	return *this;
}

Complex Complex::operator/(const Complex& F)
{
	set_a((this->get_a() * F.get_a() + get_b() * F.get_b()) /
		((F.get_a() * F.get_a() + F.get_b() * F.get_b())));
	set_b(((F.get_a() * this->get_b() - get_a() * F.get_b()) /
		(F.get_a() * F.get_a() + F.get_b() * F.get_b())));
	return *this;
}

bool Complex::operator==(const Complex& F)
{
	return this->get_a() == F.get_a() && get_b() == F.get_b();
}

ostream& Complex::Print(ostream& out) const
{
	out << get_a() << "+i*" << get_b() << endl;
	return out;
}

istream& Complex::Insert(istream& in)
{
	double x, y;
	cout << "x: "; in >> x;
	cout << "y: "; in >> y;
	this->set_a(x);
	this->set_b(y);
	return in;
}
