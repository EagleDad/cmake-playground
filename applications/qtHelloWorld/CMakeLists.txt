set_compiler_flags( THIRD_PARTY )

# Don't use PROJECT_NAME as target name, it's too tight of a relationship
set(EXECUTABLE_NAME "qtHelloWorld")

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
qt_standard_project_setup()


qt_add_executable(${EXECUTABLE_NAME} 
    codeeditor.cpp
    codeeditor.h
    main.cpp
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()

target_include_directories(${EXECUTABLE_NAME}
    INTERFACE
    
    PUBLIC
)

copy_runtime_dependencies(
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    #MACOSX_BUNDLE ON
)

set_target_properties( Qt6::Widgets
    PROPERTIES
        MAP_IMPORTED_CONFIG_COVERAGE "RELEASE"
)

set_target_properties( Qt6::Core
    PROPERTIES
        MAP_IMPORTED_CONFIG_COVERAGE "RELEASE"
)

set_target_properties( Qt6::Gui
    PROPERTIES
        MAP_IMPORTED_CONFIG_COVERAGE "RELEASE"
)

target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets

    PRIVATE

    INTERFACE
)