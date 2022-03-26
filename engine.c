#include "engine.h"
#include "player.h"

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

void
draw(Engine engine) {
    Draw(engine.state.player, engine.window_surface);

    return;
}

void
update(Engine engine) {
    Update(engine.state.player, 1.0/60.0);
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
                switch (e.key.keysym.sym)
                {
                case SDLK_w: 
                    engine.state.player->VY -= 0.5;
                    break;
                case SDLK_a:
                    engine.state.player->VX -= 0.5;
                    break;
                case SDLK_d:
                    engine.state.player->VX += 0.5;
                    break;
                case SDLK_s:
                    engine.state.player->VY += 0.5;
                    break;
                case SDLK_p:
                    printf("coords: (%f, %f)\n", engine.state.player->X, engine.state.player->Y);
                    break;
                }
            }

            if (e.type == SDL_MOUSEBUTTONDOWN){

            }
        }

        // Clear screen with black rect
        SDL_FillRect(engine.window_surface, NULL, 0x000000);

        draw(engine);
        update(engine);

        SDL_UpdateWindowSurface(engine.window);
    }

    return 0;
}
