
project(WpfHelloWorld VERSION 0.1.0 LANGUAGES CSharp)

set(EXECUTABLE_NAME "wpfhelloworld")

include(DotNetSupport)

add_wpf_executable(
    TARGET
        ${EXECUTABLE_NAME}
    
    SOURCES
        src/MyTestClass.cs
        src/Person.cs
    
    XAML_SOURCES
     
    DOT_NET_REFERENCES
        "System"
        "System.Core"
        "System.Xaml"
        "System.Data"
        "WindowsBase"
        "PresentationCore"
        "PresentationFramework"
)

# Nuget needs to be installed
# add_nuget_package(
    # TARGET 
        # ${EXECUTABLE_NAME}
    # PACKAGE
        # NUnit
    # VERSION
        # 3.13.3
# )

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()
