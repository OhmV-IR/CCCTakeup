cmake_minimum_required(VERSION 3.8)
project(CCCTakeup)

file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${child} AND NOT child STREQUAL ".github")
        add_subdirectory(${child})
    endif()
endforeach()