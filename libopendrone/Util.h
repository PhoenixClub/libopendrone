/**
 * This file is part of libopendrone.
 *
 * libopendrone is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libopendrone is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libopendrone.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef AT_UTIL_H
#define AT_UTIL_H

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

#endif
