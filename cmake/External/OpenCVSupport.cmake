
set( OpenCV_DEPENDS "" )

if (BUILD_WITH_OPENCV_CONTRIB)

    ExternalProject_Add(
        opencv_contrib
        GIT_REPOSITORY      https://github.com/opencv/opencv_contrib.git
        GIT_TAG             4.5.5
        SOURCE_DIR "${FETCHCONTENT_BASE_DIR}/opencv_contrib/opencv_contrib-4.5.5/src"
        BINARY_DIR ""
        INSTALL_DIR ""
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
    )
    
    list(APPEND OpenCV_DEPENDS "opencv_contrib")
    
    set(OPENCV_CONTRIB_MODULE_PATH ${FETCHCONTENT_BASE_DIR}/opencv_contrib/opencv_contrib-4.5.5/src/modules )
    
    list(APPEND OPENCV_EXTRA_BUILD_FLAGS "-DOPENCV_EXTRA_MODULES_PATH:PATH=${OPENCV_CONTRIB_MODULE_PATH}")
    
endif()

MESSAGE(STATUS "OPENCV_EXTRA_BUILD_FLAGS: ${OPENCV_EXTRA_BUILD_FLAGS}")

ExternalProject_Add(
    opencv
    DEPENDS ${OpenCV_DEPENDS}
    PREFIX ${FETCHCONTENT_BASE_DIR}/opencv
    GIT_REPOSITORY      https://github.com/opencv/opencv.git
    GIT_TAG             4.5.5
    SOURCE_DIR "${FETCHCONTENT_BASE_DIR}/opencv/opencv-4.5.5/src"
    BINARY_DIR "${FETCHCONTENT_BASE_DIR}/opencv/opencv-4.5.5/build"
    INSTALL_DIR "${FETCHCONTENT_BASE_DIR}/opencv/opencv-4.5.5/install"
    CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    -DCMAKE_BUILD_TYPE=Release
    -DBUILD_PERF_TESTS:BOOL=FALSE
    -DBUILD_SHARED_LIBS:BOOL=TRUE
    -DBUILD_WITH_STATIC_CRT:BOOL=TRUE
    -DBUILD_TESTS:BOOL=FALSE
    -DWITH_TIFF:BOOL=FALSE
    -DWITH_JASPER:BOOL=FALSE
    -DBUILD_DOCS:BOOL=FALSE
    -DBUILD_FAT_JAVA_LIB:BOOL=FALSE
    -DWITH_CUDA:BOOL=FALSE
    -DWITH_VTK:BOOL=FALSE
    -DWITH_EIGEN:BOOL=OFF
    -DWITH_1394:BOOL=OFF
    -DWITH_GSTREAMER:BOOL=OFF
    -DWITH_GTK:BOOL=OFF
    -DWITH_ITT:BOOL=OFF
    -DBUILD_opencv_python2:BOOL=FALSE
    -DBUILD_opencv_python3:BOOL=FALSE
    -DBUILD_opencv_apps:BOOL=FALSE
    -DBUILD_JAVA:BOOL=FALSE
    -DBUILD_PACKAGE:BOOL=FALSE
    ${OPENCV_EXTRA_BUILD_FLAGS}
)

list(APPEND DEPENDENCIES opencv)

set(OpenCV_DIR "${FETCHCONTENT_BASE_DIR}/opencv/opencv-4.5.5/install")

list(APPEND EXTRA_CMAKE_ARGS
    -DOpenCV_DIR:PATH=${OpenCV_DIR}
)
