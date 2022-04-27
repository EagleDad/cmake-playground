#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

int print_eigen( Eigen::MatrixX3d m )
{
    // Eigen Matrices do have rule to print them with std::cout
    std::cout << m << std::endl;
    return 0;
}


int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        Eigen::Matrix3d test; // 3 by 3 double precision matrix initialization

        // Let's make it a symmetric matrix
        for ( int i = 0; i < 3; i++ )
        {
            for ( int j = 0; j < 3; j++ ) test( i, j ) = ( i + 1 ) * ( 1 + j );
        }

        // Print
        print_eigen( test );
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
