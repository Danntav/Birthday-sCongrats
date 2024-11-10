#include <iostream>
#include <raylib.h>
#include <random>

const int width = 1000;
const int height = 800;

void Screens(int currentPage, Texture2D images[], Texture2D background);

int main(){
	
	std::cout << "Initializing programm" << std::endl;

	const char backgroundMenu[] = "/home/daniel/Desktop/path/backgroundMenu.png";
	const char backgroundSlide[] = "/home/daniel/Desktop/path/backgroundSlide.png";

	bool startButtonState = false;
	int currentPage = 1;
	int numberOfPages = 10;
	
	Rectangle startButton = {(width/2)-75, height-300,150 ,50 };
	Rectangle nextButton = {width-200,height-100,150,50};
	Rectangle previousButton = {50, height-100,150,50};
	Rectangle menuButton = {width-100, 50, 60, 30};
	Rectangle exitButton = {(width/2)-75, height-240,150 ,50 };

	InitWindow(width, height, "YARA");
	SetTargetFPS(60);
	Texture2D backgroundMenuImage = LoadTexture(backgroundMenu);
	Texture2D backgroundSlideImage = LoadTexture(backgroundSlide);
	
	Texture2D images[numberOfPages] = {
		LoadTexture("/home/daniel/Desktop/path/photo1.png"),
		LoadTexture("/home/daniel/Desktop/path/photo2.png"),
		LoadTexture("/home/daniel/Desktop/path/photo10.png"),
		LoadTexture("/home/daniel/Desktop/path/photo4.png"),
		LoadTexture("/home/daniel/Desktop/path/photo5.png"),
		LoadTexture("/home/daniel/Desktop/path/photo11.png"),
		LoadTexture("/home/daniel/Desktop/path/photo7.png"),
		LoadTexture("/home/daniel/Desktop/path/photo8.png"),
		LoadTexture("/home/daniel/Desktop/path/photo9.png"),
	};

	while(!WindowShouldClose()){
		ShowCursor();
		BeginDrawing();
		 if (startButtonState){
  			ClearBackground(WHITE);
		 	Screens(currentPage-1, images, backgroundSlideImage);
		        DrawRectangleRounded(nextButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(previousButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(menuButton, 0.3, 0, RED);
			DrawText("Menu ", width-90, 60, 15, BLACK);
			DrawText(" -> ", width-175, height-100, 60, BLACK);
			DrawText(" <- ", 75, height-100, 60, BLACK);


		        if (CheckCollisionPointRec(GetMousePosition(), nextButton)){
				DrawRectangleRounded(nextButton, 0.3, 0, {190,190,190,200});
                                if (IsMouseButtonPressed(0)){
					currentPage++;
					if (currentPage > numberOfPages){
						currentPage = 1;
				}	}
       			 }
			if (CheckCollisionPointRec(GetMousePosition(), previousButton)){
				DrawRectangleRounded(previousButton, 0.3, 0, {190,190,190,200});
				if (IsMouseButtonPressed(0)){
					currentPage--;
					if(currentPage < 1){
						currentPage = numberOfPages;
					}
				}
			}
			if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonPressed(0)){
				startButtonState = false;
			}
                }
		else{
			ClearBackground(WHITE);
			DrawTexture(backgroundMenuImage, 0, 0, WHITE);
             	 	DrawRectangleRounded(startButton, 0.3, 0, LIGHTGRAY);
              		DrawText("COMECAR", (width/2)-50, height-285, 20, BLACK);
			DrawRectangleRounded(exitButton, 0.3, 0,RED);
                        DrawText("SAIR", (width/2)-25, height-225, 20, BLACK);


			if(CheckCollisionPointRec(GetMousePosition(), startButton)){
				DrawRectangleRounded(startButton, 0.3, 0, {190,190,190,200});
				if (IsMouseButtonPressed(0)){
					startButtonState = true;
				}
			}
			if(CheckCollisionPointRec(GetMousePosition(), exitButton)){
				DrawRectangleRounded(exitButton, 0.3, 0, {255,255,44,44});
				if (IsMouseButtonPressed(0)){
					break;
				}
			}
		}
		EndDrawing();
	}

	for (int i = 0; i < numberOfPages; ++i){
		UnloadTexture(images[i]);
	}
	UnloadTexture(backgroundMenuImage);
	UnloadTexture(backgroundMenuSlide);
	CloseWindow();
	return 0;
}


void Screens(int currentPage, Texture2D image[], Texture2D background){
	
	float scaleX = static_cast<float>(width) / image[currentPage].width;
	float scaleY = static_cast<float>(height) / image[currentPage].height;
	float scale = std::min(scaleX, scaleY); // Uniform scale to keep aspect ratio

	float posX = (width - image[currentPage].width * scale) / 2;
	float posY = (height - image[currentPage].height * scale) / 2;

	DrawTextureEx(background,{0,0}, 0.0f,0.7 ,WHITE);
	DrawTextureEx(image[currentPage], {posX, posY}, 0.0f, scale, WHITE);

	switch(currentPage){
		case 0:
			break;
		case 1:
			DrawText("Welcome to Page 1", 50, 50, 20, BLACK);
			break;
		case 2:
			DrawText("Thats the second Page", 50, 50, 20, BLACK);
			break;
		case 3:
	                DrawText("Third page goes hard", 50, 50, 20, BLACK);
	                break;
		case 4:
			DrawText("Forth Image", 50, 50, 20, BLACK);
			break;
		case 5:
			DrawText("Fifth Image", 50, 50, 20, BLACK);
			break;
		case 6:
			DrawText("Sixth Image", 50, 50, 20, BLACK);
			break;
		case 7:
			DrawText("Seventh Image", 50, 50, 20, BLACK);
                        break;
		case 8:
			DrawText("Eigth Image", 50, 50, 20, BLACK);
                        break;
		case 9:
			static Rectangle loveButton = {(width / 2) - 100, height / 2, 200, 50};
		        static Rectangle dontLoveButton = {width / 2 - 100, height / 2 + 80, 200, 50};
			
		        DrawRectangleRounded(loveButton, 0.3, 0, LIGHTGRAY);
		        DrawText("I love you too", loveButton.x + 30, loveButton.y + 15, 20, BLACK);
		        DrawRectangleRounded(dontLoveButton, 0.3, 0, LIGHTGRAY);
		        DrawText("Don't love you", dontLoveButton.x + 20, dontLoveButton.y + 15, 20, BLACK);
		        if (CheckCollisionPointRec(GetMousePosition(), loveButton)){
				DrawRectangleRounded(loveButton,0.3,0, {190,190,190,200});
				DrawText("Te amo mais, amor", 50, 50, 60, BLACK);
			}
			if (CheckCollisionPointRec(GetMousePosition(), dontLoveButton)) {
		                dontLoveButton.x = GetRandomValue(50, width - 250);
		                dontLoveButton.y = GetRandomValue(100, height - 150);
			}
			break;
	}		
}
