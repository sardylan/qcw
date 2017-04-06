add_subdirectory(config)
add_subdirectory(handler)
add_subdirectory(morsecodec)
add_subdirectory(windows)

set(QCW_SOURCES
        qcw.cpp)

set(QCW_HEADERS
        version.hpp
        qcw.hpp)

set(QCW_RESOURCES
        qcw.rc
        resources.qrc)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Svg
        Widgets
        SerialPort
        OpenGL)

set(QCW_MAC_ICON_NAME icon.icns)
set(QCW_MAC_ICON_PATH ../icons/macos/icon.icns)

set_source_files_properties(${QCW_MAC_ICON_PATH}
        PROPERTIES
        MACOSX_PACKAGE_LOCATION
        Resources)

set(MACOSX_BUNDLE_EXECUTABLE_NAME qcw)
set(MACOSX_BUNDLE_BUNDLE_NAME qCw)
set(MACOSX_BUNDLE_ICON_FILE ${QCW_MAC_ICON_NAME})

add_executable(qcw
        WIN32 MACOSX_BUNDLE
        ${QCW_SOURCES}
        ${QCW_HEADERS}
        ${QCW_RESOURCES}
        ${QCW_MAC_ICON_PATH})

target_link_libraries(qcw
        config
        handler
        morsecodec
        windows
        Qt5::Core
        Qt5::Gui
        Qt5::Svg
        Qt5::Widgets
        Qt5::SerialPort
        Qt5::OpenGL)

set_target_properties(qcw
        PROPERTIES
        MACOSX_BUNDLE_ICON_FILE
        ${QCW_MAC_ICON_NAME})
