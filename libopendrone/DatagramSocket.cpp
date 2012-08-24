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

#include <libopendrone/DatagramSocket.h>

namespace opendrone {
    DatagramSocket::DatagramSocket(std::string address, uint32_t port)
        : m_hostAddr(address), m_hostPort(port), m_socketFd(0), m_hostInfo(0),
        m_isConnected(false)
    {
        /* empty */
    }

    DatagramSocket::~DatagramSocket() 
    {
        if (!m_isConnected)
        {
            // Ensure the socket is closed and the socket is freed
            Close();
        }
    }

    bool DatagramSocket::Connect()
    {
        addrinfo hints;
        addrinfo* serverInfo;
        int ret;
        int fd;

        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_DGRAM;

        if ((ret = getaddrinfo(m_hostAddr.c_str(), TypeToString(m_hostPort).c_str(), 
                                                &hints, &serverInfo)) != 0) {
            std::cerr << "getaddrinfo failed: " << gai_strerror(ret) << std::endl;
            return false;
        }

        // Loop all the results from getaddrinfo until we get a valid connection
        for (; serverInfo != NULL; serverInfo = serverInfo->ai_next) 
        {
            if ((fd = socket(serverInfo->ai_family, serverInfo->ai_socktype,
                    serverInfo->ai_protocol)) >= 0)
            {
                break; // We've got a valid socket
            }
            // connect() the fd so that we can use send and recv
            if (connect(fd, serverInfo->ai_addr, serverInfo->ai_addrlen) != -1)
            {
                break;
            }
            close(fd);
        }

        if (!serverInfo)
        {
            std::cerr << "Unable to connect to " << m_hostAddr << ":" << m_hostPort 
            << std::endl;
            return false;
        }

        m_socketFd = fd;
        m_hostInfo = serverInfo;
        m_isConnected = true;
    }

    void DatagramSocket::Close()
    {
        if (!Valid())
        {
            std::cerr << "Called Close() on invalid socket" << std::endl;
            return;
        }
        freeaddrinfo(m_hostInfo);
        close(m_socketFd);
        m_hostInfo = 0;
        m_socketFd = 0;
        m_isConnected = false;
    }

    bool DatagramSocket::Valid()
    {
        return (m_socketFd && m_hostInfo && m_isConnected);
    }

    uint32_t DatagramSocket::Write(const char* buffer, uint32_t length)
    {
        if (!Valid())
        {
            std::cerr << "Called Write() on invalid socket" << std::endl;
            return -1;
        }
        return send(m_socketFd, buffer, length, 0);
    }

    uint32_t DatagramSocket::Read(char* buffer, uint32_t length)
    {
        if (!Valid())
        {
            std::cerr << "Called Read() on invalid socket" << std::endl;
            return -1;
        }
        return recv(m_socketFd, buffer, length, 0);
    }

    bool DatagramSocket::WriteAll(const char* buffer, uint32_t length)
    {
        uint32_t curPos = 0;
        uint32_t toWrite = length;
        while (toWrite > 0)
        {
            uint32_t written = Write(buffer+curPos, toWrite);
            if (written == -1)
            {
                // error, probably timeout. close and return an error
                Close();
                return false;
            }
            toWrite -= written;
            curPos += written;
        }
        return true;
    }

    bool DatagramSocket::ReadAll(char* buffer, uint32_t length)
    {
        uint32_t curPos = 0;
        uint32_t toRead = length;
        while (toRead > 0)
        {
            uint32_t read = Read(buffer+curPos, toRead);
            if (read == -1)
            {
                // error, probably timeout. close and return an error
                Close();
                return false;
            }
            toRead -= read;
            curPos += read;
        }
        return true;
    }
}