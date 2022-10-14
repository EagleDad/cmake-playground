#include <iostream>
#include <clipper2/clipper.h>
#include <clipper2/clipper.engine.h>

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        std::cout << "Clipper2 version : " << CLIPPER2_VERSION << std::endl;

        Clipper2Lib::Path64 pattern =
            Clipper2Lib::Ellipse< int64_t >( Clipper2Lib::Point64( ), 25, 25 );

        return 0;
    }
    catch ( Clipper2Lib::Clipper2Exception& e )
    {
        std::cout << "Caught Clipper2Lib::Exception" << e.what( ) << std::endl;
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
