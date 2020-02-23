cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(tsa)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(tsa
  src/main.cpp

  src/game/game_states.cpp
  src/game/game.cpp
  src/game/manager/item_manager.cpp
  src/game/manager/manager_manager.cpp
  src/game/manager/manager.cpp
  src/game/object/game_item.cpp

  src/level/boss/boss_manager.cpp
  src/level/boss/boss.cpp
  src/level/boss/rocket.cpp
  src/level/cutscene/cutscene_manager.cpp
  src/level/cutscene/dialog.cpp
  src/level/enemies/enemy_manager.cpp
  src/level/enemies/enemy.cpp
  src/level/player/player_manager.cpp
  src/level/player/player.cpp
  src/level/trampoline/trampoline_manager.cpp
  src/level/trampoline/trampoline.cpp

  src/menu/menu_manager.cpp
  src/menu/level_select/level_select_manager.cpp
  src/menu/level_select/level_tile.cpp

  src/sdl/mixer.cpp
  src/sdl/renderer.cpp
  src/sdl/texture.cpp
  src/sdl/window.cpp

  src/ui/background/background_manager.cpp
  src/ui/background/background.cpp
  src/ui/components/component_manager.cpp
  src/ui/components/ui_component.cpp
  src/ui/components/button/button_manager.cpp
  src/ui/components/button/button.cpp
  src/ui/labels/label_manager.cpp
  src/ui/labels/label.cpp
  src/ui/labels/score/number.cpp
  src/ui/labels/score/score_manager.cpp
  src/ui/slide/slide_manager.cpp
  src/ui/slide/slide.cpp
)

target_include_directories(tsa PUBLIC
  src
  src/game
  src/game/manager
  src/game/object
  src/level/boss
  src/level/cutscene
  src/level/enemies
  src/level/player
  src/level/trampoline
  src/menu
  src/menu/level_select
  src/sdl
  src/ui/background
  src/ui/components
  src/ui/components/button
  src/ui/labels
  src/ui/labels/score
  src/ui/slide
  include/
  include/headers
  ${SDL2_INCLUDE_DIRS} 
${SDL2_IMAGE_INCLUDE_DIRS}	
${SDL2_MIXER_INCLUDE_DIRS}	
)


target_link_libraries(tsa ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} )
set_target_properties(tsa PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)