# Example of shared library.

project(SharedLibrary)

set(LIBRARY_NAME "MyProject::SharedLibrary")
get_raw_target_name(${LIBRARY_NAME} LIBRARY_NAME_RAW)

add_library(${LIBRARY_NAME_RAW} SHARED
    src/string.cpp
    src/privateheader.h

    include/myproject/sharedlibrary/string.h
)

add_library(${LIBRARY_NAME} ALIAS ${LIBRARY_NAME_RAW})

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${LIBRARY_NAME_RAW} PROPERTIES FOLDER "libraries")
endif()

target_include_directories(${LIBRARY_NAME_RAW}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>
)

# TODO:  Refactor to  wrapper that takes care of the include dir wit get_properties
generate_export_header(${LIBRARY_NAME_RAW} EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/myproject/sharedLibrary/export.h)

target_link_libraries(${LIBRARY_NAME_RAW}
    PRIVATE
        # Define any private dependencies here
    PUBLIC
        # Define any public dependencies here
)

if(BUILD_TESTING)
    # Build unit tests only if testing is enabled
    add_subdirectory(test)
endif(BUILD_TESTING)

if(BUILD_PYTHON_BINDINGS)
    add_subdirectory(python)
endif(BUILD_PYTHON_BINDINGS)

# Tell CMake how to install our library
install(TARGETS ${LIBRARY_NAME_RAW}
    ARCHIVE  DESTINATION "lib"
    LIBRARY  DESTINATION "bin"
    RUNTIME  DESTINATION "bin"
)

# In addition to the binaries, copy the directory containing all public
# header files to the installation directory.
install(
    DIRECTORY
        include
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}"
)
