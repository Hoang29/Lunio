#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include <cstdlib>
#include <SDL_ttf.h>
#include "rule.h"
using namespace std;



void Myfood(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

}



int main(int argc, char* argv[])
{

    while(true){
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    // Your code here
    SDL_Event e;
    mybegin(renderer,e);
    // Định nghĩa toạ độ ban đầu và kích cỡ hình chữ nhật
    SDL_Rect filled_rect;
    filled_rect.x = 0;
    filled_rect.y = 0;
    filled_rect.w = 20;
    filled_rect.h = 20;


    SDL_Rect food;
    food.x = 240;
    food.y = 250;
    food.w = 10;
    food.h = 10;


    // Bước nhảy mỗi khi dịch chuyển
    int step = 5;
    int m = 0;
    // Xoá toàn bộ màn hình và vẽ
    refreshScreen(window, renderer, filled_rect);
    Myfood(window, renderer, food);
    if(e.type == SDL_QUIT) break;

        while (true) {
        // Đợi 10 mili giây
        SDL_Delay(10);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
        if ( SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu có một phím được nhấn, thì xét phím đó là gì để xử lý tiếp
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break; // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        		// Nếu phím mũi tên trái, dịch sang trái
    	        // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
        		case SDLK_LEFT: filled_rect.x = (filled_rect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
        			break;
                // Tương tự với dịch phải, xuống và lên
            	case SDLK_RIGHT: filled_rect.x = (filled_rect.x + step) % SCREEN_WIDTH;
            		break;
            	case SDLK_DOWN: filled_rect.y = (filled_rect.y + step) % SCREEN_HEIGHT;
					break;
            	case SDLK_UP: filled_rect.y = (filled_rect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
            		break;
        		default: break;
			}

            // Xoá toàn bộ màn hình và vẽ lại
                refreshScreen(window, renderer, filled_rect);


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
            Myfood(window, renderer, food);
            score(renderer, e, m);

            if(lose(filled_rect.x, filled_rect.y)){
                gameOver(renderer, e);

                break;
            }
            SDL_RenderPresent(renderer);
        }

    quitSDL(window, renderer);

    }
    return 0;
}
// Xoá và vẽ lại toàn bộ màn hình với 1 hình chữ nhật



