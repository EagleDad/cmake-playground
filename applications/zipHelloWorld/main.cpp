// std includes
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>

// 3'rd Party includes
#include <zip/zip.h>

// https://github.com/kuba--/zip

std::vector< std::string > getFileList( const std::string& directory,
                                        const std::string& fileExtension )
{
    std::vector< std::string > fileList;
    for ( const auto& entry : std::filesystem::directory_iterator( directory ) )
    {
        if ( ! is_directory( entry ) )
        {
            if ( std::filesystem::path( entry ).extension( ) == fileExtension )
            {
                fileList.push_back( entry.path( ).string( ) );
            }
        }
    }
    return fileList;
}

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    //std::string basePath =
    //    "C:/Users/dirk.adler/data/Dotcode/WorkingBadly/Dotcode_DavidLorand";
    /*std::string basePath =
        "C:/Users/dirk.adler/data/Dotcode/WorkingBadly/Dotcode_Sichuan_March_2021";*/
     std::string basePath =
         "C:/Users/dirk.adler/data/Dotcode/WorkingBadly/Dotcode_DavidLorand2";

    //std::string outPath = "C:/TEMP/Dotcode_DavidLorand";
    //std::string outPath = "C:/TEMP/Dotcode_Sichuan_March_2021";
     std::string outPath = "C:/TEMP/Dotcode_DavidLorand2";

    try
    {
        if ( ! std::filesystem::exists( basePath ) )
        {
            std::cout << "Defined BASE_PATH (" << basePath
                      << ") does not exist!" << std::endl;
            return 0;
        }

        std::vector< std::string > zipList = getFileList( basePath, ".zip" );

        std::cout << "Found " << zipList.size( ) << " zip files " << std::endl;

        int32_t imageIdx = 0;
        for ( const auto& zipFile : zipList )
        {
            auto zip = zip_open( zipFile.c_str( ), 0, 'r' );

            if ( ! zip )
            {
                std::cout << "Unable to open zip file " << zipFile
                          << ". Processing next" << std::endl;
            }

            std::ostringstream curName;
            curName << outPath << "/Image_" << std::setw( 3 )
                    << std::setfill( '0' ) << imageIdx++ << ".bmp";

            //std::cout << curName.str() << std::endl;

            if ( zip_entry_open( zip, "Picture Base_000.bmp" ) == 0 )
            {
                zip_entry_fread( zip, curName.str().c_str(  ) );
                zip_entry_close( zip );
            }

            zip_close( zip );
        }
        ////auto zip = zip_open( zipFileName.c_str( ), 0, 'r' );

        // if ( zip )
        //{
        // const int n = zip_entries_total( zip );

        // for ( int i = 0; i < n; ++i )
        //{
        //     zip_entry_openbyindex( zip, i );
        //     {
        //         const char* name = zip_entry_name( zip );
        //         std::cout << "Entry: " << name << std::endl;
        //         //int isdir = zip_entry_isdir( zip );
        //         //unsigned long long size = zip_entry_size( zip );
        //         //unsigned int crc32 = zip_entry_crc32( zip );
        //     }
        //     zip_entry_close( zip );
        // }

        //    std::cout << "VALID ZIP" << std::endl;
        //    if ( zip_entry_open( zip, "Picture Base_000.bmp" ) == 0 )
        //    {
        //        std::cout << "FOUND IMAGE" << std::endl;
        //        zip_entry_fread( zip, "C:\\Temp\\Picture Base_000_.bmp" );
        //    }
        //}
        // std::cout << "STOP" << std::endl;
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
