cmake_minimum_required(VERSION 3.10)
project(KolomietsProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Створення статичної бібліотеки з файлу calculator.cpp
add_library(calculator STATIC calculator.cpp)

# Створення виконуваного файлу Kolomiets_app
add_executable(Kolomiets_app main.cpp)

# Підключення бібліотеки 
target_link_libraries(Kolomiets_app calculator)