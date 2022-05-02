project(ActivityLibrary VERSION 0.1.0 LANGUAGES CSharp)

include(DotNetSupport)

set(LIBRARY_NAME "ActivityLibrary")

add_csharp_library(
    TARGET 
        ${LIBRARY_NAME}
        
    CREATE_DEFAULT_FILES
    
    SOURCES
        src/Activity1.cs
        
        
    RESOURCES
        "Resources/Activity.png"

    DOT_NET_REFERENCES
        "Microsoft.CSharp"
        "System"
        "System.Activities"
        "System.Activities.Presentation"
        "System.Core"
        "System.Data"
        "System.Drawing"
        "System.Runtime.Serialization"
        "System.ServiceModel"
        "System.ServiceModel.Activities"
        "System.Xaml"
        "System.Xml"
        "System.Xml.Linq"
        "PresentationFramework"
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${LIBRARY_NAME} PROPERTIES FOLDER "libraries")
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