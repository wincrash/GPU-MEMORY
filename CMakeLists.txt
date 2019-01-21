cmake_minimum_required(VERSION 2.8)

project(GPU-MEMORY)

find_package(OpenCL)
include_directories(${OpenCL_INCLUDE_DIR})

#-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
SET(MY_GCC_COMPILE_FLAGS "-w")
add_definitions(${MY_GCC_COMPILE_FLAGS})
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MY_GCC_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${MY_GCC_COMPILE_FLAGS}" )


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS log )
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK=0)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cxx")
target_link_libraries(${PROJECT_NAME}   -lpthread -lboost_log -lstdc++fs  -lOpenCL)
