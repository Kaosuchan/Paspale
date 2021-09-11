cmake_minimum_required(VERSION 3.0.0)
project(Paspale VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(src)
aux_source_directory(src PaspaleSrc)
aux_source_directory(test PaspaleTest)
add_library(Paspale ${PaspaleSrc})
add_executable(Pas test.c ${PaspaleTest})
target_link_libraries(Pas Paspale)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
