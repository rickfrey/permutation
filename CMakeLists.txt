cmake_minimum_required(VERSION 2.8.3)
project(permutation)
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

#QT4_WRAP_UI(UISrcs )
#QT4_WRAP_CPP(MOCSrcs MyWidget.h)

add_executable(permutation src/permutation.cpp)

#target_link_libraries(permutation ${OpenCV_LIBRARIES} ${QT_LIBRARIES})
