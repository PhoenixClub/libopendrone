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
