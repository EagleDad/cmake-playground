#include <iostream>
#include <opencv2/core.hpp>

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        std::cout << "OpenCV version : " << CV_VERSION << std::endl;
        std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
        std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
        std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;

        return 0;
    }
    catch ( cv::Exception& e )
    {
        std::cout << "Caught cv::Exception" << e.what( ) << std::endl;
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
