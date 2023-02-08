/*
 * screen_difflevel.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#include "req.h"
#include "LiquidCrystal.h"

void showDiffLevelScreen() {
    osMutexAcquire(lcdMutexHandle, osWaitForever);

    setCursor(1, 0);
    print("<Difficulty Level>");

    setCursor(0, 1);
    print("1) Easy");

    setCursor(0, 2);
    print("2) Normal");

    setCursor(0, 3);
	print("2) Hard");

    osMutexRelease(lcdMutexHandle);
}

void handlePressingKeyOnDiffLevelScreen() {
	// TODO
}
