#include <iostream>
#include <myproject/sharedLibrary/string.h>

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        std::cout << "Hello World" << std::endl;

        std::string szHelloWrold = "Hello World";
        std::string converted = myproject::sharedlib::uppercase( szHelloWrold );

        std::cout << converted << std::endl;
        return 0;
    }
    catch ( std::exception& e )
    {
        std::cout << "Caught std::exception" << e.what( ) << std::endl;
        return -1;
    }
    catch ( ... )
    {
        std::cerr << "Caught undetermined exception" << std::endl;
        return -1;
    }
}
