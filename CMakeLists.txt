cmake_minimum_required(VERSION 3.10)
project(test_cv)
set(CMAKE_MACOSX_RPATH 0)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE  "-std=c++11 -O3  -pthread")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

############### dependencies ######################
# Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# OpenCV
find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

#Boost
find_package(Boost REQUIRED COMPONENTS
filesystem
)
include_directories(${Boost_INCLUDE_DIRS}) 

set(THIRD_PARTY_LIBS
        ${OpenCV_LIBS}
        ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}
        ${GLOG_LIBRARIES}
        pthread
        ${Boost_LIBRARIES}
        )

enable_testing()

############### source and test ######################
add_executable(test_sfm examples/essential_mat_reconstr.cpp)
target_link_libraries(test_sfm ${THIRD_PARTY_LIBS})
