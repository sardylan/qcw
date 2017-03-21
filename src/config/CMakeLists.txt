set(QCW_CONFIG_SOURCES
        config.cpp
        manager.cpp)

set(QCW_CONFIG_HEADERS
        default.hpp
        config.hpp
        manager.hpp)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        SerialPort)

add_library(config
        ${QCW_CONFIG_SOURCES}
        ${QCW_CONFIG_HEADERS})

target_link_libraries(config
        Qt5::Core
        Qt5::SerialPort)

target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
