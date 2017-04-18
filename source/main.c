#include <3ds.h>
#include <stdio.h>
#include <SDL/sdl.h>
#include <SDL/SDL_image.h>

int main(int argc, char **argv)
{
	//Initialize gfx (note: not needed if you're using SF2Dlib)
	gfxInitDefault();
	
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG);
	
	SDL_Surface* image = NULL;
	SDL_Surface* screen = NULL;
	screen = SDL_SetVideoMode(400, 240, 32, SDL_SWSURFACE);
	image = IMG_Load("ssgss.jpeg");
	SDL_BlitSurface(image, NULL, screen, NULL);

	
	consoleInit(GFX_BOTTOM, NULL);

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		//hidKeysHeld returns information about which buttons are currently pressed (regardless if they were pressed or not pressed in the previous frame)
		//hidKeysUp returns information about which buttons are not pressed but were pressed in the previous frame
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers, this is needed for rendering these will not be needed when using SF2D lib
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank, this is needed for rendering these will not be needed when using SF2D lib
		gspWaitForVBlank();
	}
	SDL_FreeSurface(image);
	IMG_Quit();
	SDL_Quit();
	gfxExit();
	return 0;
}
