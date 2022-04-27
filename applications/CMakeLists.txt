
set_compiler_flags(STRICT)

if(BUILD_WITH_BOOST)
    add_subdirectory( boostHelloWorld )
endif(BUILD_WITH_BOOST)

if(BUILD_WITH_EIGEN)
    add_subdirectory( eigenHelloWorld )
endif(BUILD_WITH_EIGEN)

if(BUILD_WITH_OPENCV)
    add_subdirectory( opencvHelloWorld )
endif(BUILD_WITH_OPENCV)

if(BUILD_WITH_ZIP)
    add_subdirectory( zipHelloWorld )
endif(BUILD_WITH_ZIP)

if ( MSVC )
	# Add .NET only on Microsoft compiler
	add_subdirectory( cppCliHelloWorld )
	add_subdirectory( wpfHelloWorld )
endif ( MSVC )

add_subdirectory( helloWorld )
