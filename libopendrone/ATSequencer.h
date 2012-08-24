#ifndef _ATSEQUENCER_H
#define _ATSEQUENCER_H

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
        
        /**
         * Default constructor
         */
        ATSequencer();
    public:
        /**
         * Returns and increments m_nextSeqId
         * \returns The next sequence id
         */
        static int GetNextSequenceId();
    };
}

#endif // _ATSEQUENCER_H
