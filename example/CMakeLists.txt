cmake_minimum_required(VERSION 3.12)
# Get all .cpp files in current directory
file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Loop through each file and create a target
foreach(src_file ${SOURCES})
    # Get filename without extension
    get_filename_component(exe_name ${src_file} NAME_WE)

    # Create executable for each .cpp file
    add_executable(${exe_name} ${src_file})

    # Link Boost.Graph
    target_link_libraries(${exe_name} PRIVATE Boost::graph)
endforeach()
