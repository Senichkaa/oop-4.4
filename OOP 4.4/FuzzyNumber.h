//FuzzyNumber.h
// 5 4
// 6 2 9
#pragma once
#include "Pair.h"
class FuzzyNumber:public Pair
{
private:
	double x;
public:
	FuzzyNumber();
	FuzzyNumber(double a,double b,double x);
	FuzzyNumber(const FuzzyNumber& v);

	double get_x() const { return x; }
	void set_x(double value) { x = value; }

	virtual FuzzyNumber operator = (const FuzzyNumber& r);
	virtual FuzzyNumber operator + (const FuzzyNumber& F);
	virtual FuzzyNumber operator - (const FuzzyNumber& F);
	virtual FuzzyNumber operator * (const FuzzyNumber& F);
	virtual FuzzyNumber operator / (const FuzzyNumber& F);

	friend FuzzyNumber operator / (int a, const FuzzyNumber& F);

	virtual ostream& Print(ostream& out) const override;
	virtual istream& Insert(istream& in) override;


};

