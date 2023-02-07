/*
 * bullets.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */
#include "bullets.h"
#include "lcd.h"
#include "config.h"

Bullet bullets[MAX_BULLET_COUNT];

int bulletCount = 0;

void shoot(int startRow, int startCol, Dir dir) {
	if(bulletCount >= MAX_BULLET_COUNT)
		return;

	bullets[bulletCount].row = startRow;
	bullets[bulletCount].col = startCol;
	bullets[bulletCount].direction = dir;

	putBullet(bullets[bulletCount]);

	bulletCount++;
}

void removeBullet(int index) {
	for(int i = index + 1; i < getBulletCount(); i++) {
		bullets[i - 1] = bullets[i];
	}
	bulletCount--;
}

void moveBullet(int bulletIndex) {

	clearAt(bullets[bulletIndex].row, bullets[bulletIndex].col);

	if(bullets[bulletIndex].direction == UP) {
		bullets[bulletIndex].row--;
	} else {
		bullets[bulletIndex].row++;
	}

	int row = bullets[bulletIndex].row;
	if(row < 0 || row >= VERTICAL_LCD_ROWS) {
		removeBullet(bulletIndex);
	}
}

int getBulletCount() {
	return bulletCount;
}

Bullet getBullet(int index) {
	return bullets[index];
}

void moveAllBullets() {
	for(int i = 0; i < getBulletCount(); i++) {
		moveBullet(i);
	}
}

void updateAllBulletsOnMatrix() {
	for(int i = 0; i < getBulletCount(); i++) {
		int row = bullets[i].row;
		if(row >= 0 && row < VERTICAL_LCD_ROWS) {
			putBullet(bullets[i]);
		}
	}
}

void handleHittingEnemy() {
	for(int i = getBulletCount() - 1; i >= 0; i--) {
		Bullet bullet = getBullet(i);
		if(isEnemy(bullet.row, bullet.col)) {
			incrementKilledEnemyCount();
			clearAt(bullet.row, bullet.col);
			removeBullet(i);
			break;
		}
	}
}

void handleHittingHero() {
	for(int i = 0; i < getBulletCount(); i++) {
		Bullet bullet = getBullet(i);
		if(bullet.row == getHeroRow() && bullet.col == getHeroCol()) {
			decrementHeroLevelHealth();
			removeBullet(i);
			break;
		}
	}
}
