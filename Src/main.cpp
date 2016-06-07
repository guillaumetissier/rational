#include <phpcpp.h>
#include <PhpRational.hpp>

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        Php::Class<PhpRational> rational("Rational");
        /*rational.method("add", &Rational::operator+=, {
            Php::ByRef("r", "Rational")
        });

        rational.method("sub", &Rational::operator-=, {
            Php::ByRef("r", "Rational")
        });

        rational.method("mul", &Rational::operator*=, {
            Php::ByRef("r", "Rational")
        });

        rational.method("div", &Rational::operator/=, {
            Php::ByRef("r", "Rational")
        });
*/
        static Php::Extension extension("rational", "1.0");
        extension.add(std::move(rational));

        return extension;
    }
}