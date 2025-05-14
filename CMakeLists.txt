cmake_minimum_required(VERSION 3.1)

project(snake2)

set(SFML_DIR "C:/c++Libs/SFML-2.6.0")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

# Find and include Qt5 packages
#find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED )  #static for static build

add_executable(snake2 main.cpp Piassa.cpp Makla.cpp Plan2D.cpp Snake.cpp Game.cpp)

target_link_libraries(snake2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network )

# Link the Qt5 libraries to the executable target
#target_link_libraries(${PROJECT_NAME} 
   # Qt5::Core     Qt5::Gui     Qt5::Widgets)  # public for static build