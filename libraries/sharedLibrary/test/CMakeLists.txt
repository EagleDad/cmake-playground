project(SharedLibraryTest)

find_package(GTest REQUIRED)

set_compiler_flags(THIRD_PARTY)

set(EXECUTABLE_NAME "test_sharedLibrary")

add_executable(test_sharedLibrary
    src/test_string.cpp
)

# Write own function to add test and do grouping there
if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "tests")
endif()

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        GTest::GTest
        GTest::Main
        GTest::gmock
        MyProject::SharedLibrary
)

gtest_discover_tests(${EXECUTABLE_NAME})