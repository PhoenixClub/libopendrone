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
