project(consolez)

cmake_minimum_required(VERSION 3.23)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1) # for clangd
set(CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc") # exceptions enabled with model 'sc'
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)
add_compile_definitions(NDEBUG)
add_compile_definitions(FREEIMAGE_LIB)

# https://docs.microsoft.com/en-us/cpp/build/reference/subsystem-specify-subsystem?view=msvc-170
add_link_options("/SUBSYSTEM:WINDOWS")

# the next one was hard...
# before llvm_rc a preprocessor must run for the includes of .rc files
# cmake uses the C or CXX defined compiler for that (so clang-cl) BUT gives it the same flags as for RC Compiler
# as it seems, clang-cl does not support "-I" for includes
# but clang (no -cl!) does, so just exchange this executable instead of figuring out how <INCLUDES> could be manipulated here
# see https://bugzilla.mozilla.org/show_bug.cgi?id=1537703
# see https://github.com/Kitware/CMake/commit/1c2d031cbdbf28f99ef36e5db5e4d9de1b97fff9
#message("!!!!!!!!!!!!!!!! ${CMAKE_RC_COMPILE_OBJECT}")
set(CMAKE_RC_COMPILE_OBJECT "<CMAKE_COMMAND> -E cmake_llvm_rc <SOURCE> <OBJECT>.pp clang <DEFINES> -DRC_INVOKED <INCLUDES> <FLAGS> -E -- <SOURCE> ++ <CMAKE_RC_COMPILER> <DEFINES> -I <SOURCE_DIR> <INCLUDES> <FLAGS> /fo <OBJECT> <OBJECT>.pp")

find_package(Boost 1.76.0 REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")

add_subdirectory(Console)
add_subdirectory(TabbingFramework)
add_subdirectory(wtl)
add_subdirectory(shared)
add_subdirectory(FreeImage)
add_subdirectory(ConsoleHook)