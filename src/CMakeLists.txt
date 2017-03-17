set(QCW_SOURCES
        qcw.cpp
        mainwindow.cxx
        serialhandler.cpp)

set(QCW_HEADERS
        mainwindow.hxx
        serialhandler.hxx)

set(QCW_UIS
        mainwindow.ui)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui SerialPort Charts)

add_executable(qcw ${QCW_SOURCES} ${QCW_HEADERS})
target_link_libraries(qcw Qt5::Core Qt5::Widgets Qt5::Gui Qt5::SerialPort Qt5::Charts)
