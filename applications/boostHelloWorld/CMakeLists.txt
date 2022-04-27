project(BoostHelloWorld)

set_compiler_flags(THIRD_PARTY)

# Don't use PROJECT_NAME as target name, it's too tight of a relationship
set(EXECUTABLE_NAME "boosthelloworld")

add_executable(${EXECUTABLE_NAME}
    main.cpp
)

if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "applications")
endif()

find_package(Boost  REQUIRED COMPONENTS filesystem )

target_include_directories(${EXECUTABLE_NAME}
    INTERFACE
    
    PUBLIC
        Boost::headers
        #${Boost_INCLUDE_DIR}
)

target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC
        Boost::filesystem
        #${Boost_LIBRARIES}
    PRIVATE
        
    INTERFACE
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