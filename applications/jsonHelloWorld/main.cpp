#include <iostream>

#include <nlohmann/json.hpp>

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        nlohmann::json j;

        return 0;
    }
    catch ( nlohmann::json::exception& e )
    {
        std::cout << "Caught nlohmann::json::exception" << e.what( ) << std::endl;
        return -1;
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
