project(ConsoleHook)

add_compile_definitions(CONSOLEHOOK_API)

add_library(
  ${PROJECT_NAME}
  SHARED
    ConsoleHandler.cpp
    ConsoleHandler.h
    ConsoleHook.cpp
    ConsoleHook.h
    ConsoleHook.rc
    resource.h
    stdafx.cpp
)

target_precompile_headers(
  ${PROJECT_NAME}
  PUBLIC
    stdafx.h
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
    User32
    shell32
    Boost::boost
)