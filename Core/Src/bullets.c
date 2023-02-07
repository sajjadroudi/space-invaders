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
	clearAt(bullets[index].row, bullets[index].col);
	for(int i = index + 1; i < getBulletCount(); i++) {
		bullets[i - 1] = bullets[i];
	}
	bulletCount--;
}

void moveBullet(int bulletIndex) {

	clearAt(bullets[bulletIndex].row, bullets[bulletIndex].col);

	if(bullets[bulletIndex].row <= 0 || bullets[bulletIndex].row >= VERTICAL_LCD_ROWS) {
		removeBullet(bulletIndex);
		return;
	}

	if(bullets[bulletIndex].direction == UP) {
		bullets[bulletIndex].row--;
	} else {
		bullets[bulletIndex].row++;
	}

	putBullet(bullets[bulletIndex]);
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

void handleHittingEnemy() {
	for(int i = getBulletCount() - 1; i >= 0; i--) {
		Bullet bullet = getBullet(i);
		if(isEnemy(bullet.row, bullet.col)) {
			incrementKilledEnemyCount();
			removeBullet(i);
			break;
		}
	}
}

int doesHitHero() {
	for(int i = 0; i < getBulletCount(); i++) {
		Bullet bullet = getBullet(i);
		if(bullet.row == getHeroRow() && bullet.col == getHeroCol()) {
			return 1;
		}
	}
	return 0;
}
