//Pair.h
#pragma once
#pragma pack(1)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Pair
{
private:
	double a;
	double b;
public:
	Pair();
	Pair(double a, double b);
	Pair(const Pair& v);

	double get_a() const { return a; }
	double get_b() const { return b; }

	void set_a(double value) { a = value; }
	void set_b(double value) { b = value; }

	virtual Pair operator = (const Pair& r) = 0;
	virtual Pair operator + (const Pair& F) = 0;
	virtual Pair operator - (const Pair& F) = 0;
	virtual Pair operator * (const Pair& F) = 0;
	virtual Pair operator / (const Pair& F) = 0;

	virtual ostream& Print(ostream& out) const = 0;
	virtual istream& Insert(istream& in) = 0;
};

