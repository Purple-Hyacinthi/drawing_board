cmake_minimum_required(VERSION 3.21)

project(DrawingBoardDesktop LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Gui Widgets Test)

add_executable(DrawingBoardDesktop WIN32
    src/main.cpp
    src/canvassharedtypes.h
    src/canvaswidget.h
    src/canvaswidget.cpp
    src/canvasfilecodec.h
    src/canvasfilecodec.cpp
    src/canvasfilters.h
    src/canvasfilters.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    resources/resources.qrc
    resources/app.rc
)

target_link_libraries(DrawingBoardDesktop
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

if(BUILD_TESTING)
    add_executable(DrawingBoardDesktopTests
        tests/canvasmodules_test.cpp
        src/canvassharedtypes.h
        src/canvasfilecodec.h
        src/canvasfilecodec.cpp
        src/canvasfilters.h
        src/canvasfilters.cpp
        src/canvaswidget.h
        src/canvaswidget.cpp
    )

    target_link_libraries(DrawingBoardDesktopTests
        PRIVATE
            Qt6::Core
            Qt6::Gui
            Qt6::Widgets
            Qt6::Test
    )

    add_test(NAME DrawingBoardDesktopTests COMMAND $<TARGET_FILE:DrawingBoardDesktopTests>)
    set_tests_properties(DrawingBoardDesktopTests PROPERTIES
        ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:$<TARGET_FILE_DIR:Qt6::Core>"
        ENVIRONMENT "QT_QPA_PLATFORM_PLUGIN_PATH=$<TARGET_FILE_DIR:Qt6::Core>/../plugins/platforms;QT_PLUGIN_PATH=$<TARGET_FILE_DIR:Qt6::Core>/../plugins"
    )
endif()

install(TARGETS DrawingBoardDesktop RUNTIME DESTINATION bin)
