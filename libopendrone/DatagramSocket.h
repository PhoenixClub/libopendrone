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

#ifndef _DATAGRAM_SOCKET_H
#define _DATAGRAM_SOCKET_H

#include <libopendrone/OpendroneConfig.h>
#include <libopendrone/Util.h>

#include <string>
#include <iostream>
#include <stdint.h>
#include <string.h>

#ifdef PLAF_UNIX
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <netdb.h>
#endif

#ifdef PLAF_WIN
  #include <windows.h>
#endif

namespace opendrone
{
    /**
     * A generic class for creating a UDP client and communicating through it
     */
    class DatagramSocket
    {
    private:
        /**
         * Is the socket connected (as far as we know)?
         */
        bool m_isConnected;
        /**
         * The address of the host
         */
        std::string m_hostAddr;
        /**
         * The post to connect on the host
         */
        uint32_t m_hostPort;
        /**
         * The file descriptor of the socket
         */
        uint32_t m_socketFd;
        /**
         * Since we're using UDP, we might need to store the addrinfo struct
         */
        addrinfo* m_hostInfo;
    public:
        /**
         * Constructs a datagram object, but doesn't create or connect the
         * socket yet
         * \param address The address to connect on
         * \param port The port to connect on
         */
        DatagramSocket(std::string address, uint32_t port);
        virtual ~DatagramSocket();

        /**
         * Creates the socket, and attempts to connect
         * \return Whether the connection was successful
         */
        bool Connect();
        /**
         * Closes the socket
         */
        void Close();
        /**
         * Checks if the socket is valid
         * \return Whether the socket is valid
         */
        bool Valid();

        /**
         * Writes a buffer to the socket.
         * \param buffer A pointer to the data to write
         * \param length The number of bytes to write from buffer
         * \return The number of bytes written
         */
        uint32_t Write(const char* buffer, uint32_t length);
        /**
         * Reads up to length amount of bytes into buffer
         * \param buffer The location to read into
         * \param length The maximum number of bytes to read
         * \return The number of bytes read
         */
        uint32_t Read(char* buffer, uint32_t length);
        /**
         * Attempt to write length bytes of data, and will retry until either
         * all data is written, or we recieve a timeout.
         * Guarantees either all data is written, or a timeout is recieved
         * \param buffer A pointer to the data to write
         * \param length The number of bytes to write from buffer
         * \return Whether the write was successful
         */
        bool WriteAll(const char* buffer, uint32_t length);
        /**
         * Reads length amount of bytes into buffer. Blocks until all data
         * is recieved.
         * Guarantees either length bytes are read, or a timeout is recieved
         * \param buffer The location to read into
         * \param length The maximum number of bytes to read
         * \return The number of bytes read
         */
        bool ReadAll(char* buffer, uint32_t length);
    };
}

#endif // _DATAGRAM_SOCKET_H