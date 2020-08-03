cmake_minimum_required (VERSION 3.1)
project (glfreetype)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

# put all source code in one place for convenience
# note, when you do this in your own project, the src and include paths
# would likely be glfreetype/src/*.cpp and 
# glfreetype/include/glfreetpye/*.hpp respectively.
file(GLOB_RECURSE glfreetype src/ include/glfreetype/ *.hpp *.cpp)

# ensure headers in the src folder are compiler-found
# Note, in your own project the following include path 
# would likely be glfreetype/include
include_directories(include)
include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories( ${FREETYPE_INCLUDE_DIRS} )

# break above sub-folders into individual libraries
add_library(glfreetype ${glfreetype})
target_link_libraries(glfreetype ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES})

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast -ffast-math -funroll-loops")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g3 -frecord-gcc-switches -Wall -Wextra")

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(wintest test/main.cpp)

    find_package(glfw3 REQUIRED)
    find_package(Threads REQUIRED)
    target_link_libraries(wintest Threads::Threads)

    target_link_libraries(wintest glfreetype ${OPENGL_LIBRARIES} glfw3 ${CMAKE_DL_LIBS})
endif()
