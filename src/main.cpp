#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <format>

#define WINDOWX 800
#define WINDOWY 600

namespace main {
    const char *title = "SDL2 Examples";
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
}

void initSDL(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        auto error = std::format("Error initializing SDL2: {}", SDL_GetError());
        std::cerr << error << std::endl;
        std::exit(1);
    }
}

void createObjects(void) {
    main::window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOWX, WINDOWY,
        0       
    );

    if (!main::window) {
        auto error = std::format("Error creating window: {}", SDL_GetError());
        std::cerr << error << std::endl;
        std::exit(1);
    }

    main::renderer = SDL_CreateRenderer(
        main::window,
        -1,
        SDL_RENDERER_ACCELERATED        
    );

    if (main::renderer) {
        auto error = std::format("Error creating renderer: {}", SDL_GetError());
        std::cerr << error << std::endl;
        std::exit(1);
    }
}

void closeSDL(void) {
    SDL_DestroyRenderer(main::renderer);
    SDL_DestroyWindow(main::window);
    SDL_Quit();
}

int main(void) {
    initSDL();
    createObjects();

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        SDL_SetRenderDrawColor(main::renderer, 255, 255, 255, 255);
        SDL_RenderClear(main::renderer);
        SDL_RenderPresent(main::renderer);
    }
    closeSDL();
    return 0;
}
