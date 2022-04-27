
project(WpfHelloWorld VERSION 0.1.0 LANGUAGES CSharp)

set(EXECUTABLE_NAME "wpfhelloworld")

include(WpfSupport)

add_csharp_executable(
    TARGET ${EXECUTABLE_NAME}
    SOURCES
        src/MyTestClass.cs
        src/Person.cs
     XAML_SOURCES
        
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()
