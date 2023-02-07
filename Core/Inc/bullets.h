/*
 * bullets.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_BULLETS_H_
#define INC_BULLETS_H_

#include "characters.h"

#define MAX_BULLET_COUNT 5

void shoot(int startRow, int startCol, Dir dir);

int getBulletCount();

Bullet getBullet(int index);

void moveAllBullets();

void handleHittingHero();

void handleHittingEnemy();

void updateAllBulletsOnMatrix();

#endif /* INC_BULLETS_H_ */
