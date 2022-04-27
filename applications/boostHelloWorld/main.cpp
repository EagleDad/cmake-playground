#include <iostream>
#include <boost/filesystem.hpp>

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        std::string path = "C:/Temp";

        boost::filesystem::path p( path );

        if ( boost::filesystem::exists( p ) )
        {
            std::cout << path << ": exists." << std::endl;
        }
        else
        {
            std::cout << path << ": does not exists." << std::endl;
        }

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
