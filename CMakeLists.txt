cmake_minimum_required(VERSION 3.8)
project(templatesbook)
  

if(MSVC)
  message(status "Setting MSVC flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /Zc:__cplusplus /std:c++latest")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
  message(status "Setting GCC/Clang flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fexceptions -g -Wall")
endif()

file(GLOB V_GLOB LIST_DIRECTORIES true "src/*")
foreach(item ${V_GLOB})
  if(IS_DIRECTORY ${item})
    add_subdirectory(${item})
  endif()
endforeach()
