#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class Rational
{

public:
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational& r);

	Rational operator+(Rational& r);
	Rational operator-(Rational& r);
	Rational operator*(Rational& r);
	Rational operator/(Rational& r);

	Rational power(int p);

	friend bool operator==(Rational& r1, Rational& r2);
	friend bool operator!=(Rational& r1, Rational& r2);
	friend bool operator<(Rational& r1, Rational& r2);
	friend bool operator>(Rational& r1, Rational& r2);
	friend bool operator<=(Rational& r1, Rational& r2);
	friend bool operator>=(Rational& r1, Rational& r2);

	friend std::ostream& operator<<(std::ostream& output, const Rational& r);
	friend std::istream& operator>>(std::istream& input, Rational& r);

	void shorten();

	int getnumerator();
	int getdenominator();

	void setnumerator(int value);
	void setdenominator(int value);

private:
	int numerator;
	int denominator;

	void swap();
	static int gcd(int x, int y);
};

#endif