set(QCW_WINDOWS_SOURCES
        mainwindow.cxx)

set(QCW_WINDOWS_HEADERS
        mainwindow.hxx)

set(QCW_WINDOWS_UIS
        mainwindow.ui)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Widgets
        Gui
        SerialPort
        OpenGL)

add_library(windows
        ${QCW_WINDOWS_SOURCES}
        ${QCW_WINDOWS_HEADERS}
        ${QCW_WINDOWS_UIS})

target_link_libraries(windows
        handler
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::SerialPort
        Qt5::OpenGL)

target_include_directories(windows PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})