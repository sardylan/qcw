add_subdirectory(config)
add_subdirectory(handler)
add_subdirectory(windows)

set(QCW_SOURCES
        qcw.cpp)

set(QCW_HEADERS
        qcw.hpp)

set(QCW_RESOURCES
        qcw.rc
        resources.qrc)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        SerialPort
        OpenGL)

add_executable(qcw WIN32
        ${QCW_SOURCES}
        ${QCW_HEADERS}
        ${QCW_RESOURCES})

target_link_libraries(qcw
        config
        handler
        windows
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::SerialPort
        Qt5::OpenGL)
