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

#ifndef _ATCOMMAND_H
#define _ATCOMMAND_H

#include <string>

namespace opendrone
{
    /**
     * An enumeration containing all the possible at command types
     */
    enum ATType
    {
        TYPE_REF,
        TYPE_PCMD,
        TYPE_FTRIM,
        TYPE_CONFIG,
        TYPE_CONFIGIDS,
        TYPE_LED,
        TYPE_ANIM,
        TYPE_COMWDG
    };
    /**
     * Converts an ATType to its corresponding string
     * \param type The type to convert
     * \return The corresponding string
     */
    std::string ATTypeToStr(ATType type);
    /**
     * A simple struct used to represent a single constructed AT Command
     */
    struct ATCommand
    {
        char command[128]; // 128 should be enough for all commands
    };
}

#endif // _ATCOMMAND_H
