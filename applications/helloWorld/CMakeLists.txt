project(HelloWorld)

# Don't use PROJECT_NAME as target name, it's too tight of a relationship
set(EXECUTABLE_NAME "helloworld")

add_executable(${EXECUTABLE_NAME}
    main.cpp
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()

target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC
       MyProject::SharedLibrary
    PRIVATE
)

install(TARGETS ${EXECUTABLE_NAME}
    ARCHIVE  DESTINATION "lib"
    LIBRARY  DESTINATION "bin"
    RUNTIME  DESTINATION "bin"
)

install(
    FILES
    DESTINATION
        "bin"
)
