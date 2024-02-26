cmake_minimum_required(VERSION 3.27)
project(Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "/Users/al.deshkovets/Qt/6.6.1/macos/lib/cmake")

find_package(Qt6Widgets REQUIRED)
find_package(Qt6Network REQUIRED)
find_package(Qt6Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(Client main.cpp
        Resources/MainWindow.cpp
        Headers/MainWindow.h
)
target_link_libraries(Client Qt6::Widgets Qt6::Network Qt6::Gui)