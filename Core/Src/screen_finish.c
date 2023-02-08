/*
 * screen_finish.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Sajjad
 */

#include "screen_finish.h"
#include "req.h"
#include "LiquidCrystal.h"
#include "config.h"
#include <stdio.h>

void showFinishScreen() {
    osMutexAcquire(lcdMutexHandle, osWaitForever);

    if(getGameState() == VICTORY) {
    	setCursor(6, 0);
    	print("<Victory>");
    } else {
    	setCursor(7, 0);
    	print("<Defeat>");
    }

    setCursor(1, 2);
    print("Name: ");
    print(getPlayerName());

    char score[3];
    sprintf(score, "%d", getScore());
    setCursor(1, 3);
    print("Score: ");
    print(score);

    osMutexRelease(lcdMutexHandle);
}
