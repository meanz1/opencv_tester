# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(opencv_tester)

set(OpenCV_DIR /Users/adammcquistan/code/c++/opencv/install/lib/cmake/opencv4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BINARY_DIR  ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
set(OpenCV_DIR /opt/homebrew/opt/opencv4)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/HoughLines.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )
