#include "Rational.h"

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(const Rational& r) {
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}

Rational::Rational(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;

	shorten();
}

Rational Rational::operator+(Rational& r)
{
	int nww = (this->denominator * r.denominator) / gcd(this->denominator, r.denominator);
	int w1 = nww / this->denominator, w2 = nww / r.denominator;

	return  Rational(w1 * this->numerator + w2 * r.numerator, nww);
}

Rational Rational::operator-(Rational& r)
{
	int nww = (this->denominator * r.denominator) / gcd(this->denominator, r.denominator);
	int w1 = nww / this->denominator, w2 = nww / r.denominator;

	return Rational(w1 * this->numerator - w2 * r.numerator, nww);
}

Rational Rational::operator*(Rational& r)
{
	return Rational(this->numerator * r.numerator, this->denominator * r.denominator);
}

Rational Rational::operator/(Rational& r)
{
	return  Rational(this->numerator * r.denominator, this->denominator * r.numerator);
}

Rational Rational::power(int p)
{
	if (p < 0)
	{
		swap();
		return power(0 - p);
	}
	else
	{
		Rational result(*this);
		result.numerator = (int)pow(this->numerator, p);
		result.denominator = (int)pow(this->denominator, p);
		result.shorten();

		return result;
	}
}

inline int Rational::getnumerator()
{
	return this->numerator;
}

inline int Rational::getdenominator()
{
	return this->denominator;
}

inline void Rational::setnumerator(int value)
{
	this->numerator = value;
	shorten();
}

inline void Rational::setdenominator(int value)
{
	this->denominator = value;
	shorten();
}

int Rational::gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

void Rational::shorten() {

	if (this->denominator == 0)
		throw std::invalid_argument("denominator is 0");

	int _gcd = gcd(this->numerator, this->denominator);

	this->numerator /= _gcd;
	this->denominator /= _gcd;

	if (this->denominator < 0)
	{
		this->denominator = 0 - this->denominator;
		this->numerator = 0 - this->numerator;
	}
}

void Rational::swap()
{
	int temp = this->numerator;
	this->numerator = this->denominator;
	this->denominator = temp;
}

bool operator==(Rational& r1, Rational& r2)
{
	return (r1.denominator == r2.denominator) && (r1.numerator == r2.numerator);
}

bool operator!=(Rational& r1, Rational& r2)
{
	return (r1.denominator != r2.denominator) || (r1.numerator != r2.numerator);
}

bool operator>(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) > 0) return true;
	else return false;
}

bool operator<(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) < 0) return true;
	else return false;
}

bool operator>=(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) >= 0) return true;
	else return false;
}

bool operator<=(Rational& r1, Rational& r2)
{
	Rational x = r1 - r2;
	if (((double)x.getnumerator() / (double)x.getdenominator()) <= 0) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& output, const Rational& r) {
	output << r.numerator;

	if (r.denominator != 1)
		output << "|" << r.denominator;

	return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
	char separator;
	input >> r.numerator >> separator >> r.denominator;
	r.shorten();

	return input;
}