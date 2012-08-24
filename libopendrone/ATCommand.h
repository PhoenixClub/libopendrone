#ifndef ATCOMMAND_H
#define ATCOMMAND_H

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

#endif  
