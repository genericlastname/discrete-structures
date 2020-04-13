#ifndef __FRACTION_H__
#define __FRACTION_H__

struct Fraction {
		int num;
		int denom;
};

Fraction create(int n, int d);
void add(Fraction f1, Fraction f2);
void display(Fraction f);
#endif
