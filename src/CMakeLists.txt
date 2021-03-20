## local variable for managing the game target
set(GAME ${PROJECT_NAME})

## glob is useful but not reliant in compilation so just use it for headers ##
file(GLOB_RECURSE HEADER_LIST
        LIST_DIRECTORIES FALSE
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/src/game/*.hpp
        ${CMAKE_SOURCE_DIR}/src/game/*.h)

## the ASGE Game, which spawns the Game window ##
add_executable(
        ${GAME} ${HEADER_LIST}
        ## source code files for app here ##
        game/main.cpp
        game/game.cpp game/GameObjects/Core/SpriteObject.cpp game/GameObjects/Core/SpriteObject.h game/GameObjects/GameObject.h game/GameObjects/Core/TextObject.cpp game/GameObjects/Core/TextObject.h game/GameObjects/Core/AnimatedSprite.cpp game/GameObjects/Core/AnimatedSprite.h game/GameObjects/Scenes/Scene.cpp game/GameObjects/Scenes/Scene.h game/GameObjects/Tilemap/Tile.cpp game/GameObjects/Tilemap/Tile.h game/GameObjects/Tilemap/TileMap.cpp game/GameObjects/Tilemap/TileMap.h game/GameObjects/Scenes/LevelTest.cpp game/GameObjects/Scenes/LevelTest.h game/GameObjects/Player/Player.cpp game/GameObjects/Player/Player.h)

## configure the target ##
list(APPEND LIBS ${CMAKE_DL_LIBS} "soloud")
configure_target(${GAME} ${CMAKE_CURRENT_SOURCE_DIR} "${HEADER_LIST}" "${LIBS}")
add_asge_dependency(${GAME})

## game data ##
include(tools/gamedata)
add_gamedata(${GAME} ${CMAKE_SOURCE_DIR}/data)
