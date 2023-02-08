/*
 * intro_screen.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#include "screen_intro.h"
#include "characters.h"
#include "LiquidCrystal.h"

void handlePressingKeyOnIntroScreen() {
	// TODO
}

void showIntroScreen() {
    osMutexAcquire(lcdMutexHandle, osWaitForever);

    setCursor(2, 0);

    print("<Space Invaders>");

    setCursor(10, 2);
    write(CT_HERO);

    setCursor(8, 1);
    write(CT_ENEMY);

    setCursor(8, 2);
    write(CT_ENEMY);

    setCursor(8, 3);
    write(CT_ENEMY);

    osMutexRelease(lcdMutexHandle);
}
