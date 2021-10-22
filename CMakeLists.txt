cmake_minimum_required(VERSION 3.0)

project(my_shared_pointer_test)

add_executable(my_shared_pointer_test src/main.cpp)

install(TARGETS my_shared_pointer_test DESTINATION bin)