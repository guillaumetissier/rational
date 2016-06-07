#include "PhpRational.hpp"

void PhpRational::__construct(Php::Parameters &params)
{
    Php::Value denominator = params[0];
    Php::Value numerator   = params[1];
    _rational       = Rational(denominator, numerator);
}
