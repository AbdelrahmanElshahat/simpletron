cmake_minimum_required(VERSION 3.20)
project(simpletron C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(simpletron
        main.c
        Simpletron_UI.c
        Simpletron_UI.h
        SML_exe.c
        SML_exe.h)
