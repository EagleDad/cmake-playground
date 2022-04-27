#define IGNORE_WARNINGS_PYBIND_PUSH                                            \
    __pragma( warning( push ) ) __pragma( warning( disable : 6011 ) )          \
        __pragma( warning( disable : 4244 ) ) __pragma(                        \
            warning( disable : 4623 ) ) __pragma( warning( disable : 4626 ) )  \
            __pragma( warning( disable : 4464 ) ) __pragma( warning(           \
                disable : 4465 ) ) __pragma( warning( disable : 4365 ) )       \
                __pragma( warning( disable : 5039 ) ) __pragma( warning(       \
                    disable : 5027 ) ) __pragma( warning( disable : 4191 ) )   \
                    __pragma( warning( disable : 4686 ) )                      \
                        __pragma( warning( disable : 4868 ) )                  \
                            __pragma( warning( disable : 4371 ) )              \
                                __pragma( warning( disable : 4710 ) )          \
                                    __pragma( warning( disable : 4371 ) )

#define IGNORE_WARNINGS_POP __pragma( warning( pop ) )

IGNORE_WARNINGS_PYBIND_PUSH
#include <pybind11/pybind11.h>
IGNORE_WARNINGS_POP

#include <myproject/sharedLibrary/string.h>

namespace py = pybind11;

PYBIND11_MODULE( myproject, m )
{
    m.def( "lowercase", myproject::sharedlib::lowercase );

    m.def( "uppercase", myproject::sharedlib::uppercase );
}