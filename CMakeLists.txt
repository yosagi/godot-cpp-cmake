cmake_minimum_required(VERSION 3.10)

# GDNative Binding. Creates "godot-cpp" library target.
add_subdirectory(godot-cpp)

# Configurations
## godot project directory
set(GDNATIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/nativetest1/bin)
if(NOT EXISTS ${GDNATIVE_OUTPUT_DIRECTORY})
    file(MAKE_DIRECTORY ${GDNATIVE_OUTPUT_DIRECTORY})
endif()

# User codes
add_subdirectory(src)

