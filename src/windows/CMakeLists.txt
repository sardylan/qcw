set(QCW_WINDOWS_WIDGET_SOURCES
        widget/glwidget.cpp)

set(QCW_WINDOWS_WIDGET_HEADERS
        widget/glwidget.hpp)

set(QCW_WINDOWS_MAIN
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui)

set(QCW_WINDOWS_CONFIG
        configwindow.cpp
        configwindow.hpp
        configwindow.ui)

set(QCW_WINDOWS_ABOUT
        aboutwindow.cpp
        aboutwindow.hpp
        aboutwindow.ui)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Widgets
        Gui
        SerialPort
        OpenGL)

add_library(windows
        ${QCW_WINDOWS_WIDGET_SOURCES}
        ${QCW_WINDOWS_WIDGET_HEADERS}
        ${QCW_WINDOWS_MAIN}
        ${QCW_WINDOWS_CONFIG}
        ${QCW_WINDOWS_ABOUT})

target_link_libraries(windows
        config
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::SerialPort
        Qt5::OpenGL)

target_include_directories(windows PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
