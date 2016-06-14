#ifndef __PHP_RATIONAL_HPP__
#define __PHP_RATIONAL_HPP__

#include <phpcpp.h>
#include <Rational.hpp>

class PhpRational : public Php::Base
{
public:

    PhpRational()  = default;
    ~PhpRational() = default;

    void       __construct(Php::Parameters &params);
    Php::Value __toString();
    int        __compare(const PhpRational &that) const;

    Php::Value operator+=(Php::Parameters &params);
    Php::Value operator-=(Php::Parameters &params);
    Php::Value operator*=(Php::Parameters &params);
    Php::Value operator/=(Php::Parameters &params);
	
	void print() const;
    
private:

    std::string toString() const;
    void    reduce();
    int32_t gcd(int32_t a, int32_t b);
    int32_t sgn();

    int32_t _numerator;
    int32_t _denominator;
};
#endif
