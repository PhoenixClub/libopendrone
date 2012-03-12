#ifndef ATSEQUENCER_H
#define ATSEQUENCER_H

namespace opendrone
{
    /**
     * A static class that keeps track of the current sequence number and issues
     * the next one along.
     */
    class ATSequencer
    {
    private:
        /**
         * The next sequence id
         */
        static int m_nextSeqId;
        
        ATSequencer();
    public:
        static int GetNextSequenceId();
    };
}

#endif
