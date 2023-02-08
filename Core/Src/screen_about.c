/*
 * screen_about.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#include <stdio.h>
#include <stdlib.h>
#include "screen_about.h"
#include "req.h"
#include "timehandler.h"
#include "LiquidCrystal.h"
#include "main.h"

char groupName[15] = "Sajjad - Iman";
static char timeStr[20];

void showAboutScreen() {

    updateDateTime();
    sprintf(timeStr, "%d/%d/%d - %d:%d:%d",
            getDateTime().dateVar.Year, getDateTime().dateVar.Month, getDateTime().dateVar.Date,
            getDateTime().timeVar.Hours, getDateTime().timeVar.Minutes, getDateTime().timeVar.Seconds
	);

    osMutexAcquire(lcdMutexHandle, osWaitForever);

    clear();

    setCursor(0, 0);
    print("Name: ");
    print(groupName);

    setCursor(0, 2);
    print(timeStr);

    display();

    osMutexRelease(lcdMutexHandle);
}

void updateShowingDateTime() {
    updateDateTime();
    sprintf(timeStr, "%d/%d/%d - %d:%d:%d",
            getDateTime().dateVar.Year, getDateTime().dateVar.Month, getDateTime().dateVar.Date,
            getDateTime().timeVar.Hours, getDateTime().timeVar.Minutes, getDateTime().timeVar.Seconds
	);

    osMutexAcquire(lcdMutexHandle, osWaitForever);
    setCursor(0, 2);
    print(timeStr);

    display();

    osMutexRelease(lcdMutexHandle);
}

void handlePressingKeyOnAboutScreen() {
	// TODO

    /*switch (keypadNum) {
        case 0:
            programState = MenuState;
            menuStart();
            break;
        default:
            break;
    }*/
}
