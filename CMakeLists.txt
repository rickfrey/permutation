cmake_minimum_required(VERSION 2.8.3)
project(neu_kombination)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

#QT4_WRAP_UI(UISrcs )
#QT4_WRAP_CPP(MOCSrcs MyWidget.h)

add_executable(neu_kombination src/neu_kombination.cpp)

target_link_libraries(neu_kombination ${OpenCV_LIBRARIES} ${QT_LIBRARIES})
