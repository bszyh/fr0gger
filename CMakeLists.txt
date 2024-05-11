cmake_minimum_required(VERSION 3.10)
project(Frogger LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
message(RESOURCE_PATH="${PROJECT_SOURCE_DIR}/content/")

configure_file(include/config.h.in config.h)

# fetch the sfml lib
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Frogger 
src/main.cpp
src/cFrogPlayer.cpp
src/cGameBoard.cpp
src/cGameController.cpp
src/cGameManager.cpp
src/cGameOverController.cpp
src/cListBase.cpp
src/cListNode.cpp
src/cMenuController.cpp
src/cObstacle.cpp
src/cObstacleBus.cpp
src/cObstacleCar.cpp
src/cObstacleLog.cpp
src/cWaterZone.cpp
src/cWinController.cpp)

target_include_directories(Frogger
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

target_link_libraries(Frogger PRIVATE sfml-graphics)
target_compile_features(Frogger PRIVATE cxx_std_17)


install(TARGETS Frogger)
