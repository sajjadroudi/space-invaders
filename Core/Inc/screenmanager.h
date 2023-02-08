/*
 * screenmanager.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#ifndef INC_SCREENMANAGER_H_
#define INC_SCREENMANAGER_H_

typedef enum {
	SCREEN_ABOUT,
	SCREEN_DIFFLEVEL,
	SCREEN_FINISH,
	SCREEN_INTRO,
	SCREEN_MENU,
	SCREEN_NAME,
	SCREEN_GAME
} Screen;

void goToScreen(Screen screen);

void handleShowingScreen();

void handleKeyPress(int keyNum);

Screen getCurrentScreen();

#endif /* INC_SCREENMANAGER_H_ */
