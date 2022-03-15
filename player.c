#include "engine.h"
#include "player.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

Player
NewPlayer() {
    SDL_Surface* image = IMG_Load("./0x72_16x16DungeonTileset.v4.png");

    if(!image)
    {
        printf("Failed to load image\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
    }

    Player player;

    player.x = 340;
    player.y = 240;
    player.width = 16;
    player.height = 16;
    player.sprite = image;

    return player;
}

void
Update(Player player)
{
  return;
}

void
Draw(Player p, SDL_Surface *window_surface)
{
    if (p.sprite)
    {
        SDL_Rect srcrect;

        srcrect.x = 0;
        srcrect.y = 0;
        srcrect.w = 32;
        srcrect.h = 32;

        SDL_BlitSurface(p.sprite, &srcrect, window_surface, NULL);
    }
}
