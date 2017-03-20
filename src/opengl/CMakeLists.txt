set(QCW_OPENGL_SOURCES
        glwidget.cpp
        helper.cpp)

set(QCW_OPENGL_HEADERS
        glwidget.hpp
        helper.hpp)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        OpenGL)

add_library(opengl
        ${QCW_OPENGL_SOURCES}
        ${QCW_OPENGL_HEADERS})

target_link_libraries(opengl
        Qt5::Core
        Qt5::OpenGL)

target_include_directories(opengl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
