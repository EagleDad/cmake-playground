

#define IGNORE_WARNINGS_GTEST_PUSH                                             \
    __pragma( warning( push ) ) __pragma( warning( disable : 4389 ) )          \
        __pragma( warning( disable : 4626 ) )                                  \
            __pragma( warning( disable : 5026 ) )                              \
                __pragma( warning( disable : 4625 ) )                          \
                    __pragma( warning( disable : 5027 ) )                      \
                        __pragma( warning( disable : 5219 ) )                  \
                            __pragma( warning( disable : 4388 ) )              \
                                __pragma( warning( disable : 4365 ) )

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


IGNORE_WARNINGS_GTEST_PUSH
#include <gmock/gmock.h>
#include <gtest/gtest.h>
IGNORE_WARNINGS_POP

#include <myproject/sharedLibrary/string.h>

using namespace myproject::sharedlib;
using testing::Eq;

TEST( test_sharedLibrary_String, ConvertToLowercase )
{
    EXPECT_STRNE( "hello", "world" );
    ASSERT_THAT( lowercase( "aBc42XYZ" ), Eq( "abc42xyz" ) );
}

TEST( test_sharedLibrary_String, ConvertToUppercase )
{
    ASSERT_THAT( uppercase( "aBc42XYZ" ), Eq( "ABC42XYZ" ) );
}
