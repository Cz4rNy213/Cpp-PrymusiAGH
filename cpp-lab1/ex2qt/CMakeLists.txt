cmake_minimum_required(VERSION 3.5)

project(ex2qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex2qt main.cpp
    add.h
    add.h
    add.cpp)

include(GNUInstallDirs)
install(TARGETS ex2qt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
