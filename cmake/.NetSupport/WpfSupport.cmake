include(CSharpUtilities)

set(DOT_NET_VERSION "v4.8" CACHE STRING "The .NET version to use for the projects")
set_property(CACHE DOT_NET_VERSION PROPERTY STRINGS v4.8 v4.6.1 v4.6.2)

set(WPF_REQIRED_XAML_SOURCE_FILES "")
set(WPF_REQIRED_CONFIG_FILES "")
set(WPF_REQIRED_PROPERTY_FILES "")

# Setup application config file

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/App.config")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/App.config.in
        ${CMAKE_CURRENT_SOURCE_DIR}/App.config
    )
endif()
list(APPEND WPF_REQIRED_CONFIG_FILES App.config)

# Setup minimum required source files

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/App.xaml")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/App.xaml.in
        ${CMAKE_CURRENT_SOURCE_DIR}/App.xaml
    )
endif()
set(WPF_REQIRED_XAML_SOURCE_FILES ${WPF_REQIRED_XAML_SOURCE_FILES} App.xaml)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/App.xaml.cs")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/App.xaml.cs.in
        ${CMAKE_CURRENT_SOURCE_DIR}/App.xaml.cs
    )
endif()
set(WPF_REQIRED_XAML_SOURCE_FILES ${WPF_REQIRED_XAML_SOURCE_FILES} App.xaml.cs)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.xaml.cs")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/MainWindow.xaml.cs.in
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.xaml.cs
    )
endif()
set(WPF_REQIRED_XAML_SOURCE_FILES ${WPF_REQIRED_XAML_SOURCE_FILES} MainWindow.xaml.cs)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.xaml")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/MainWindow.xaml.in
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.xaml
    )
endif()
set(WPF_REQIRED_XAML_SOURCE_FILES ${WPF_REQIRED_XAML_SOURCE_FILES} MainWindow.xaml)

# Setup propertiy files

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/AssemblyInfo.cs")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/Properties/AssemblyInfo.cs.in
        ${CMAKE_CURRENT_SOURCE_DIR}/Properties/AssemblyInfo.cs
    )
endif()
set(WPF_REQIRED_PROPERTY_FILES ${WPF_REQIRED_PROPERTY_FILES} Properties/AssemblyInfo.cs)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/Resources.Designer.cs")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/Properties/Resources.Designer.cs.in
        ${CMAKE_CURRENT_SOURCE_DIR}/Properties/Resources.Designer.cs
    )
endif()
set(WPF_REQIRED_PROPERTY_FILES ${WPF_REQIRED_PROPERTY_FILES} Properties/Resources.Designer.cs)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/Resources.resx")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/Properties/Resources.resx.in
        ${CMAKE_CURRENT_SOURCE_DIR}/Properties/Resources.resx
    )
endif()
set(WPF_REQIRED_PROPERTY_FILES ${WPF_REQIRED_PROPERTY_FILES} Properties/Resources.resx)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/Settings.Designer.cs")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/Properties/Settings.Designer.cs.in
        ${CMAKE_CURRENT_SOURCE_DIR}/Properties/Settings.Designer.cs
    )
endif()
set(WPF_REQIRED_PROPERTY_FILES ${WPF_REQIRED_PROPERTY_FILES} Properties/Settings.Designer.cs)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Properties/Settings.settings")
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/templates/Properties/Settings.settings.in
        ${CMAKE_CURRENT_SOURCE_DIR}/Properties/Settings.settings
    )
endif()
set(WPF_REQIRED_PROPERTY_FILES ${WPF_REQIRED_PROPERTY_FILES} Properties/Settings.settings)


#################################
function(add_csharp_executable)

    cmake_parse_arguments(
        pargs 
        ""
        "TARGET"
        "SOURCES;XAML_SOURCES"
        ${ARGN}
    )
    
    if(pargs_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "Unknown arguments: ${pargs_UNPARSED_ARGUMENTS}")
    endif()
    
    set(WPF_REQIRED_XAML_SOURCE_FILES ${WPF_REQIRED_XAML_SOURCE_FILES} ${pargs_XAML_SOURCES})
    
    message(STATUS "Target: ${pargs_TARGET}")
    message(STATUS "SOURCES: ${pargs_SOURCES}")
    message(STATUS "XAML_SOURCES: ${pargs_XAML_SOURCES}")
    message(STATUS "WPF_REQIRED_XAML_SOURCE_FILES: ${WPF_REQIRED_XAML_SOURCE_FILES}")
    
    add_executable(${pargs_TARGET}

        ${WPF_REQIRED_CONFIG_FILES}

        ${WPF_REQIRED_XAML_SOURCE_FILES}

        ${WPF_REQIRED_PROPERTY_FILES}
    
        ${pargs_SOURCES}
    )
    
    csharp_set_designer_cs_properties(
        ${WPF_REQIRED_PROPERTY_FILES}
    )
    
    csharp_set_xaml_cs_properties(
        ${WPF_REQIRED_XAML_SOURCE_FILES}
    )
    
    set_property(
        SOURCE
            App.xaml
        
        PROPERTY
            VS_XAML_TYPE "ApplicationDefinition"
    )
    
    set_property(
        TARGET
            ${pargs_TARGET}
        
        PROPERTY
            VS_DOTNET_TARGET_FRAMEWORK_VERSION "${DOT_NET_VERSION}"
    )
    
    set_property(
        TARGET
            ${pargs_TARGET}
        
        PROPERTY
            WIN32_EXECUTABLE TRUE
    )
    
    set_property(
        TARGET
            ${pargs_TARGET} 
            
        PROPERTY VS_DOTNET_REFERENCES
            "Microsoft.CSharp"
            "PresentationCore"
            "PresentationFramework"
            "System"
            "System.Core"
            "System.Data"
            "System.Data.DataSetExtensions"
            "System.Net.Http"
            "System.Xaml"
            "System.Xml"
            "System.Xml.Linq"
            "WindowsBase"
    )


endfunction(add_csharp_executable)
