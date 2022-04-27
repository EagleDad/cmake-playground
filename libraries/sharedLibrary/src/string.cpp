// See math.cpp for details about the convention used here

#include <myproject/sharedLibrary/export.h>

#include "privateheader.h"

#include <algorithm>
#include <string>

#include <algorithm>
#include <string>

namespace myproject::sharedlib
{
MYPROJECT_SHAREDLIBRARY_EXPORT
std::string lowercase( std::string s )
{
    std::string copy( s );

    std::transform( copy.begin( ),
                    copy.end( ),
                    copy.begin( ),
                    []( const char c )
                    { return static_cast< char >( std::tolower( c ) ); } );

    return copy;
}

MYPROJECT_SHAREDLIBRARY_EXPORT
std::string uppercase( std::string s )
{
    std::string copy( s );

    std::transform( copy.begin( ),
                    copy.end( ),
                    copy.begin( ),
                    []( const char c )
                    { return static_cast< char >( std::toupper( c ) ); } );

    return copy;
}

} // namespace myproject::sharedlib
