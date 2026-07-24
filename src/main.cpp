#include <SDL2/SDL.h>
#include <iostream>
#include <format>
#include <cstdlib>

#define WINDOWX 800
#define WINDOWY 600

namespace main {
    const char *title = "SDL2 Examples";
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
};

void initSDL(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        auto error = std::format("Error initializing SDL2: {}", SDL_GetError());
        std::cerr << error << std::endl;
        std::exit(1); // error
    }
}

void createObjects(void) {
    main::window = SDL_CreateWindow(
        main::title,
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

    if (!main::renderer) {
        auto error = std::format("Error creating renderer: {}", SDL_GetError());
        std::cerr << error << std::endl;
        std::exit(1);
    }
}

void close(void) {
    SDL_DestroyRenderer(main::renderer);
    SDL_DestroyWindow(main::renderer);
    SDL_Quit();
}

int main(void) {
    initSDL();
    createObjects();

    // mainloop
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        SDL_SetRenderDrawColor(main::renderer, 255, 255, 255, 255);
        SDL_RenderClear();
        SDL_RenderPresent();
    }

    close();
    return 0;
}
