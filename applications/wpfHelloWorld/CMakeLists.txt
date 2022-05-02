
project(WpfHelloWorld VERSION 0.1.0 LANGUAGES CSharp)

set(EXECUTABLE_NAME "wpfhelloworld")

add_wpf_executable(
    TARGET
        ${EXECUTABLE_NAME}
        
    CREATE_DEFAULT_FILES
    
    SOURCES
        src/MyTestClass.cs
        src/Person.cs
    
    XAML_SOURCES
        
    RESOURCES
     
    DOT_NET_REFERENCES
        "System"
        "System.Core"
        "System.Xaml"
        "System.Data"
        "WindowsBase"
        "PresentationCore"
        "PresentationFramework"
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()
