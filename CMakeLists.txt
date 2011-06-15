project(FujiModelViewer_qt)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(Fuji REQUIRED)

include_directories(${QT_INCLUDES} ${FUJI_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(FujiModelViewer_qt_SRCS FujiModelViewer_qt.cpp FujiWidget.cpp main.cpp)
qt4_automoc(${FujiModelViewer_qt_SRCS})
add_executable(FujiModelViewer_qt ${FujiModelViewer_qt_SRCS})
target_link_libraries(FujiModelViewer_qt ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${FUJI_LIBRARIES})
