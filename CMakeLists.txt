project(consolez)

cmake_minimum_required(VERSION 3.23)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1) # for clangd
set(CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)
add_compile_definitions(NDEBUG)
#add_compile_definitions(WINAPI_FAMILY=100) # 100 = WINAPI_PARTITION_DESKTOP

#set(WINSDK_BASE "C:\\Users\\Johannes\\home\\Develop\\lib\\winsdk\\Include\\10.0.19041.0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc") # exceptions on with model 'sc'
#set(CMAKE_RC_FLAGS "${CMAKE_RC_FLAGS} -I ${WINSDK_BASE}\\um -I ${WINSDK_BASE}\\shared")

#message("!!!!!!!!!!!!!!!! ${CMAKE_RC_COMPILE_OBJECT}")
set(CMAKE_RC_COMPILE_OBJECT "<CMAKE_COMMAND> -E cmake_llvm_rc <SOURCE> <OBJECT>.pp clang <DEFINES> -DRC_INVOKED <INCLUDES> <FLAGS> -E -- <SOURCE> ++ <CMAKE_RC_COMPILER> <DEFINES> -I <SOURCE_DIR> <INCLUDES> <FLAGS> /fo <OBJECT> <OBJECT>.pp")


find_package(Boost 1.76.0 REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")

add_subdirectory(Console)
add_subdirectory(TabbingFramework)
add_subdirectory(wtl)
add_subdirectory(shared)