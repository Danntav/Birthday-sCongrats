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


	Rectangle baseScreen = {50, 50, width-100, height-100};

	InitWindow(width, height, "YARA");
	SetTargetFPS(60);

	Texture2D background = LoadTexture(image1);

	while(!WindowShouldClose()){
		ShowCursor();
		BeginDrawing();
		//DrawTexture(background, 0, 0, WHITE);
		DrawRectangleRounded(baseScreen, 0.1, 10, LIGHTGRAY);
		EndDrawing();

	}
	UnloadTexture(background);

	CloseWindow();
	return 0;

}
