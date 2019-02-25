cmake_minimum_required(VERSION 3.13)
project(SortAlgorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(SortAlgorithm
        main.c
        src/sort_api.h
        src/sort_public.h
        src/Bubblesort.c
        src/Bucketsort.c
        src/Combsort.c
        src/Comparisonsort.c
        src/Heapsort.c
        src/Introsort.c
        src/Mergesort.c
        src/Quicksort.c
        src/Radixsort.c
        src/Timsort.c
        SortTest/SortTest.c
        SortTest/SortTest.h
        SortTest/Debug.c
        SortTest/Debug.h)