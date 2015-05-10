set(GAME_SOURCES
    Main.cpp
    World.cpp)

set(GAME_HEADERS
    World.h
    ConsoleHandler.h)

source_group(Engine FILES ${GAME_SOURCES} ${GAME_HEADERS})

add_executable(game
    ${GAME_SOURCES}
    ${GAME_HEADERS})

include_directories(${SDL2_INCLUDE_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(../engine/include/)

target_link_libraries(game
    engine

    ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}

    ${BOX2D_LIBRARY})

add_dependencies(engine engine)