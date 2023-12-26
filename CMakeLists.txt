cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 23)
project(RayBaser)
include(FetchContent)
add_executable(${PROJECT_NAME} src/main.cpp)


##################
# External deps  #
##################
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        bf71a834948186f4097caa076cd2663c69a10e1e # 0.9.9.8
)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY  https://github.com/raysan5/raylib.git
  GIT_TAG         5.0
)
FetchContent_MakeAvailable(
  glm
  raylib
)
target_link_libraries(${PROJECT_NAME} 
  glm
  raylib
)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
endif()

##################
# Internal stuff #
##################
target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/primitive.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


##################
# Output         #
##################
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)