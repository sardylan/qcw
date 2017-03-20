add_subdirectory(config)
add_subdirectory(handler)
add_subdirectory(opengl)
add_subdirectory(windows)

set(QCW_SOURCES
        qcw.cpp)

set(QCW_HEADERS
        qcw.hpp)

set(QCW_RESOURCES
        resources.qrc)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Widgets
        Gui
        SerialPort
        OpenGL)

add_executable(qcw
        ${QCW_SOURCES}
        ${QCW_HEADERS}
        ${QCW_RESOURCES})

target_link_libraries(qcw
        config
        handler
        opengl
        windows
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::SerialPort
        Qt5::OpenGL)
