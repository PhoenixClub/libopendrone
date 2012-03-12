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
