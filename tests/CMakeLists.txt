# Copyright (c) 2016 Andrew Sutton
# All rights reserved

enable_testing()

add_unit_test(test-dfs-undirected undirected.cpp)
add_unit_test(test-dfs-directed directed.cpp)

add_unit_test(test-digraph digraph.cpp)
add_unit_test(test-graph graph.cpp)
add_unit_test(test-queue-insertion insertion.cpp)