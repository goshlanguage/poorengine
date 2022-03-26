#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "engine.h"

#include <SDL2/SDL.h>

typedef struct player {
    float X, Y;
    float VX, VY;
    float maxVX, maxVY;
    int width, height;
    SDL_Surface* sprite;
    SDL_Rect rect;
} Player;

extern Player NewPlayer();
extern void Draw(Player*, SDL_Surface *window_surface);
extern void Update(Player*, double);

#endif
