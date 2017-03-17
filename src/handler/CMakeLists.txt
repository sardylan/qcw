set(QCW_HANDLER_SOURCES
        serialhandler.cxx)

set(QCW_HANDLER_HEADERS
        serialhandler.hxx)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        SerialPort)

add_library(handler
        ${QCW_HANDLER_SOURCES}
        ${QCW_HANDLER_HEADERS})

target_link_libraries(handler
        Qt5::Core
        Qt5::SerialPort)

target_include_directories(handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
