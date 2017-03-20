set(QCW_WINDOWS_MAIN
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Widgets
        Gui
        SerialPort
        OpenGL)

add_library(windows
        ${QCW_WINDOWS_MAIN})

target_link_libraries(windows
        config
        opengl
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::SerialPort
        Qt5::OpenGL)

target_include_directories(windows PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
