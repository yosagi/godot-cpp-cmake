# dependencies

# no runtime error check for this target
STRING (REGEX REPLACE "[/|-]RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# utilities
function(set_output_dirs tgt dir)
 set_property(TARGET ${tgt} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${dir})
 set_property(TARGET ${tgt} PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG ${dir})
endfunction(set_output_dirs)

# Target(s)
set(SRCS
  gdexample.cpp
  gdexample.h
  gdlibrary.cpp
)
set(RCS
  gdexample.gdnlib
  gdexample.gdns
)
add_library(libgdexample SHARED ${SRCS})
target_link_libraries(libgdexample godot-cpp)

set_output_dirs(libgdexample ${GDNATIVE_OUTPUT_DIRECTORY}/win64)

# deploy meta files
foreach(RC ${RCS})
 configure_file(${RC} ${GDNATIVE_OUTPUT_DIRECTORY} COPYONLY)
endforeach(RC)
