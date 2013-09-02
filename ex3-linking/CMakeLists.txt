cmake_minimum_required (VERSION 2.6)
project (ex3)



#add_library(/usr/include/fcl)
#include_directories(/usr/local/include/fcl)
add_library(libLocal.a subfolder/local.cpp)

#file(GLOB collision_a /home/bi/fcl/src/ *.cpp)

link_directories(/usr/local/include/fcl) # @change
link_libraries(fcl /usr/local/lib/libfcl.so)
link_directories(${CMAKE_BINARY_DIR}/subfolder)
#link_libraries(libLocal libLocal.a)
#target_link_libraries(ex3 libLocal)
include_directories(subfolder)
include_directories(/usr/inclde/fcl)
add_executable(ex3 main.cpp)
target_link_libraries(ex3 libLocal.a)