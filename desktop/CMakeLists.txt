cmake_minimum_required(VERSION 3.21)

project(DrawingBoardDesktop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Gui Widgets WebEngineWidgets WebChannel)

add_executable(DrawingBoardDesktop WIN32
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/nativebridge.h
    src/nativebridge.cpp
    resources/resources.qrc
    resources/app.rc
)

target_link_libraries(DrawingBoardDesktop
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::WebEngineWidgets
        Qt6::WebChannel
)

install(TARGETS DrawingBoardDesktop RUNTIME DESTINATION bin)
