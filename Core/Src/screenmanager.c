/*
 * screenmanager.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#include "screenmanager.h"
#include "screen_about.h"
#include "screen_intro.h"
#include "screen_menu.h"
#include "screen_difflevel.h"
#include "screen_finish.h"
#include "screen_name.h"
#include "lcd.h"
#include "config.h"
#include "LiquidCrystal.h"

Screen currScreen = SCREEN_INTRO;

void goToScreen(Screen screen) {
	currScreen = screen;
}

void handleShowingScreen() {
	osMutexAcquire(lcdMutexHandle, osWaitForever);
	clear();
    osMutexRelease(lcdMutexHandle);

	switch(currScreen) {
		case SCREEN_ABOUT:
			showAboutScreen();
			while(1) {
				updateShowingDateTime();
				osDelay(1000);

				if(currScreen != SCREEN_ABOUT)
					break;
			}
			handleShowingScreen();
		break;

		case SCREEN_DIFFLEVEL:
			showDiffLevelScreen();
		break;

		case SCREEN_FINISH:
			showFinishScreen();
		break;

		case SCREEN_GAME:
			while(1) {
			    osDelay(100);
			    updateLcd();

			    if(currScreen != SCREEN_GAME)
			    	break;
		    }
			handleShowingScreen();
		break;

		case SCREEN_INTRO:
			showIntroScreen();
		break;

		case SCREEN_MENU:
			showMenuScreen();
		break;

		case SCREEN_NAME:
			showNameScreen();
		break;
	}
}

void handleKeyPress(int keyNum) {
	switch(currScreen) {
		case SCREEN_ABOUT:
			goToScreen(SCREEN_MENU);
		break;

		case SCREEN_DIFFLEVEL:
			if(keyNum == 1) {
				setDifficultyLevel(DIFFICULTY_EASY);
			} else if(keyNum == 2) {
				setDifficultyLevel(DIFFICULTY_NORMAL);
			} else if(keyNum == 3) {
				setDifficultyLevel(DIFFICULTY_HARD);
			}

			goToScreen(SCREEN_GAME);
		break;

		case SCREEN_FINISH:

		break;

		case SCREEN_GAME:
			// This if branch might cause bug because of heavy computation
			if(keyNum == 14) {
				moveHeroLeft();
			} else if(keyNum == 15) {
				commandHeroToShoot();
			} else if(keyNum == 16) {
				moveHeroRight();
			}
		break;

		case SCREEN_INTRO:
			goToScreen(SCREEN_MENU);
		break;

		case SCREEN_MENU:
			if(keyNum == 1) {
				goToScreen(SCREEN_NAME);
			} else if(keyNum == 2) {
				goToScreen(SCREEN_ABOUT);
			}
		break;

		case SCREEN_NAME:
			if(keyNum == 1) {
				goToScreen(SCREEN_DIFFLEVEL);
			}
		break;
	}
}

Screen getCurrentScreen() {
	return currScreen;
}
