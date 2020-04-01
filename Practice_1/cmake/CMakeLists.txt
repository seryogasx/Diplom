project(Diplom_Practice1)

find_package(Boost  REQUIRED)
if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost")
	return()
else()
	include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(Diplom_Practice1 main.cpp)

target_link_libraries(Diplom_Practice_1 ${Boost_LIBRARIES})
