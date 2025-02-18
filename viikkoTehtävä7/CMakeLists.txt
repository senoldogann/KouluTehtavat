cmake_minimum_required(VERSION 3.16)
project(calculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.16")
find_package(Qt5 REQUIRED COMPONENTS Widgets)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

add_executable(calculator
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(calculator PRIVATE Qt5::Widgets) 