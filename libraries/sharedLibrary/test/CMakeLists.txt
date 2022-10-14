
set(EXECUTABLE_NAME "test_haredLibraryTest")

add_gtest_executable(
    TARGET
        ${EXECUTABLE_NAME}

    HEADERS

    SOURCES
        src/test_string.cpp

    DEPENDENCIES
        MyProject::SharedLibrary

)

target_include_directories(${EXECUTABLE_NAME}
    PUBLIC
)