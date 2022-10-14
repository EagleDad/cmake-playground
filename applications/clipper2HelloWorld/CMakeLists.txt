set_compiler_flags(THIRD_PARTY)

# Don't use PROJECT_NAME as target name, it's too tight of a relationship
set(EXECUTABLE_NAME "clipper2helloworld")

find_package(Clipper2 REQUIRED QUIET)

include_directories( ${CLIPPER2_INCLUDE_DIRS} )

add_executable(${EXECUTABLE_NAME}
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
    Clipper2::Clipper2
    Clipper2::Clipper2Z
)

target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC
        Clipper2::Clipper2
        Clipper2::Clipper2Z
    PRIVATE
        
    INTERFACE
)