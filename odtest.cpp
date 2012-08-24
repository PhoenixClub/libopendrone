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
#include <libopendrone/DatagramSocket.h>

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Testing ATCommandBuilder." << std::endl;
    opendrone::ATCommand cmd = opendrone::ATCommandFactory(opendrone::TYPE_REF)
                                .AddCString("lol")
                                .AddInteger(1000)
                                .AddFloat(-0.8f)
                                .Construct();
    std::cout << cmd.command << std::endl;
    cmd = opendrone::ATCommandFactory(opendrone::TYPE_REF)
                                .AddCString("lol")
                                .AddInteger(1000)
                                .AddFloat(-0.8f)
                                .Construct();
    std::cout << cmd.command << std::endl;

    std::cout << "Testing DatagramSocket." << std::endl;
    // Test by contacting an echo server. Assumes you have one running
    // at localhost:8888
    opendrone::DatagramSocket socket("0.0.0.0", 8888);
    if (!socket.Connect())
    {
        return 1;
    }
    char writebuf[32];
    char readbuf[32];
    strcpy(writebuf, "hello");
    if (!socket.WriteAll(writebuf, strlen(writebuf)))
    {
        std::cerr << "WriteAll failed" << std::endl;
        socket.Close();
        return 1;
    }
    if (!socket.Read(readbuf, 32)) // Read a max of 32 bytes
    {
        std::cerr << "Read failed" << std::endl;
        socket.Close();
        return 1;
    }
    if (!strcmp(writebuf, readbuf))
    {
        std::cout << "Success! The strings are equal: " << writebuf << ", "
            << readbuf << std::endl;
    } else {
        std::cerr << "Failed. The strings are not equal: " << writebuf << ", "
            << readbuf << std::endl;
    }
    socket.Close();
    return 0;
}
