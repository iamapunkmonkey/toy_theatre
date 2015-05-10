set(THEATRE_SOURCES
    Main.cpp
    base/Show.cpp
    base/Actor.cpp
    base/Act.cpp
    base/Scene.cpp
    shows/todd/Todd.cpp)

set(THEATRE_HEADERS
    base/Show.h
    ConsoleHandler.h
    base/WorldObject.h
    base/Actor.h
        base/Act.h
        base/Scene.h
    shows/todd/Todd.h)

source_group(Engine FILES ${THEATRE_SOURCES} ${THEATRE_HEADERS})

add_executable(theatre
    ${THEATRE_SOURCES}
    ${THEATRE_HEADERS} )

include_directories(${SDL2_INCLUDE_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(../engine/include/)

target_link_libraries(theatre
    engine

    ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}

    ${BOX2D_LIBRARY})

add_dependencies(engine engine)