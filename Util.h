#ifndef AT_UTIL_H
#define AT_UTIL_H

#include <sstream>

/**
 * Converts a type T to std::string form using the stringstream << operator
 */
template <typename T>
std::string TypeToString(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

#endif
