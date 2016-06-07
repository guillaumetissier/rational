#ifndef __PHP_RATIONAL_HPP__
#define __PHP_RATIONAL_HPP__

#include <phpcpp.h>
#include <Rational.hpp>

class PhpRational : public Php::Base
{
public:

    PhpRational() = default;
    ~PhpRational() = default;

    void __construct(Php::Parameters &params);

private:
    Rational& _rational;
};
#endif
