#ifndef AT_COMMAND_FACTORY_H
#define AT_COMMAND_FACTORY_H

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
        ATCommandFactory& AddCString(char* str);
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

#endif
