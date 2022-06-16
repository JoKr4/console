project(consolez)

cmake_minimum_required(VERSION 3.23)

set(CXX_STANDARD 17)

find_package(Boost 1.76.0 REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")

#set(WLT_DIR "" CACHE STRING "Dir with WTL")

add_subdirectory(Console)
add_subdirectory(TabbingFramework)
add_subdirectory(wtl)