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

#include <libopendrone/ATCommand.h>

namespace opendrone
{
    std::string ATTypeToStr(ATType type)
    {
        switch (type)
        {
        case TYPE_REF:
            return "REF";
        case TYPE_PCMD:
            return "PCMD";
        case TYPE_FTRIM:
            return "FTRIM";
        case TYPE_CONFIG:
            return "CONFIG";
        case TYPE_CONFIGIDS:
            return "CONFIGIDS";
        case TYPE_LED:
            return "LED";
        case TYPE_ANIM:
            return "ANIM";
        case TYPE_COMWDG:
            return "COMWDG";
        }
        return "ERR";
    }
}
