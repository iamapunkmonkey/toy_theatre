include_directories(include/)

set(ROOT_SOURCES
    src/Engine.cpp
    src/Physics.cpp
    src/Sound.cpp
    src/TileMap.cpp
    src/LunkTimer.cpp
    timer/Timer.cpp
    src/Animator.cpp
    )

set(ROOT_HEADERS
    include/Engine.h
    include/Log.h
    include/Vec2.h
    include/Updateable.h
    include/Transform.h
    include/LunkTimer.h
    include/TileMap.h
    include/TileEngine.h
    include/Rect2.h
    include/Texture.h
    include/TextureFactory.h
    include/Sound.h
    include/Renderer.h
    include/Input.h
    include/Identity.h
    include/Random.h
    include/FPSCounter.h
    include/LunkTimer.h
    include/Physics.h
    include/Filesystem.h
    include/Entity.h
    include/Renderable.h
    timer/Timer.h
    include/List.h
    include/ListNode.h
    include/Animator.h
    include/MemoryManager.h
    )

set(SDL_SOURCES
    src/sdl/SDLInput.cpp
    src/sdl/SDLRenderer.cpp
    src/sdl/SDLTexture.cpp
    src/sdl/SDLTextureFactory.cpp
    )

set(SDL_HEADERS
    include/sdl/SDLInput.h
    include/sdl/SDLRenderer.h
    include/sdl/SDLTexture.h
    include/sdl/SDLTextureFactory.h)

include_directories(${SDL2_INCLUDE_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(${SDL2_TTF_INCLUDE_DIR})

include_directories(${SDL2_MIXER_INCLUDE_DIR})

add_library(engine STATIC
    ${ROOT_SOURCES}
    ${ROOT_HEADERS}

    ${SDL_SOURCES}
    ${SDL_HEADERS})

target_link_libraries(engine

    ${SDL2_MIXER_LIBRARY})