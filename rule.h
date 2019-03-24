#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <SDL.h>

bool lose(int x,int y);
void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect);
void gameOver(SDL_Renderer* renderer,SDL_Event event);

void score(SDL_Renderer* renderer,SDL_Event event, int m);

#endif // RULE_H
