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
}
