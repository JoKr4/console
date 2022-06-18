project(ConsoleWow)

add_executable(
  ${PROJECT_NAME}
    ConsoleWow.cpp
    ConsoleWow.rc
    targetver.h
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

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
)