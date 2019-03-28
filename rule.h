#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <SDL.h>

bool lose(int x,int y);
//void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect);
void gameOver(SDL_Renderer* renderer,SDL_Event event,int m);

//void score(SDL_Renderer* renderer,SDL_Event event, int m);
void mybegin(SDL_Renderer* renderer,SDL_Event event);
//void mytime(SDL_Renderer* renderer,int m, SDL_Event);
void rendergame(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect1, const SDL_Rect& filled_rect2,SDL_Event event, int m,int time);

#endif // RULE_H
