#include <string> 
#include <phpcpp.h>
#include <PhpRational.hpp>

void PhpRational::__construct(Php::Parameters &__params)
{
    _numerator   = (int32_t)__params[0];
    _denominator = __params.size() > 1 ? (int32_t)__params[1] : 1;
    reduce();
}

Php::Value PhpRational::__toString()
{
    return toString();
}

int PhpRational::__compare(const PhpRational &that) const
{
	return _numerator * that._denominator - _denominator * that._numerator;
}

void PhpRational::print() const
{
	Php::out << toString() << std::endl;
}

Php::Value PhpRational::operator+=(Php::Parameters &__params)
{
    PhpRational *pRhs = (PhpRational *)__params[0].implementation();
    _numerator   = _numerator * pRhs->_denominator + _denominator * pRhs->_numerator;
    _denominator = _denominator * pRhs->_denominator;
    reduce();
    return this;
}

Php::Value PhpRational::operator-=(Php::Parameters &__params)
{
    PhpRational *pRhs = (PhpRational *)__params[0].implementation();
    _numerator   = _numerator * pRhs->_denominator - _denominator * pRhs->_numerator;
    _denominator = _denominator * pRhs->_denominator;
    reduce();
    return this;
}

Php::Value PhpRational::operator*= (Php::Parameters &__params)
{
	PhpRational *pRhs = (PhpRational *)__params[0].implementation();
    _numerator   = _numerator * pRhs->_numerator;
    _denominator = _denominator * pRhs->_denominator;
    reduce();
    return this;
}

Php::Value PhpRational::operator/= (Php::Parameters &__params)
{
	PhpRational *pRhs = (PhpRational *)__params[0].implementation();
    _numerator   = _numerator * pRhs->_denominator;
    _denominator = _denominator * pRhs->_numerator;
    reduce();
    return this;
}

std::string PhpRational::toString() const
{
	std::string myString = std::to_string(_numerator);
    if (_denominator != 1) {
        myString += "/" + std::to_string(_denominator);
    }
    return myString;
}

void PhpRational::reduce()
{
    if (_denominator == 0) {
        throw Php::Exception("Divide by zero exception");
    }
    
    int32_t theGcd = gcd(_numerator, _denominator);
    _numerator     = std::abs(_numerator / theGcd) * sgn();
    _denominator   = std::abs(_denominator / theGcd);
}

int32_t PhpRational::gcd(int32_t a, int32_t b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int32_t PhpRational::sgn()
{
    return _numerator * _denominator / std::abs(_numerator * _denominator);
}