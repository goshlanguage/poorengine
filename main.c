#include "engine.h"
#include "player.h"
#include "state.h"

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

void
init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize the SDL2 library\n");
        return;
    }
}

int
main()
{
    init();

    SDL_Window *window = SDL_CreateWindow("demo",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if(!window)
    {
        printf("Failed to create window\n");
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        printf("Failed to get the surface from the window\n");
        return -1;
    }

    Player player = NewPlayer();

    State state;
    state.player = &player;

    Engine engine = NewEngine(window, window_surface);
    engine.state = state;

    loop(engine);

    // free window and surface
    SDL_DestroyWindow(window);
    SDL_Quit();

    window = NULL;
    window_surface = NULL;

    return 0;
}
