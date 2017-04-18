#include <3ds.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char **argv)
{
	
	romfsInit();
	
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG);
	
	SDL_Surface* image = NULL;
	SDL_Surface* screen = NULL;
	screen = SDL_SetVideoMode(400, 240, 32, SDL_HWSURFACE);
	
	image = IMG_Load("romfs:/ssgss.jpeg");


	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		
		u32 kDown = hidKeysDown();
		
		SDL_BlitSurface(image, NULL, screen, NULL);
		
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		
		SDL_Flip(screen);
	}
	SDL_FreeSurface(image);
	IMG_Quit();
	SDL_Quit();
	romfsExit();
	return 0;
}
