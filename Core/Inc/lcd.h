/*
 * lcd.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "characters.h"

#define LCD_D_8 GPIO_PIN_8
#define LCD_D_9 GPIO_PIN_9
#define LCD_D_10 GPIO_PIN_10
#define LCD_D_11 GPIO_PIN_11
#define LCD_D_12 GPIO_PIN_12
#define LCD_D_13 GPIO_PIN_13
#define LCD_D_14 GPIO_PIN_14

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

#endif /* INC_LCD_H_ */
