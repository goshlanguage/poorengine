#ifndef __ENGINE_H__
#define __ENGINE_H__

# include "state.h"
#include <SDL2/SDL.h>

struct engine {
  SDL_Window*  window;
  SDL_Surface* window_surface;
  State state;
};
typedef struct engine Engine;

extern Engine NewEngine(SDL_Window *window, SDL_Surface *window_surface);
extern int loop(Engine);

#endif
