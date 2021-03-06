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

#ifndef _AT_COMMAND_FACTORY_H
#define _AT_COMMAND_FACTORY_H

#include <string>
#include <stdint.h>

#include <libopendrone/ATCommand.h>

namespace opendrone
{
    /**
     * A union wrapped in a struct used to convert floats to the type required
     * by the drone (IEEE-754 float, binary represented as a 32-bit integer)
     */
    typedef struct {
        union {
            int32_t intval;
            float floatval;
        };
    } ar_float_t;
    /**
     * A class which is used to construct ATCommands
     * Utilizes the chaining pattern
     */
    class ATCommandFactory
    {
    private:
        /**
         * A local buffer of the command so far
         */
        std::string m_commandBuffer;
    public:
        /**
         * Default constructor.
         * \param type The ATType of the command we're constructing.
         */
        ATCommandFactory(ATType type);
        virtual ~ATCommandFactory();

        /**
         * Appends a parameter of type string to the command
         * \param str The string to append in std::string& form
         * \return A reference to this
         */
        ATCommandFactory& AddString(std::string& str);
        /**
         * Appends a parameter of type string to the command
         * \param str The string to append in char* form
         * \return A reference to this
         */
        ATCommandFactory& AddCString(const char* str);
        /**
         * Appends a parameter of type int to the command
         * \param i The int to append
         * \return A reference to this
         */
        ATCommandFactory& AddInteger(int32_t i);
        /**
         * Appends a parameter of type float to the command
         * \param f The float to append
         * \return A reference to this
         */
        ATCommandFactory& AddFloat(float f);
        
        /**
         * Builds the packet
         * \return The constructed ATCommand
         */
        ATCommand Construct();
    };
}

#endif // _AT_COMMAND_FACTORY_H
