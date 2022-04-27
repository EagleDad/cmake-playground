project (SharedLibrary_Python)

set(LIBRARY_NAME "MyProject::SharedLibrary::Python")
get_raw_target_name(${LIBRARY_NAME} LIBRARY_NAME_RAW)

message([${PROJECT_NAME}] " Raw name: ${LIBRARY_NAME_RAW}")

find_package(pybind11 REQUIRED)

pybind11_add_module(${LIBRARY_NAME_RAW}
   src/sharedLibraryPython.cpp
   python/example.py
)

# Write own function to add test and do grouping there
if(ENABLE_SOLUTION_FOLDERS)
    set_target_properties(${LIBRARY_NAME_RAW} PROPERTIES FOLDER "python")
endif()


target_link_libraries(${LIBRARY_NAME_RAW}
    PRIVATE
        MyProject::SharedLibrary
    INTERFACE
)

# Tell CMake how to install our library
install(TARGETS ${LIBRARY_NAME_RAW}
    ARCHIVE  DESTINATION "lib"
    LIBRARY  DESTINATION "bin"
    RUNTIME  DESTINATION "bin"
)