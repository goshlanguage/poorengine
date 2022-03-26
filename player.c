#include "engine.h"
#include "player.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

const float FRICTION = 0.05;

Player
NewPlayer() {
    SDL_Surface* image = IMG_Load("./0x72_16x16DungeonTileset.v4.png");

    if(!image)
    {
        printf("Failed to load image\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
    }

    SDL_Rect srcrect;

    srcrect.x = 160;
    srcrect.y = 240;
    srcrect.w = 16;
    srcrect.h = 16;

    Player player;

    player.X = 340.0;
    player.Y = 240.0;
    player.VX = 0.0;
    player.VY = 0.0;
    player.maxVX = 0.5;
    player.maxVY = 0.5;
    player.width = 16;
    player.height = 16;
    player.sprite = image;
    player.rect = srcrect;

    return player;
}

void
Update(Player* p, double delta_time)
{
    if ((*p).VX > (*p).maxVX) {
        (*p).VX = (*p).maxVX;
    }

    if ((*p).VX < -1.0 * (*p).maxVX) {
        (*p).VX = -1.0 * (*p).maxVX;
    }

    if ((*p).VY > (*p).maxVY) {
        (*p).VY = (*p).maxVY;
    }

    if ((*p).VY < -1.0 * (*p).maxVY) {
        (*p).VY = -1.0 * (*p).maxVY;
    }

    // update player X and Y only after we ensure we're not moving by an illegal amount
    (*p).X += (*p).VX;
    (*p).Y += (*p).VY;

    // Wrap the sprite around if it goes out of bounds of the window
    if ((*p).X > 680.0) {
        (*p).X -= 680.0;
    }

    if ((*p).X < 0.0) {
        (*p).X += 680.0;
    }

    if ((*p).Y > 480.0) {
        (*p).Y -= 480.0;
    }

    if ((*p).Y < 0.0) {
        (*p).Y += 480.0;
    }

    // Moving mechanics (right, left, up, down)
    if ((*p).VX > 0.0) {
        (*p).VX -= .005;
        
        if ((*p).VX < 0.1) {
            (*p).VX = 0.0;
        }
    }

    if ((*p).VX < 0.0) {
        (*p).VX += .005;
        
        if ((*p).VX > -0.1) {
            (*p).VX = 0.0;
        }
    }

    if ((*p).VY > 0.0) {
        (*p).VY -= .005;
        
        if ((*p).VY < 0.1) {
            (*p).VY = 0.0;
        }
    }

    if ((*p).VY < 0.0) {
        (*p).VY += .005;
        
        if ((*p).VY > -0.1) {
            (*p).VY = 0.0;
        }
    }

    return;
}

void
Draw(Player* p, SDL_Surface *window_surface)
{ 
    if (p->sprite)
    {
        SDL_Rect dstrect;

        dstrect.x = (*p).X;
        dstrect.y = (*p).Y;
        dstrect.w = 32;
        dstrect.h = 32;

        if (p->VX < 0) {
            p->rect.x = 0;
        } else if (p->VX > 0) {
            p->rect.x = 16;
        }

        SDL_BlitScaled(p->sprite, &p->rect, window_surface, &dstrect);
    }
}
