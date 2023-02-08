/*
 * lcd.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "characters.h"

#define VERTICAL_LCD_ROWS 20
#define VERTICAL_LCD_COLUMNS 4

void initLcd();

void updateLcd();

void clearAt(int row, int col);

void moveHeroRight();

void moveHeroLeft();

void moveDown(int row, int col);

int getHeroRow();

int getHeroCol();

void putBullet(Bullet bullet);

int isEnemy(int row, int col);

int findRandomEnemyCol(int row);

int findLastRowOfEnemies();

void moveEnemiesDown();

void commandHeroToShoot();

#endif /* INC_LCD_H_ */
