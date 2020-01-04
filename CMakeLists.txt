cmake_minimum_required(VERSION 3.10)

add_executable(tsa
  src/main.cpp

  src/game/game_states.cpp
  src/game/game.cpp
  src/game/manager/item_manager.cpp
  src/game/manager/manager_manager.cpp
  src/game/manager/manager.cpp
  src/game/object/game_item.cpp

  src/sdl/renderer.cpp
  src/sdl/texture.cpp
  src/sdl/window.cpp

  src/ui/slide/slide_manager.cpp
  src/ui/slide/slide.cpp
)

target_include_directories(tsa PUBLIC
  src
  src/game
  src/game/manager
  src/game/object
  src/sdl
  src/ui/slide
)

target_link_libraries(tsa SDL2 SDL2_image)
set_target_properties(tsa PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)
