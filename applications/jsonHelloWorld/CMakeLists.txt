set_compiler_flags(THIRD_PARTY)

# Don't use PROJECT_NAME as target name, it's too tight of a relationship
set(EXECUTABLE_NAME "jsonhelloworld")

find_package(nlohmann_json REQUIRED QUIET)

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

)

target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC
        nlohmann_json::nlohmann_json
    PRIVATE
        
    INTERFACE
)