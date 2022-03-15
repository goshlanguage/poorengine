#include "engine.h"

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

    Engine engine = NewEngine(window, window_surface);
    loop(engine);

    return 0;
}
