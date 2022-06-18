project(FreeImage)

add_library(
  ${PROJECT_NAME}
  INTERFACE
    FreeImage.h
    FreeImagePlus.h
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/x64/FreeImagePlus.lib
)

install(FILES ${CMAKE_SOURCE_DIR}/setup/dlls/x64/FreeImagePlus.dll
        DESTINATION bin
)