cmake_minimum_required(VERSION 2.8)
project("Complex")

set(HEADERS)
set(SOURCE)
	
add_subdirectory(src) 

add_executable(Complex ${HEADERS} ${SOURCE})