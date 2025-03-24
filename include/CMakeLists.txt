# Copyright (c) 2016 Andrew Sutton
# All rights reserved

add_library(graph INTERFACE)
target_sources(graph
  PUBLIC
    FILE_SET
      HEADERS
    FILES
      utility.hpp
      common.hpp
      graph.hpp
      digraph.hpp
      output.hpp
      dfs.hpp
      queue.hpp)