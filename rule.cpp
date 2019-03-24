#include <iostream>
#include <SDL.h>

#include <SDL_ttf.h>
using namespace std;
bool lose(int x,int y){
  if(((x == 10)||(x == 20)||(x == 30))&&((y >= 10)&&(y <= 80))) return true;
  else if ((x > 380)||(y > 380)) return true;
  else if ((x >= 30 && x <= 70)&&((y == 80)||(y == 60))) return true;
  else if (((x == 70)||(x == 50))&&(y >= 80 && y <= 140)) return true;
  else if ((x >= 0 && x <= 170)&&(y == 160||y == 140)) return true;
  else if ((x >= 0 && x <= 30)&&(y == 100 || y == 110 || y == 120)) return true;
  else if ((x == 50 || x == 70)&&(y <= 30)) return true;
  else if ((x >= 50 && x <= 110)&&(y == 30 || y == 10 || y == 20)) return true;
  else if ((x == 90 || x == 110)&&(y >= 10 && y <= 120)) return true;
  else if ((x >= 90 && x <= 150)&&(y == 120 || y == 100)) return true;
  else if ((x == 170 && x == 190)&&(y >= 100 && y <= 200)) return true;
//  else if (()&&()) return true;
//  else if (()&&()) return true;
//  else if (()&&()) return true;
//  else if (()&&()) return true;
//  else if (()&&()) return true;
  else return false;
}

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect)
{
    // Đặt màu vẽ thành xanh lam (blue), xoá màn hình về màu xanh lam.
 SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    // Đặt màu vẽ về trắng và vẽ hình chữ nhật
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

    SDL_SetRenderDrawColor(renderer, 225, 0, 0, 255);
    SDL_Rect mill;
    mill.x = 0;
    mill.y = 0;
    mill.w = 400;
    mill.h = 400;
    SDL_RenderDrawRect(renderer,& mill);

    SDL_Rect nill;
    nill.x = 400;
    nill.y = 0;
    nill.w = 200;
    nill.h = 600;
    SDL_SetRenderDrawColor(renderer, 0, 225, 0, 255);
    SDL_RenderFillRect(renderer,& nill);



    SDL_Rect qill;
    qill.x = 0;
    qill.y = 400;
    qill.w = 600;
    qill.h = 200;
    SDL_SetRenderDrawColor(renderer, 0, 225, 0, 255);
    SDL_RenderFillRect(renderer,& qill);

    SDL_Rect aill;
    aill.x = 450;
    aill.y = 20;
    aill.w = 100;
    aill.h = 30;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer,& aill);

    SDL_SetRenderDrawColor(renderer, 220, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, 220, 0, 0, 255);

    SDL_RenderDrawLine(renderer,30,30,30,80);
    SDL_RenderDrawLine(renderer,30,80,70,80);
    SDL_RenderDrawLine(renderer,70,80,70,160);
    SDL_RenderDrawLine(renderer,0,120,30,120);
    SDL_RenderDrawLine(renderer,0,160,190,160);
    SDL_RenderDrawLine(renderer,70,30,70,0);
    SDL_RenderDrawLine(renderer,70,30,110,30);
    SDL_RenderDrawLine(renderer,110,30,110,120);
    SDL_RenderDrawLine(renderer,110,120,150,120);
    SDL_RenderDrawLine(renderer,150,120,150,80);
    SDL_RenderDrawLine(renderer,150,80,230,80);
    SDL_RenderDrawLine(renderer,150,30,230,30);
    SDL_RenderDrawLine(renderer,190,160,190,120);
    SDL_RenderDrawLine(renderer,230,30,230,0);
    SDL_RenderDrawLine(renderer,230,80,230,160);
    SDL_RenderDrawLine(renderer,230,160,350,160);
    SDL_RenderDrawLine(renderer,270,30,270,120);
    SDL_RenderDrawLine(renderer,270,120,400,120);
    SDL_RenderDrawLine(renderer,310,0,310,80);
    SDL_RenderDrawLine(renderer,350,30,350,120);
    SDL_RenderDrawLine(renderer,190,160,190,200);
    SDL_RenderDrawLine(renderer,350,160,350,180);
    SDL_RenderDrawLine(renderer,110,200,190,200);
    SDL_RenderDrawLine(renderer,270,200,310,200);
    SDL_RenderDrawLine(renderer,230,160,230,240);
    SDL_RenderDrawLine(renderer,310,200,310,220);
    SDL_RenderDrawLine(renderer,310,220,400,220);
    SDL_RenderDrawLine(renderer,30,200,30,320);
    SDL_RenderDrawLine(renderer,70,200,70,280);
    SDL_RenderDrawLine(renderer,110,200,110,280);
    SDL_RenderDrawLine(renderer,150,240,270,240);
    SDL_RenderDrawLine(renderer,270,260,370,260);
    SDL_RenderDrawLine(renderer,270,240,270,260);
    SDL_RenderDrawLine(renderer,70,280,230,280);
    SDL_RenderDrawLine(renderer,230,280,230,300);
    SDL_RenderDrawLine(renderer,230,300,330,300);
    SDL_RenderDrawLine(renderer,370,260,370,300);
    SDL_RenderDrawLine(renderer,330,300,330,370);
    SDL_RenderDrawLine(renderer,330,340,370,340);
    SDL_RenderDrawLine(renderer,30,320,190,320);
    SDL_RenderDrawLine(renderer,190,320,190,360);
    SDL_RenderDrawLine(renderer,190,360,0,360);
    SDL_RenderDrawLine(renderer,190,340,290,340);
    SDL_RenderDrawLine(renderer,270,340,270,370);
    SDL_RenderDrawLine(renderer,230,380,230,400);


    // Dùng lệnh hiển thị (đưa) hình đã vẽ ra mành hình
   //Khi thông thường chạy với môi trường bình thường ở nhà
       //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
   //SDL_UpdateWindowSurface(window);
}
void gameOver(SDL_Renderer* renderer,SDL_Event event)
{
    SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0 };

	//Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"lamba.ttf", 10);
	if (font == NULL) {
		//font not loaded? print an error and return
		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* gameover = TTF_RenderText_Solid(font, "Game Over", Red);

	//SDL_Surface* score = TTF_RenderText_Solid(font, (string("Score: ") + to_string(tailLength * 10)).c_str(), Black);
	SDL_Texture* gameoverMessage = SDL_CreateTextureFromSurface(renderer, gameover);

	SDL_Rect gameoverRect;

	gameoverRect.w = 200;
	gameoverRect.h = 100;
	gameoverRect.x = 100;
	gameoverRect.y = 100;

	SDL_RenderCopy(renderer, gameoverMessage, NULL, &gameoverRect);

	TTF_CloseFont(font);


	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}
		}
	}

}

void score(SDL_Renderer* renderer,SDL_Event event, int m){
    SDL_Color Black = { 0, 0, 0 };
	//Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"lightitalic.ttf", 30);
	if (font == NULL) {
		//font not loaded? print an error and return
		cout << "Font loading error" << endl;
		return;
	}
	//c_str() allows normal strings to be rendered here, otherwise the rendered text would have to be a const char* type
	//Const char* values cannot be changed after initialization, but we need dynamic text here
	SDL_Surface* score = TTF_RenderText_Solid(font, ( to_string(m * 10)).c_str(), Black);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect scoreRect;
	scoreRect.w = 30;
	scoreRect.h = 30;
	scoreRect.x = 500;
	scoreRect.y = 20;
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);
	//Close font before finishing so this font doesn't collide with any other function's font
	TTF_CloseFont(font);


}


