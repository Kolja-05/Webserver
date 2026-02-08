cmake_minimum_required(VERSION 3.5)
project(RN-Praxis)
set(CMAKE_C_STANDARD 11)

add_executable(webserver ./src/webserver.c ./src/http_parser.c)
target_compile_options(webserver PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(webserver PRIVATE -lm)

