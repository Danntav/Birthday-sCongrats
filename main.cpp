#include <iostream>
#include <raylib.h>

//Set screen dimensions
const int width = 1000;
const int height = 800;

void Screens(int currentPage, Texture2D images[], Texture2D background, Texture2D heart);

int main(){
	
	std::cout << "Initializing programm" << std::endl;

	const char backgroundMenu[] = "backgroundMenu.png";
	const char backgroundSlide[] = "backgroundSlide.png";

	bool startButtonState = false;
	int currentPage = 1;
	int numberOfPages = 10;
	
	//Configuring all buttons types
	Rectangle startButton = {(width/2)-75, height-300,150 ,50 };
	Rectangle nextButton = {width-200,height-100,150,50};
	Rectangle previousButton = {50, height-100,150,50};
	Rectangle menuButton = {width-100, 50, 60, 30};
	Rectangle exitButton = {(width/2)-75, height-240,150 ,50 };
	
	//Initializing program window and loading images
	InitWindow(width, height, "{NAME}");
	SetTargetFPS(60);
	Texture2D backgroundMenuImage = LoadTexture(backgroundMenu);
	Texture2D backgroundSlideImage = LoadTexture(backgroundSlide);

	Texture2D heart = LoadTexture("heart1.png");

	Texture2D images[numberOfPages] = {
		LoadTexture("photo1.png"),
		LoadTexture("photo2.png"),
		LoadTexture("photo3.png"),
		LoadTexture("photo4.png"),
		LoadTexture("photo5.png"),
		LoadTexture("photo6.png"),
		LoadTexture("photo7.png"),
		LoadTexture("photo8.png"),
		LoadTexture("photo9.png"),
	};

	while(!WindowShouldClose()){
		ShowCursor();
		BeginDrawing();
		//Configuring the slide pages
		if (startButtonState){
  			ClearBackground(WHITE);
		 	Screens(currentPage-1, images, backgroundSlideImage, heart);
		        DrawRectangleRounded(nextButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(previousButton, 0.3, 0, LIGHTGRAY);
			DrawRectangleRounded(menuButton, 0.3, 0, RED);
			DrawText("Menu ", width-90, 60, 15, BLACK);
			DrawText(" -> ", width-175, height-100, 60, BLACK);
			DrawText(" <- ", 75, height-100, 60, BLACK);
			//Incrementing pages
		        if (CheckCollisionPointRec(GetMousePosition(), nextButton)){
				DrawRectangleRounded(nextButton, 0.3, 0, {190,190,190,200});
                                if (IsMouseButtonPressed(0)){
					currentPage++;
					if (currentPage > numberOfPages){
						currentPage = 1;
				}	}
       			}
			//Decresing pages
			if (CheckCollisionPointRec(GetMousePosition(), previousButton)){
				DrawRectangleRounded(previousButton, 0.3, 0, {190,190,190,200});
				if (IsMouseButtonPressed(0)){
					currentPage--;
					if(currentPage < 1){
						currentPage = numberOfPages;
					}
				}
			}
			//home button
			if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonPressed(0)){
				startButtonState = false;
			}
                }
		//Configuring menu page
		else{
			ClearBackground(WHITE);
			DrawTexture(backgroundMenuImage, 0, 0, WHITE);
			DrawRectangleRounded({(width/2)-200, height-525,400 ,200 }, 0.3, 0, WHITE);
			DrawText("Happy Birthday!", (width/2)-175, height-500, 42, BLACK);
			DrawText("  {Text}   ", (width/2)-175, height-420, 50, BLACK);
	                DrawRectangleRounded(startButton, 0.3, 0, LIGHTGRAY);
        	        DrawText("START", (width/2)-50, height-285, 20, BLACK);
			DrawRectangleRounded(exitButton, 0.3, 0,RED);
            	        DrawText("EXIT", (width/2)-25, height-225, 20, BLACK);
			
			//Checking menu buttons
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
	//Unloading images and Closing Window
	for (int i = 0; i < numberOfPages; ++i){
		UnloadTexture(images[i]);
	}
	UnloadTexture(heart);
	UnloadTexture(backgroundMenuImage);
	UnloadTexture(backgroundSlideImage);
	CloseWindow();
	return 0;
}

//This function loads the images and scales them for each page
void Screens(int currentPage, Texture2D image[], Texture2D background, Texture2D heart){
	
	float scaleX = static_cast<float>(width) / image[currentPage].width;
	float scaleY = static_cast<float>(height) / image[currentPage].height;
	float scale = std::min(scaleX, scaleY); // Uniform scale to keep aspect ratio

	float posX = (width - image[currentPage].width * scale) / 2;
	float posY = (height - image[currentPage].height * scale) / 2;

	DrawTextureEx(background,{0,0}, 0.0f,0.7 ,WHITE);
	DrawTextureEx(image[currentPage], {posX, posY}, 0.0f, scale, WHITE);

	//Setting each page distinctly
	switch(currentPage){
		case 0:
			DrawRectangleRounded({200, height-120, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 220, height-80, 23, BLACK);
			break;
		case 1:
			DrawRectangleRounded({200, 50, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 215, 80, 23, BLACK);
			break;
		case 2:
			DrawRectangleRounded({200, 50, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 215, 80, 23, BLACK);
			break;
		case 3:
			DrawRectangleRounded({200, height-120, 600, 90}, 0.3, 0, WHITE);
	        DrawText("{Text}", 260, height-80, 23, BLACK);
	        break;
		case 4:
			DrawRectangleRounded({200, height-120, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", (width/2)-110, height-85, 40, BLACK);
			break;
		case 5:
			DrawRectangleRounded({200, 50, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 250, 80, 23, BLACK);
			break;
		case 6:
			DrawRectangleRounded({200, 50, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 290, 70, 23, BLACK);
			DrawText("{Text}", 310, 95, 23, BLACK);
			break;
		case 7:
			DrawRectangleRounded({200, height-120, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", 225, height-80, 23, BLACK);
                        break;
		case 8:
			DrawRectangleRounded({200, height-120, 600, 90}, 0.3, 0, WHITE);
			DrawText("{Text}", (width/2)-110, height-80, 23, BLACK);
                        break;
		case 9:
			//Set small animated button on the last page
			ClearBackground(WHITE);
			static Rectangle loveButton = {(width/2)-100, (height/2)+80, 200, 50};
		        static Rectangle dontLoveButton = {width/2-100, height/2+160, 200, 50};
			
		        DrawRectangleRounded(loveButton, 0.3, 0, LIGHTGRAY);
		        DrawText("    {Text}", loveButton.x + 30, loveButton.y + 15, 20, BLACK);
		        DrawRectangleRounded(dontLoveButton, 0.3, 0, LIGHTGRAY);
		        DrawText("   {Text}", dontLoveButton.x + 20, dontLoveButton.y + 15, 20, BLACK);
		        if (CheckCollisionPointRec(GetMousePosition(), loveButton)){
				DrawRectangleRounded(loveButton,0.3,0, {190,190,190,200});
				DrawText("{Text}", 250, 200, 60, BLACK);
				DrawTextureEx(heart,{425,300} , 0.0f, 0.1, WHITE);
			}
			if (CheckCollisionPointRec(GetMousePosition(), dontLoveButton)) {
		                dontLoveButton.x = GetRandomValue(50, width - 250);
		                dontLoveButton.y = GetRandomValue(100, height - 150);
			}
			break;
	}		
}

