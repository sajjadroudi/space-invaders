/*
 * screen_name.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#include "screen_name.h"
#include "req.h"
#include "LiquidCrystal.h"

void showNameScreen() {
    osMutexAcquire(lcdMutexHandle, osWaitForever);

    clear();

    setCursor(2, 1);
    print("Enter your name:");

    osMutexRelease(lcdMutexHandle);
}
