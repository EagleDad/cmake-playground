include(FetchContent)
include(ExternalProject)

project (SuperBuild NONE)

set(DEPENDENCIES)
set(EXTRA_CMAKE_ARGS)

list(APPEND EXTRA_CMAKE_ARGS
    -DUSE_SUPERBUILD:BOOL=OFF
)

if(BUILD_WITH_BOOST)
    include(BoostSupport)
endif(BUILD_WITH_BOOST)

if(BUILD_WITH_EIGEN)
    include(EigenSupport)
endif(BUILD_WITH_EIGEN)

if(BUILD_TESTING)
    include(GoogleTestSupport)
endif(BUILD_TESTING)

if(BUILD_PYTHON_BINDINGS)
    include(PyBind11Support)
endif(BUILD_PYTHON_BINDINGS)

if(BUILD_WITH_OPENCV)
    include(OpenCVSupport)
endif(BUILD_WITH_OPENCV)

if(BUILD_WITH_ZIP)
    include(ZipSupport)
endif(BUILD_WITH_ZIP)

if(BUILD_WITH_CLIPPER)
    include(ClipperSupport)
endif()

message(STATUS "EXTRA_CMAKE_ARGS: ${EXTRA_CMAKE_ARGS}")

foreach(X ${EXTRA_CMAKE_ARGS})
    message(STATUS "Arg=${X}")
endforeach()

# FIXME add to default target "all"?
ExternalProject_Add (superBuild
    DEPENDS ${DEPENDENCIES}
    SOURCE_DIR ${PROJECT_SOURCE_DIR}
    CMAKE_ARGS ${EXTRA_CMAKE_ARGS}
    CMAKE_CACHE_ARGS ${EXTRA_CMAKE_ARGS}
    INSTALL_COMMAND ""
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
)