cmake_minimum_required(VERSION 2.8)
project(Game)

set(CMAKE_CXX_STANDARD 14)

if(DEBUG)
    add_subdirectory(googletest)
    include_directories(googletest/googletest/include)
    include_directories(googletest/googlemock/include)
endif()

include_directories(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
if(DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG=1")
    include_directories(test)
    set(SOURCE_DEBUG_FILES test/Test.cpp)
endif()

set(SOURCE_FILES src/main.cpp src/Rule.h src/EarleyParser.cpp src/EarleyParser.h)

add_executable(second-practical-work ${SOURCE_FILES} ${SOURCE_DEBUG_FILES})
if(DEBUG)
    target_link_libraries(second-practical-work gtest gtest_main)
endif()