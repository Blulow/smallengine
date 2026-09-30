cmake_minimum_required(VERSION 3.10.0)
project(thesmallengine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE G_SOURCES "src/*.cpp" "src/*.c")
file(GLOB_RECURSE G_HEADERS "src/*.hpp" "src/*.h")

add_subdirectory(external/glad)

add_executable(thesmallengine ${G_SOURCES} ${G_HEADERS})
target_include_directories(thesmallengine PUBLIC include)

target_link_libraries(thesmallengine PRIVATE opengl32 glad)


