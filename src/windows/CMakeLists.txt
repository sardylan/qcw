set(QCW_WINDOWS_MAIN
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui)

set(QCW_WINDOWS_CONFIG
        configwindow.cpp
        configwindow.hpp
        configwindow.ui)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Widgets
        Gui
        SerialPort
        OpenGL)

add_library(windows
        ${QCW_WINDOWS_MAIN}
        ${QCW_WINDOWS_CONFIG})

target_link_libraries(windows
        config
        opengl
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::SerialPort
        Qt5::OpenGL)

target_include_directories(windows PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
