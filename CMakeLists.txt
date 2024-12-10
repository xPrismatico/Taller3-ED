cmake_minimum_required(VERSION 3.26)
project(taller_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(taller_3 main.cpp

        cmake-build-debug/workers.csv
        cmake-build-debug/minecare_events.csv
        Sistema.cpp
        Sistema.h
        Operador.cpp
        Operador.h
        Evento.cpp
        Evento.h
        NodoEvento.cpp
        NodoEvento.h
        MaxHeap.cpp
        MaxHeap.h
        NodoOperador.cpp
        NodoOperador.h
        AVL.cpp
        AVL.h

)
