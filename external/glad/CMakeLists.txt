cmake_minimum_required(VERSION 3.10.0)
project(glad)

add_library(glad src/gl.c src/wgl.c)
# target_sources(glad src/gl.c src/wgl.c)
target_include_directories(glad PUBLIC include)