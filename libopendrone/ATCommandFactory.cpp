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
