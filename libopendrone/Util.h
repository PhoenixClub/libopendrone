#ifndef _AT_UTIL_H
#define _AT_UTIL_H

#include <sstream>

/**
 * Converts a type T to std::string form using the stringstream << operator
 * \return The value in std::string form
 */
template <typename T>
std::string TypeToString(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

#endif // _AT_UTIL_H
