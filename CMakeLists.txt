cmake_minimum_required(VERSION 3.10)

project(tuntaptcpip)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src test)

set(SRC 
src/IPv4.cc
src/ICMPv4.cc
src/Stack.cc
src/Buffer.cc
src/NetBuf.cc
src/NetDev.cc
src/TunIf.cc
src/Utils.cc)

set(UTEST
test/units/unit.cc)

#Test
add_executable(unit ${UTEST} ${SRC})
target_link_libraries(unit -lgtest -lpthread)

add_executable(tuntaptcpip src/main.cc ${SRC})

