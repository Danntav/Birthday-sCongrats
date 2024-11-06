#include <iostream>
#include <raylib.h>

int main(){
	
	std::cout << "Initializing programm" << std::endl;
	const int width = 1000;
	const int height = 800;
	const char image1[] = "/home/daniel/Desktop/path/photo1.png";
	const char image2[] = "/home/daniel/Desktop/path/photo2.png";
	const char image3[] = "/home/daniel/Desktop/path/photo3.png";
	const char image4[] = "/home/daniel/Desktop/path/photo4.png";
	const char image5[] = "/home/daniel/Desktop/path/photo5.png";
	const char image6[] = "/home/daniel/Desktop/path/photo6.png";
	bool startButtonState = false;

	Rectangle startButton = {(width/2)-75, height-300,150 ,50 };
	
	Rectangle second = {10, 10, 200, 200};

	InitWindow(width, height, "YARA");
	SetTargetFPS(60);

	Texture2D background = LoadTexture(image1);

	while(!WindowShouldClose()){
		ShowCursor();
		BeginDrawing();
		ClearBackground(WHITE);
		DrawRectangleRounded(startButton, 0.3, 0, LIGHTGRAY);
		DrawText("COMECAR", (width/2)-50, height-285, 20, BLACK);
		
		if(CheckCollisionPointRec(GetMousePosition(), startButton)){
			DrawRectangleRounded(startButton, 0.3, 0, {190,190,190,200});
			if (IsMouseButtonDown(0)){
			//if (IsMouseButtonPressed(0)){
				startButtonState = true;
				//Start here the pages
			}
			else{
			startButtonState = false;
			}
		}
		if (startButtonState){
			DrawRectangleRounded(second, 0.3,0, RED);
		}
		
				

		EndDrawing();

	}
	UnloadTexture(background);

	CloseWindow();
	return 0;

}
