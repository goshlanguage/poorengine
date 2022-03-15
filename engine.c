#include "engine.h"

#include<stdbool.h>
#include<SDL2/SDL.h>

Engine
NewEngine(SDL_Window* window, SDL_Surface *window_surface)
{
    Engine engine;

    engine.window = window;
    engine.window_surface = window_surface;

    return engine;
}

// loop is our main loop, it's responsible for processing events
int
loop(Engine engine)
{
    SDL_Event e;
    bool quit = false;

    while(!quit)
    {
        while (SDL_PollEvent(&e) > 0)
        {
        if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){

            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }

            SDL_UpdateWindowSurface(engine.window);
        }

    }

    return 0;
}
