# Copyright (c) 2008-2016 Andrew Sutton
# All rights reserved

cmake_minimum_required(VERSION 3.29)
project(graph CXX)

macro(add_unit_test target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} graph)
endmacro()

add_subdirectory(include)
add_subdirectory(tests)
