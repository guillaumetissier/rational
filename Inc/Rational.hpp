#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

#include <iostream>
#include "types.hpp"

class Rational
{
public:

    Rational(s32 __numerator, s32 __denominator = 1);
    Rational(const Rational& r)
    ~Rational();

    void operator=  (const Rational& __rhs);
    void operator+= (const Rational& __rhs);
    void operator-= (const Rational& __rhs);
    void operator*= (const Rational& __rhs);
    void operator/= (const Rational& __rhs);

    Rational& operator+ (const Rational& __rhs) const;
    Rational& operator- (const Rational& __rhs) const;
    Rational& operator* (const Rational& __rhs) const;
    Rational& operator/ (const Rational& __rhs) const;

    bool operator== (const Rational& __rhs) const;
    bool operator!= (const Rational& __rhs) const;
    bool operator<= (const Rational& __rhs) const;
    bool operator<  (const Rational& __rhs) const;
    bool operator>= (const Rational& __rhs) const;
    bool operator>  (const Rational& __rhs) const;

private:

    s32 _num;
    s32 _den;

    void reduce();
    s32 gcd(s32 a, s32 b);
    s32 sgn();
};

Rational& operator+ (const Rational& __r1, const Rational& __r2);
Rational& operator- (const Rational& __r1, const Rational& __r2);
Rational& operator* (const Rational& __r1, const Rational& __r2);
Rational& operator/ (const Rational& __r1, const Rational& __r2);

std::istream& operator>> (std::istream& __is, Rational& __r);

#endif