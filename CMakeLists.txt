cmake_minimum_required(VERSION 3.11)

# Configure C++
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# Project names are only relevant for humans, camel case is OK

set(COPYRIGHT_YEAR_START 2022)

list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Checks
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/External
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/.NetSupport
)

# Force all libraries to be build dynamic if ON, also they are set to STATIC
# If we set this flag to on and use gtest with FectContent we have to
# implement the main function for our unit tests by ourself
option(BUILD_SHARED_LIBS        "Build project libraries as shared libraries" OFF)
option(BUILD_TESTING            "Build with tests" OFF)
option(BUILD_PYTHON_BINDINGS    "Build bindings for python" OFF)
option(BUILD_DOC                "Build documentation" OFF)
option(BUILD_WITH_EIGEN         "Build some libraries with eigen support" OFF)
option(BUILD_WITH_BOOST         "Build some libraries with boost support" OFF)
option(BUILD_WITH_OPENCV        "Build some libraries with OpenCV support" OFF)
option(BUILD_WITH_ZIP           "Build some libraries with Zip support" OFF)

option(DEBUG_POSTFIX            "Set to ON to force _d postfix for the lib names." OFF)

option(ENABLE_SOLUTION_FOLDERS  "Solution folder in Visual Studio or in other IDEs" ON)

# 3rd party dependencies needs to be build first
option (USE_SUPERBUILD "Whether or not a superbuild should be invoked" ON)

if (USE_SUPERBUILD)
    #project (SUPERBUILD NONE)
    # execute the superbuild (this script will be invoked again without the
    # USE_SUPERBUILD option this time)
    include(SuperBuild)
    return()                      # stop processing this file further
else(USE_SUPERBUILD)
    project(CMakePlayground VERSION 1.0.0)
endif(USE_SUPERBUILD)

if(ENABLE_SOLUTION_FOLDERS)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
endif()


# Standard CMake modules
include(FindPackageHandleStandardArgs) 
include(GenerateExportHeader)


# Modules
include(Common)
include(CompilerFlags)

if(DEBUG_POSTFIX)
    # For debug libs and exes, add "-d" postfix
    set(CMAKE_DEBUG_POSTFIX "-d" CACHE STRING "Set debug library postfix")
endif(DEBUG_POSTFIX)

if(BUILD_TESTING)
    # Activate test support
    # Enable integration with CTest
    # The shared libs option needs to be turne off to be alble to use gtest main function 
    # instead of writing every time our own. Maybe for all test executables a own fucntion is required
    include(CTest)
    enable_testing()
    include(GoogleTest)
endif(BUILD_TESTING)





if(BUILD_DOC)
    #include(DoxygenSupport)
    #add_subdirectory(doc)
endif(BUILD_DOC)

# Add clang-format for all C++ projects
# and editorconfig for all .NET projects
add_custom_target(ALL
    SOURCES 
        .clang-format
        .editorconfig
)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory" FORCE)

message(STATUS "")
message(STATUS "  Install to: " "${CMAKE_INSTALL_PREFIX}")
message(STATUS "-----------------------------------------------------------------")
message(STATUS "")

# Let CMake load the CMakeLists.txt in the subdirectory to load the
# sub-projects. Prefer lower-case names.
add_subdirectory(libraries)
add_subdirectory(applications)










#find_program ( CLANG_TIDY_EXE NAMES clang-tidy clang-tidy.exe
#    PATHS "$ENV{ProgramFiles}/Microsoft Visual Studio/2022/Professional/VC/Tools/Llvm/bin"
#    DOC "Path to clang-tidy executable"
#)

#find_program ( 
#    CLANG_TIDY_EXE 
#    NAMES
#        clang-tidy clang-tidy.exe
#    DOC 
#        "Path to clang-tidy executable"
#    PATHS
#        ".../Llvm/bin"
#)

#message(STATUS "$ENV{ProgramFiles}/Microsoft Visual Studio/2022/Professional/VC/Tools/Llvm/bin")
#message(STATUS "MSVC_VERSION: ${MSVC_VERSION}")
#message(STATUS "MSVC_TOOLSET_VERSION: ${MSVC_TOOLSET_VERSION}")

#if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#    message(STATUS "Install to default")
#else(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#    message(STATUS "Install to custom")
#endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# TODO: Test on clean project. The defalult install dir will be
# c:/Program Files/${PROJECT_NAME}
#if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#  set(CMAKE_INSTALL_PREFIX "/my/default" CACHE PATH "..." FORCE)
#endif()




















# include(FetchContent)

# message("Configure Eigen: ")

# FetchContent_Declare(
        # eigen
        # GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        # GIT_TAG 3.4
        # GIT_SHALLOW TRUE
        # GIT_PROGRESS TRUE
# )
# option(EIGEN_BUILD_DOC OFF)
# option(BUILD_TESTING OFF)
# option(EIGEN_LEAVE_TEST_IN_ALL_TARGET OFF)
# option(EIGEN_BUILD_PKGCONFIG OFF)
# FetchContent_MakeAvailable(eigen)

# message("====================================")
# message("Configure spdlog: ")

# FetchContent_Declare(
        # spdlog
        # GIT_REPOSITORY https://github.com/gabime/spdlog.git
        # GIT_TAG v1.8.5
        # GIT_SHALLOW TRUE
        # GIT_PROGRESS TRUE
# )
# option(SPDLOG_BUILD_SHARED OFF)
# option(SPDLOG_BUILD_ALL OFF)
# FetchContent_MakeAvailable(spdlog)

# include(FetchContent)

# message("Configure Eigen: ")

# FetchContent_Declare(
        # eigen
        # GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        # GIT_TAG 3.4
        # GIT_SHALLOW TRUE
        # GIT_PROGRESS TRUE
# )
# option(EIGEN_BUILD_DOC OFF)
# option(BUILD_TESTING OFF)
# option(EIGEN_LEAVE_TEST_IN_ALL_TARGET OFF)
# option(EIGEN_BUILD_PKGCONFIG OFF)
# FetchContent_MakeAvailable(eigen)
# set_target_properties(eigen PROPERTIES EXCLUDE_FROM_ALL TRUE)