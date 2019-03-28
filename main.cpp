#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include <cstdlib>
#include <SDL_ttf.h>
#include "rule.h"
#include <thread>
#include <chrono>

using namespace std;


/*
void Myfood(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

        SDL_RenderPresent(renderer);

}
*/


int main(int argc, char* argv[])
{

    while(true){
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    // Your code here
     int c =SDL_GetTicks();
    SDL_Event e;
    mybegin(renderer,e);
    // Định nghĩa toạ độ ban đầu và kích cỡ hình chữ nhật
    SDL_Rect filled_rect;
    filled_rect.x = 0;
    filled_rect.y = 0;
    filled_rect.w = 20;
    filled_rect.h = 20;

    SDL_Rect food;
    food.x = 25;
    food.y = 25;
    food.w = 10;
    food.h = 10;



    int step = 5;
    int m = 0;
    // Xoá toàn bộ màn hình và vẽ
    //refreshScreen(window, renderer, filled_rect);

    //Myfood(window, renderer, food);

    int start=SDL_GetTicks();
    if(e.type == SDL_QUIT) break;


    while (true) {
        SDL_Delay(10);

        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT) break;

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: break;
                    case SDLK_LEFT: filled_rect.x = (filled_rect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
                        break;
                    case SDLK_RIGHT: filled_rect.x = (filled_rect.x + step) % SCREEN_WIDTH;
                        break;
                    case SDLK_DOWN: filled_rect.y = (filled_rect.y + step) % SCREEN_HEIGHT;
                        break;
                    case SDLK_UP: filled_rect.y = (filled_rect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
                        break;
                    default: break;
                }
                //refreshScreen(window, renderer, filled_rect);

            }
            if((filled_rect.x == food.x && filled_rect.y == food.y)||
                ((filled_rect.x <= food.x && filled_rect.x + 20 >= food.x)&& (filled_rect.y + 20 >= food.y)&&(food.y >= filled_rect.y))||
                ((filled_rect.x >= food.x && filled_rect.x <= food.x + 10)&& (filled_rect.y + 20 >= food.y)&&(food.y >= filled_rect.y))||
                ((filled_rect.x <= food.x && filled_rect.x + 20 >= food.x)&& (filled_rect.y <= food.y + 10)&&(food.y <= filled_rect.y))||
                ((filled_rect.x >= food.x && filled_rect.x <= food.x + 10)&& (filled_rect.y <= food.y + 10)&&(food.y <= filled_rect.y))){
                   food.x = rand() % (400 - food.x) + 40;
                   food.y = rand() % (400 - food.y) + 40 ;
                    m++;
            }


        }


        if(lose(filled_rect.x, filled_rect.y)){
            gameOver(renderer, e,m);

            break;
        }



        int current = SDL_GetTicks();
        //mytime(renderer,current,e);
        if(current >= 180000){
            gameOver(renderer,e,m);
            break;
        }
        rendergame(window, renderer, filled_rect,food,e, m, current);
    }
    //SDL_RenderPresent(renderer);
    quitSDL(window, renderer);
    }
    return 0;
}




