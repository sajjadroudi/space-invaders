/*
 * config.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */


#include "config.h"

int moveEnemiesDownInterval;

int heroLevelHealth;

int killedEnemyCountToWin;

void setDifficultyLevel(int level) {
	switch(level) {
	case DIFFICULTY_EASY:
		moveEnemiesDownInterval = 5000;
		heroLevelHealth = 7;
		killedEnemyCountToWin = 15;
		break;
	case DIFFICULTY_NORMAL:
		moveEnemiesDownInterval = 3000;
		heroLevelHealth = 5;
		killedEnemyCountToWin = 25;
		break;
	case DIFFICULTY_HARD:
		moveEnemiesDownInterval = 1000;
		heroLevelHealth = 3;
		killedEnemyCountToWin = 35;
		break;
	}
}

int getMoveEnemiesDownInterval() {
	return moveEnemiesDownInterval;
}

int getHeroLevelHealth() {
	return heroLevelHealth;
}

int getKilledEnemyCountToWin() {
	return killedEnemyCountToWin;
}

void incrementKilledEnemyCount() {
	killedEnemyCountToWin++;
}

void decrementHeroLevelHealth() {
	heroLevelHealth--;
}
