cmake_minimum_required(VERSION 3.0.0)
project(Level_1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    ${PROJECT_NAME}
    
    src/default_library.cpp
    src/segment_display.cpp
    src/recursion.cpp
    src/pointers.cpp
    src/driver.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
execute_process(COMMAND "cd build")
execute_process(COMMAND "Level_1.exe")