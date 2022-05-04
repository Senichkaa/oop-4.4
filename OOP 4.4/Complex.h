//Complex.h
#pragma once
#include "Pair.h"
class Complex :public Pair
{
public:
	Complex();
	Complex(double x,double y);
	Complex(const Complex& v);

	Complex& Conj(); 
	virtual Complex operator = (const Complex& r);
	virtual Complex operator + (const Complex& F);
	virtual Complex operator - (const Complex& F);
	virtual Complex operator * (const Complex& F);
	virtual Complex operator / (const Complex& F);
	virtual bool operator == (const Complex& F);

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};

