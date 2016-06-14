#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

#include <iostream>

class Rational
{
public:

    Rational(int32_t __numerator, int32_t __denominator = 1);
    Rational(const Rational& __rhs);
    ~Rational();

    int32_t numerator()   const { return _numerator; };
    int32_t denominator() const { return _denominator; };

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

    int32_t _numerator;
    int32_t _denominator;

    void reduce();
    int32_t gcd(int32_t a, int32_t b);
    int32_t sgn();
};

Rational& operator+ (const Rational& __r1, const Rational& __r2);
Rational& operator- (const Rational& __r1, const Rational& __r2);
Rational& operator* (const Rational& __r1, const Rational& __r2);
Rational& operator/ (const Rational& __r1, const Rational& __r2);

std::ostream& operator<< (std::ostream& __os, Rational& __r);

#endif
