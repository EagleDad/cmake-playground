// See test_math.cpp for more details about the convention used here
#include <myproject/sharedLibrary/string.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
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
