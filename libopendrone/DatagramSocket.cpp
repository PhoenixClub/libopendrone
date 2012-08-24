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

DatagramSocket::DatagramSocket(std::string address, uint32_t port)
    : m_hostAddr(address), m_hostPort(port)
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

}

void DatagramSocket::Close();

uint32_t DatagramSocket::Write(const char* buffer, uint32_t length)
{

}

uint32_t DatagramSocket::Read(char* buffer, uint32_t length)
{

}

bool DatagramSocket::WriteAll(const char* buffer, uint32_t length)
{

}

bool DatagramSocket::ReadAll(char* buffer, uint32_length)
{
    
}