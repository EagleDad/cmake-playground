#pragma once

#include <myproject/sharedLibrary/export.h>

/**
 * @file string.h
 * @brief String helper functions.
 *
 * String helper functions available in the API. They are not particularly
 * useful, but they demonstrate how a non-OO API looks like.
 */

#include <string>

namespace myproject::sharedlib
{

/**
 * @brief Convert the string to its lowercase form.
 * @param s the input string
 * @return The string in lowercase
 */
MYPROJECT_SHAREDLIBRARY_EXPORT
std::string lowercase( std::string s );

/**
 * @brief Convert the string to its uppercase form.
 * @param s the input string
 * @return The string in uppercase
 */
MYPROJECT_SHAREDLIBRARY_EXPORT
std::string uppercase( std::string s );

} // namespace myproject::sharedlib
