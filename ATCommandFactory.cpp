#include <libopendrone/ATCommandFactory.h>
#include <libopendrone/ATSequencer.h>
#include <libopendrone/Util.h>

#include <string.h>
#include <cstdio>
#include <assert.h>

namespace opendrone
{
    ATCommandFactory::ATCommandFactory(ATType type)
    {
        std::string seqIdStr = TypeToString(ATSequencer::GetNextSequenceId());
        std::string typeStr = ATTypeToStr(type);
        m_commandBuffer.append("AT*");
        m_commandBuffer.append(typeStr);
        m_commandBuffer.append("=");
        m_commandBuffer.append(seqIdStr);
    }
    ATCommandFactory::~ATCommandFactory()
    {
        /* empty */
    }

    ATCommandFactory& ATCommandFactory::AddString(std::string& str)
    {
        m_commandBuffer.append(",\"");
        m_commandBuffer.append(str);
        m_commandBuffer.append("\"");
        return *this;
    }
 
    ATCommandFactory& ATCommandFactory::AddCString(char* str)
    {
        m_commandBuffer.append(",\"");
        m_commandBuffer.append(str);
        m_commandBuffer.append("\"");
        return *this;
    }
    
    ATCommandFactory& ATCommandFactory::AddInteger(int32_t i)
    {
        m_commandBuffer.append(",");
        m_commandBuffer.append(TypeToString(i));
        return *this;
    }
    
    ATCommandFactory& ATCommandFactory::AddFloat(float f)
    {
        ar_float_t flt;
        flt.floatval = f;
        m_commandBuffer.append(",");
        m_commandBuffer.append(TypeToString(flt.intval));
        return *this;
    }
    
    ATCommand ATCommandFactory::Construct()
    {
        m_commandBuffer.append("\n");
        ATCommand cmd;
        memset(&cmd, 0, sizeof(ATCommand));
        std::copy(m_commandBuffer.begin(), m_commandBuffer.end(), cmd.command);
        return cmd;
    }
}
