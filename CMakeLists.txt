cmake_minimum_required(VERSION 3.8)
project(templatesbook)

include(CMakePrintHelpers)


if(MSVC)
  message(status "Setting MSVC flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /Zc:__cplusplus /std:c++latest")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
  message(status "Setting GCC/Clang flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fexceptions -g -Wall")
endif()

file(GLOB V_GLOB_CHAPTERS LIST_DIRECTORIES true "src/*")
foreach(chapter ${V_GLOB_CHAPTERS})
  if(IS_DIRECTORY ${chapter})
    cmake_print_variables("Chapter: ${chapter}")
    file(GLOB V_GLOB_ASSIGNMENT LIST_DIRECTORIES true "${chapter}/*")
    foreach(assignment ${V_GLOB_ASSIGNMENT})
      if(IS_DIRECTORY ${assignment})
        cmake_print_variables("Assignment: ${assignment}")
        add_subdirectory(${assignment})
      endif()
    endforeach()
  endif()
endforeach()
