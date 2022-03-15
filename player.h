#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "engine.h"

#include <SDL2/SDL.h>

struct player {
    int x, y;
    int width, height;
    SDL_Surface* sprite;
};
typedef struct player Player;

extern Player NewPlayer();
extern void Draw(Player p, SDL_Surface *window_surface);
extern void Update(Player);

#endif
