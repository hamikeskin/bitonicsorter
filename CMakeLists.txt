cmake_minimum_required(VERSION 3.19)
project(bitonicsorter C)

set(CMAKE_C_STANDARD 99)

add_executable(bitonicsorter main.c bitonicsorter.c bitonicsorter.h)