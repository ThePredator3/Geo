cmake_minimum_required(VERSION 3.27)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "/Users/al.deshkovets/Qt/6.6.1/macos/lib/cmake")

find_package(Qt6Widgets REQUIRED)
find_package(Qt6Network REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(Server main.cpp
        Resources/Soil.cpp
        Headers/Soil.h
        Resources/Sand.cpp
        Headers/Sand.h
        Resources/SoilData.cpp
        Headers/SoilData.h
        Resources/Server.cpp
        Headers/Server.h
)

target_link_libraries(Server Qt6::Widgets Qt6::Network)
