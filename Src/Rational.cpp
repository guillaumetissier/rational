#include "Rational.hpp"
#include <cmath>

Rational::Rational(int32_t __numerator, int32_t __denominator)
{
    _numerator   = __numerator;
    _denominator = __denominator;
    reduce();
}

Rational::Rational(const Rational& __rhs)
{
    _numerator   = __rhs._numerator;
    _denominator = __rhs._denominator;
}

Rational::~Rational()
{
}

void Rational::operator= (const Rational& __rhs)
{
    _numerator   = __rhs._numerator;
    _denominator = __rhs._denominator;
}

void Rational::operator+= (const Rational& __rhs)
{
    _numerator   = _numerator * __rhs._denominator + _denominator * __rhs._numerator;
    _denominator = _denominator * __rhs._denominator;
    reduce();
}

void Rational::operator-= (const Rational& __rhs)
{
    _numerator   = _numerator * __rhs._denominator - _denominator * __rhs._numerator;
    _denominator = _denominator * __rhs._denominator;
    reduce();
}

void Rational::operator*= (const Rational& __rhs)
{
    _numerator   = _numerator * __rhs._numerator;
    _denominator = _denominator * __rhs._denominator;
    reduce();
}

void Rational::operator/= (const Rational& __rhs)
{
    _numerator   = _numerator * __rhs._denominator;
    _denominator = _denominator * __rhs._numerator;
    reduce();
}

Rational& Rational::operator+ (const Rational& __rhs) const
{
    Rational *pResult = new Rational(*this);
    *pResult += __rhs;
    return *pResult;
}

Rational& Rational::operator- (const Rational& __rhs) const
{
    Rational *pResult = new Rational(*this);
    *pResult -= __rhs;
    return *pResult;
}

Rational& Rational::operator* (const Rational& __rhs) const
{
    Rational *pResult = new Rational(*this);
    *pResult *= __rhs;
    return *pResult;
}

Rational& Rational::operator/ (const Rational& __rhs) const
{
    Rational *pResult = new Rational(*this);
    *pResult /= __rhs;
    return *pResult;
}

bool Rational::operator== (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator == _denominator * __rhs._numerator);
}

bool Rational::operator!= (const Rational& __rhs) const
{   
    return (_numerator * __rhs._denominator != _denominator * __rhs._numerator);
}

bool Rational::operator<= (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator <= _denominator * __rhs._numerator);    
}

bool Rational::operator< (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator < _denominator * __rhs._numerator); 
}

bool Rational::operator>= (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator >= _denominator * __rhs._numerator);
}

bool Rational::operator> (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator > _denominator * __rhs._numerator);
}

void Rational::reduce()
{
    if (_denominator == 0) {
        throw std::overflow_error("Divide by zero exception");
    }
    
    int32_t theGcd   = gcd(_numerator, _denominator);
    _numerator   = std::abs(_numerator / theGcd) * sgn();
    _denominator = std::abs(_denominator / theGcd);
}

int32_t Rational::gcd (int32_t a, int32_t b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int32_t Rational::sgn ()
{
    return _numerator * _denominator / std::abs(_numerator * _denominator);
}

Rational& operator+ (const Rational& __r1, const Rational& __r2)
{
    Rational *pRational = new Rational(__r1);
    *pRational += __r2;
    return *pRational;
}

Rational& operator- (const Rational& __r1, const Rational& __r2)
{
    Rational *pRational = new Rational(__r1);
    *pRational -= __r2;
    return *pRational;
}

Rational& operator* (const Rational& __r1, const Rational& __r2)
{
    Rational *pRational = new Rational(__r1);
    *pRational *= __r2;
    return *pRational;
}

Rational& operator/ (const Rational& __r1, const Rational& __r2)
{
    Rational *pRational = new Rational(__r1);
    *pRational /= __r2;
    return *pRational;
}

std::ostream& operator<< (std::ostream & out, const Rational & __rhs) {
    out << __rhs.numerator();
    if (__rhs.denominator() != 1) {
        out << '/' << __rhs.denominator();
    }
    return out;
}