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

#include <libopendrone/ATSequencer.h>

namespace opendrone
{
    int ATSequencer::m_nextSeqId = 1;

    ATSequencer::ATSequencer()
    {
        /* empty */
    }

    int ATSequencer::GetNextSequenceId()
    {
        return ATSequencer::m_nextSeqId++;
    }
}
