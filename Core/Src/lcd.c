/*
 * lcd.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#include <stdio.h>
#include <stdlib.h>
#include "req.h"
#include "characters.h"
#include "lcd.h"
#include "LiquidCrystal.h"
#include "globals.h"

const int HERO_ROW = VERTICAL_LCD_ROWS - 1;

int lcdMat[VERTICAL_LCD_ROWS][VERTICAL_LCD_COLUMNS] = {

		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },

		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },
		{ CT_ENEMY, CT_ENEMY, CT_ENEMY, CT_ENEMY },

		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },

		{ CT_SPACE, CT_HERO, CT_SPACE, CT_SPACE },
};

void setLoc(int row, int col) {
	setCursor(row, VERTICAL_LCD_COLUMNS - col - 1);
}

void initLcd() {
	osMutexAcquire(lcdMutexHandle, osWaitForever);
	LiquidCrystal(GPIOD, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
	begin(VERTICAL_LCD_ROWS, VERTICAL_LCD_COLUMNS);
	createChar(CT_SPACE, spaceByte);
	createChar(CT_HERO, heroByte);
	createChar(CT_ENEMY, enemyByte);
	createChar(CT_BULLET, bulletByte);
	osMutexRelease(lcdMutexHandle);
}

void updateLcd() {
	for(int r = 0; r < VERTICAL_LCD_ROWS; r++) {
		for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
			osMutexAcquire(lcdMutexHandle, osWaitForever);
			setLoc(r, c);
			int type = lcdMat[r][c];
			write(type);
			osMutexRelease(lcdMutexHandle);
		}
	}
}

void clearAt(int row, int col) {
	lcdMat[row][col] = CT_SPACE;
}

int getHeroCol() {
	for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
		if(lcdMat[HERO_ROW][c] == CT_HERO)
			return c;
	}
	return -1;
}

void moveHeroRight() {
	int currentCol = getHeroCol();
	int nextCol = (currentCol + 1) % VERTICAL_LCD_COLUMNS;
	clearAt(HERO_ROW, currentCol);
	lcdMat[HERO_ROW][nextCol] = CT_HERO;
}

void moveHeroLeft() {
	int currentCol = getHeroCol();

	int prevCol = (currentCol - 1);
	if(prevCol < 0)
		prevCol = VERTICAL_LCD_COLUMNS - 1;

	clearAt(HERO_ROW, currentCol);
	lcdMat[HERO_ROW][prevCol] = CT_HERO;
}

void commandHeroToShoot() {
// TODO
}
