#include <phpcpp.h>
#include <PhpRational.hpp>

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {
    /**
     *  Startup function that is called by the Zend engine 
     *  to retrieve all information about the extension
     *  @return void*
     */
    PHPCPP_EXPORT void *get_module() {
        // create static instance of the extension object
        static Php::Extension myExtension("rational", "1.0");

        // description of the class so that PHP knows which methods are accessible
        Php::Class<PhpRational> rational("Rational");

        // register the increment method, and specify its parameters
        rational.method("__construct", &PhpRational::__construct,  { 
            Php::ByVal("numerator", Php::Type::Numeric, true),
            Php::ByVal("denominator", Php::Type::Numeric, false)
        });
        // register the add method, and specify its parameters
        rational.method("__toString", &PhpRational::__toString, {});
        // register the echo method, and specify its parameters
        rational.method("print", &PhpRational::print, {});
        // register the add method, and specify its parameters
        rational.method("add", &PhpRational::operator+=, {
            Php::ByRef("rhs", "Rational", true)
        });
        // register the add method, and specify its parameters
        rational.method("sub", &PhpRational::operator-=, {
            Php::ByRef("rhs", "Rational", true)
        });
        // register the add method, and specify its parameters
        rational.method("mul", &PhpRational::operator*=, {
            Php::ByRef("rhs", "Rational", true)
        });
        // register the add method, and specify its parameters
        rational.method("div", &PhpRational::operator/=, {
            Php::ByRef("rhs", "Rational", true)
        });
        // add the class to the extension
        myExtension.add(std::move(rational));

        // return the extension
        return myExtension;
    }
}