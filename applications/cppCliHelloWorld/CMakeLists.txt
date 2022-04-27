
project(CppCliHelloWorld)

set(EXECUTABLE_NAME "cppclihelloworld")

include(DotNetSupport)

add_cpp_cli_executable(
    TARGET ${EXECUTABLE_NAME}
    SOURCES
        main.cpp
        
    DOT_NET_REFERENCES
        "System"
        "System.Core"
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()

install(TARGETS ${LIBRARY_NAME}
    ARCHIVE  DESTINATION "lib"
    LIBRARY  DESTINATION "bin"
    RUNTIME  DESTINATION "bin"
    RESOURCE DESTINATION "bin"
)

install(
    FILES
    DESTINATION
        "bin"
)
