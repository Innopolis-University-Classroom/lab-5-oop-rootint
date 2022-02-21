cmake_minimum_required(VERSION 3.10)

project(test VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)

# include_directories("headers/" "more_headers/")

add_executable(main example_main.cpp)
add_executable(landlord landlord.cpp)

# target_include_directories(test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")

# pkg_check_modules(GLUT_CXX IMPORTED_TARGET REQUIRED glut)
# target_link_libraries(test PkgConfig::GLUT_CXX)
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL -framework GLUT")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL")