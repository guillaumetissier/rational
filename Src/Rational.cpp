#include "Rational.hpp"
#include <math>

Rational::Rational(s32 __numerator, s32 __denominator = 1)
{
    _numerator {__numerator};
    _denominator {__denominator};
    reduce();
}

Rational::Rational(const Rational& __rhs)
{
    _numerator {__rhs._numerator};
    _denominator {__rhs._denominator};
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
    Rational result = *this;
    result += __rhs;
    return result;
}

Rational& Rational::operator- (const Rational& __rhs) const
{
    Rational result = *this;
    result -= __rhs;
    return result;
}

Rational& Rational::operator* (const Rational& __rhs) const
{
    Rational result = *this;
    result *= __rhs;
    return result;
}

Rational& Rational::operator/ (const Rational& __rhs) const
{
    Rational result = *this;
    result /= __rhs;
    return result;
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

bool Rational::operator<  (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator < _denominator * __rhs._numerator); 
}

bool Rational::operator>= (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator >= _denominator * __rhs._numerator);
}

bool Rational::operator>  (const Rational& __rhs) const
{
    return (_numerator * __rhs._denominator > _denominator * __rhs._numerator);
}

void Rational::reduce()
{
    if (_denominator == 0) {
        throw Php::Exception("Division by zero");
    }
    
    s32 theGcd   = gcd(_numerator, _denominator);
    _numerator   = abs(_numerator / theGcd) * sgn();
    _denominator = abs(_denominator / theGcd);
}

s32 Rational::gcd (s32 a, s32 b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

s32 Rational::sgn ()
{
    return _numerator * _denominator / abs(_numerator * _denominator);
}

Rational& operator+ (const Rational& __r1, const Rational& __r2)
{
    return __r1 + __r2;
}

Rational& operator- (const Rational& __r1, const Rational& __r2)
{
    return __r1 - __r2;
}

Rational& operator* (const Rational& __r1, const Rational& __r2)
{
    return __r1 * __r2;
}

Rational& operator/ (const Rational& __r1, const Rational& __r2)
{
    return __r1 / __r2;
}

std::ostream& operator<< (std::ostream & out, const Rational & r) {
    out << __rhs._numerator;
    if (__rhs._denominator != 1) {
        out << '/' << __rhs._denominator;
    }
    return out;
}