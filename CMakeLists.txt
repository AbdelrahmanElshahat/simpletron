cmake_minimum_required(VERSION 3.20)
project(Simplemachine C)

set(CMAKE_C_STANDARD 99)

add_executable(Simplemachine
        "main.c"
       "Simpletron_UI.c"
        "Simpletron_UI.h"
        "SML_exe.c"
        "SML_exe.h"
        "Recive_instructions.c"
        "Excute.c"
        "Fetch&Decode.c")
