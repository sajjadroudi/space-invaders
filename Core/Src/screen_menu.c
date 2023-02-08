/*
 * screen_menu.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#include "screen_menu.h"
#include "req.h"
#include "LiquidCrystal.h"

void handlePressingKeyOnMenuScreen() {
	// 	TODO
}

void showMenuScreen() {
    osMutexAcquire(lcdMutexHandle, osWaitForever);

    setCursor(0, 0);
    print("1) Start Game");

    setCursor(0, 2);
    print("2) About Us");

    osMutexRelease(lcdMutexHandle);
}
