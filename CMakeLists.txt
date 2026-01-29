# Version minimale de CMake requise
cmake_minimum_required(VERSION 3.10)

project(Systeme_Ventilation_C)


set(CMAKE_C_STANDARD 99)


include_directories(src)


set(SOURCES 
    src/buffer.c 
    src/sensor.c 
    src/ventilation.c
)


add_library(VentilationCore STATIC ${SOURCES})

message(STATUS "Configuration du projet de ventilation terminée.")
