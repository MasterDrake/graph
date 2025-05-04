# Copyright 2020, 2021 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...3.16)

set(VCPKG_LIBRARY_LINKAGE static)
set(VCPKG_MAX_CONCURRENCY 12)

# Set the runtime library to static for the entire project
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

if (WIN32)
	include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
elseif (UNIX)
    include("/home/$ENV{USER}/GameDev/Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

project(boost_graph VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

add_library(boost_graph
  #src/graphml.cpp
  #src/read_graphviz_new.cpp
)

add_library(Boost::graph ALIAS boost_graph)

target_include_directories(boost_graph PUBLIC include)

find_package(Boost REQUIRED COMPONENTS config)

find_package(Boost REQUIRED COMPONENTS assert)

find_package(Boost REQUIRED COMPONENTS throw_exception)

find_package(Boost REQUIRED COMPONENTS core)

find_package(Boost REQUIRED COMPONENTS container_hash)

find_package(Boost REQUIRED COMPONENTS unordered)

find_package(Boost REQUIRED COMPONENTS type_traits)

find_package(Boost REQUIRED COMPONENTS tuple)

find_package(Boost REQUIRED COMPONENTS smart_ptr)

find_package(Boost REQUIRED COMPONENTS preprocessor)

find_package(Boost REQUIRED COMPONENTS utility)

find_package(Boost REQUIRED COMPONENTS mpl)

find_package(Boost REQUIRED COMPONENTS integer)

find_package(Boost REQUIRED COMPONENTS concept_check)

find_package(Boost REQUIRED COMPONENTS regex)

find_package(Boost REQUIRED COMPONENTS optional)

find_package(Boost REQUIRED COMPONENTS detail)

find_package(Boost REQUIRED COMPONENTS function)


find_package(Boost REQUIRED COMPONENTS iterator)

find_package(Boost REQUIRED COMPONENTS conversion)

find_package(Boost REQUIRED COMPONENTS array)

find_package(Boost REQUIRED COMPONENTS range)

find_package(Boost REQUIRED COMPONENTS algorithm)

find_package(Boost REQUIRED COMPONENTS move)

find_package(Boost REQUIRED COMPONENTS multi_index)

find_package(Boost REQUIRED COMPONENTS bimap)

find_package(Boost REQUIRED COMPONENTS foreach)

find_package(Boost REQUIRED COMPONENTS lexical_cast)

find_package(Boost REQUIRED COMPONENTS random)

find_package(Boost REQUIRED COMPONENTS math)

find_package(Boost REQUIRED COMPONENTS parameter)

find_package(Boost REQUIRED COMPONENTS property_map)

find_package(Boost REQUIRED COMPONENTS serialization)

find_package(Boost REQUIRED COMPONENTS property_tree)

find_package(Boost REQUIRED COMPONENTS tti)

find_package(Boost REQUIRED COMPONENTS xpressive)

find_package(EASTL CONFIG REQUIRED)
target_link_libraries(boost_graph PRIVATE EASTL)

target_link_libraries(boost_graph
  PUBLIC
    Boost::algorithm
    Boost::array
    Boost::assert
    Boost::bimap
    Boost::concept_check
    Boost::config
    Boost::container_hash
    Boost::conversion
    Boost::core
    Boost::detail
    Boost::foreach
    Boost::function
    Boost::integer
    Boost::iterator
    Boost::lexical_cast
    Boost::math
    Boost::move
    Boost::mpl
    Boost::multi_index
    Boost::optional
    Boost::parameter
    Boost::preprocessor
    Boost::property_map
    Boost::property_tree
    Boost::random
    Boost::range
    Boost::serialization
    Boost::smart_ptr
    Boost::spirit
    Boost::static_assert
    Boost::throw_exception
    Boost::tti
    Boost::tuple
    Boost::type_traits
    Boost::typeof
    Boost::unordered
    Boost::utility
    Boost::xpressive
    EASTL
  PRIVATE
    Boost::regex
)

target_compile_definitions(boost_graph
  PUBLIC BOOST_GRAPH_NO_LIB BOOST_NO_STD_ALLOCATOR
  # Source files already define BOOST_GRAPH_SOURCE
  # PRIVATE BOOST_GRAPH_SOURCE
)

add_subdirectory(example)

if(BUILD_SHARED_LIBS)
  target_compile_definitions(boost_graph PUBLIC BOOST_GRAPH_DYN_LINK)
else()
  target_compile_definitions(boost_graph PUBLIC BOOST_GRAPH_STATIC_LINK)
endif()

if(BUILD_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")

  add_subdirectory(test)

endif()
