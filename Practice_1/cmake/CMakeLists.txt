cmake_minimum_required(VERSION 3.17)

project(Diplom_Practice1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES sources/main.cpp sources/sort_test.cpp)
set(HEADERS sources/sort_test.hpp)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost")
	return()
else()
	include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(Diplom_Practice_1 sources/main.cpp)

target_link_libraries(Diplom_Practice_1 LINK_PUBLIC ${Boost_LIBRARIES})