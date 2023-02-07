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
#include "bullets.h"
#include "config.h"

const int HERO_ROW = VERTICAL_LCD_ROWS - 1;

int lcdMat[VERTICAL_LCD_ROWS][VERTICAL_LCD_COLUMNS] = {

		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
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

		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },
		{ CT_SPACE, CT_SPACE, CT_SPACE, CT_SPACE },

		{ CT_SPACE, CT_HERO, CT_SPACE, CT_SPACE },
};

int copyLcdMat[VERTICAL_LCD_ROWS][VERTICAL_LCD_COLUMNS] = { 0 };

void setLoc(int row, int col) {
	setCursor(row, VERTICAL_LCD_COLUMNS - col - 1);
}

void doCopy() {
	for(int r = 0; r < VERTICAL_LCD_ROWS; r++) {
		for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
			copyLcdMat[r][c] = lcdMat[r][c];
		}
	}
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
			if(copyLcdMat[r][c] == lcdMat[r][c])
				continue;

			osMutexAcquire(lcdMutexHandle, osWaitForever);
			setLoc(r, c);
			int type = lcdMat[r][c];
			write(type);
			osMutexRelease(lcdMutexHandle);
		}
	}

	doCopy();
}

void clearAt(int row, int col) {
	lcdMat[row][col] = CT_SPACE;
}

void putBullet(Bullet bullet) {
	lcdMat[bullet.row][bullet.col] = CT_BULLET;
}

int getHeroCol() {
	for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
		if(lcdMat[HERO_ROW][c] == CT_HERO)
			return c;
	}
	return -1;
}

int getHeroRow() {
	return HERO_ROW;
}

void moveHeroRight() {
	int currentCol = getHeroCol();
	int rightCol = (currentCol + 1) % VERTICAL_LCD_COLUMNS;
	clearAt(HERO_ROW, currentCol);
	lcdMat[HERO_ROW][rightCol] = CT_HERO;
}

void moveHeroLeft() {
	int currentCol = getHeroCol();

	int leftCol = (currentCol - 1);
	if(leftCol  < 0)
		leftCol  = VERTICAL_LCD_COLUMNS - 1;

	clearAt(HERO_ROW, currentCol);
	lcdMat[HERO_ROW][leftCol ] = CT_HERO;
}

int findFirstRowOfEnemies() {
	for(int r = 0; r < VERTICAL_LCD_ROWS; r++) {
		for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
			if(lcdMat[r][c] == CT_ENEMY)
				return r;
		}
	}
	return UNDEFINED;
}

int findLastRowOfEnemies() {
	for(int r = VERTICAL_LCD_ROWS; r >= 0; r--) {
		for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
			if(lcdMat[r][c] == CT_ENEMY)
				return r;
		}
	}
	return UNDEFINED;
}

int findRandomEnemyCol(int row) {
	int index = (rand() % 4);
	if(lcdMat[row][index] == CT_ENEMY)
		return index;
	return UNDEFINED;
}

void moveDown(int row, int col) {
	int pawn = lcdMat[row][col];
	lcdMat[row + 1][col] = pawn;
	lcdMat[row][col] = CT_SPACE;
}

int getWinner() {
	if(getHeroLevelHealth() <= 0)
		return GS_HERO_LOST;

	if(getKilledEnemyCountToWin() <= 0)
		return GS_HERO_WON;

	for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
		if(lcdMat[HERO_ROW][c] == CT_ENEMY) {
			return GS_HERO_LOST;
		}
	}
	return GS_NOT_FINISHED;
}

int isFinished() {
	return getWinner() != GS_NOT_FINISHED;
}

void moveEnemiesDown() {
	int startRow = findFirstRowOfEnemies();
	int endRow = findLastRowOfEnemies();

	for(int r = endRow; r >= startRow; r--) {
		for(int c = 0; c < VERTICAL_LCD_COLUMNS; c++) {
			if(lcdMat[r][c] == CT_ENEMY)
				moveDown(r, c);
		}
	}
}

int isEnemy(int row, int col) {
	return lcdMat[row][col] == CT_ENEMY;
}
