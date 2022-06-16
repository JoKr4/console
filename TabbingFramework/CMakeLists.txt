project(TabbingFramework)

add_library(
  ${PROJECT_NAME}
  STATIC
    atlgdix.h
    CustomTabCtrl.h
    DotNetTabCtrl.h
    DynamicDialogTemplate.h
    ImageUtil.h
    ListViewNoFlicker.h
    PlainTextView.h
    SimpleDlgTabCtrls.h
    SimpleTabCtrls.h
    TabbedDockingWindow.h
    TabbedFrame.h
    TabbedMDI.h
    TabbedMDIMessages.h
    TabbedMDISave.cpp
    TabbedMDISave.h  
)

target_precompile_headers(
  ${PROJECT_NAME}
  PUBLIC
    stdafx.h
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
    shared
    wtl
)