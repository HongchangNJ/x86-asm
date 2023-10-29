cmake_minimum_required(VERSION 3.23)
project(ziya_test C )
set(CMAKE_C_FLAGS   "-masm=intel")
#set(CMAKE-C_FLAGS "-m32")

add_executable(ziya_test main.c)
