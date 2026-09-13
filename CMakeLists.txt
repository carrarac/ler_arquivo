cmake_minimum_required(VERSION 4.0)

project("FerramentaCli" C)

add_executable(analise src/analise.c)

target_include_directories(analise PRIVATE "include/")
