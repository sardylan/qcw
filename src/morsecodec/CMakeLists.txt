set(QCW_MORSECODEC_SOURCES
        encoder.cpp)

set(QCW_MORSECODEC_HEADERS
        encoder.hpp)

find_package(Qt5 REQUIRED COMPONENTS
        Core)

add_library(morsecodec
        ${QCW_MORSECODEC_SOURCES}
        ${QCW_MORSECODEC_HEADERS})

target_link_libraries(morsecodec
        Qt5::Core)

target_include_directories(morsecodec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
