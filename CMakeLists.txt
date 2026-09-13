cmake_minimum_required(VERSION 4.0)

project("FerramentaCli" C)

add_library(arquivo STATIC src/arquivo.c)
add_executable(analise src/analise.c)

target_include_directories(arquivo PUBLIC "include/")
target_include_directories(analise PRIVATE "include/")

target_link_libraries(analise PRIVATE arquivo)

