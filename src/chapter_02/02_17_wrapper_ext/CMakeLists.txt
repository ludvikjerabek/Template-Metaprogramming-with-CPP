file(GLOB headers *.h)
get_filename_component(name_of_project "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
add_executable(${name_of_project} source1.cpp source2.cpp main.cpp ${headers})