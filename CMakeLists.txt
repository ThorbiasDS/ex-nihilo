cmake_minimum_required(VERSION 3.22.1)
project(ex-nihilo VERSION 1.0 LANGUAGES CXX)

include_directories(include)

add_executable(program src/main.cpp src/Musica.cpp src/Playlist.cpp)