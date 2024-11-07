#include <iostream>
#include <raylib.h>

const int width = 1000;
const int height = 800;

void screens(int currentPage);

int main(){
	
	std::cout << "Initializing programm" << std::endl;
	const char image1[] = "/home/daniel/Desktop/path/photo1.png";
	const char image2[] = "/home/daniel/Desktop/path/photo2.png";
	const char image3[] = "/home/daniel/Desktop/path/photo3.png";
	const char image4[] = "/home/daniel/Desktop/path/photo4.png";
	const char image5[] = "/home/daniel/Desktop/path/photo5.png";
	const char image6[] = "/home/daniel/Desktop/path/photo6.png";
	bool startButtonState = false;
	int currentPage = 1;
	int numberOfPages = 5;

	Rectangle startButton = {(width/2)-75, height-300,150 ,50 };
	Rectangle nextButton = {width-200,height-100,150,50};
	Rectangle previousButton = {50, height-100,150,50};
	Rectangle menuButton = {width-100, 50, 60, 30};
	Rectangle exitButton = {(width/2)-75, height-240,150 ,50 };

	InitWindow(width, height, "YARA");
	SetTargetFPS(60);
	Texture2D background = LoadTexture(image1);

	while(!WindowShouldClose()){
		ShowCursor();
		BeginDrawing();
		 if (startButtonState){
			ClearBackground(WHITE);
		 	screens(currentPage);
		        DrawRectangleRounded(nextButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(previousButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(menuButton, 0.3, 0, RED);
			DrawText("Menu ", width-90, 60, 15, BLACK);
			DrawText(" -> ", width-175, height-100, 60, BLACK);
			DrawText(" <- ", 75, height-100, 60, BLACK);

		        if (CheckCollisionPointRec(GetMousePosition(), nextButton) && IsMouseButtonPressed(0)){
		                currentPage++;
				if (currentPage >= numberOfPages){
					currentPage = 1;
				}
       			 }
			if (CheckCollisionPointRec(GetMousePosition(), previousButton) && IsMouseButtonPressed(0)){
				currentPage--;
				if(currentPage < 1){
					currentPage = numberOfPages;
				}
			}
			if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonPressed(0)){
				startButtonState = false;
			}
                }
		else{
			ClearBackground(WHITE);
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
	UnloadTexture(background);
	CloseWindow();
	return 0;
}


void screens(int currentPage){
	switch(currentPage){
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
			break;
		case 5:
			break;
		case 6:
			break;


	}

}
