/*
 * config.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */


#include "config.h"
#include <string.h>

int moveEnemiesDownInterval = 5000;

int heroLevelHealth = 2;

int killedEnemyCountToWin = 15;

char playerName[MAX_NAME_LENGTH] = "TestPlayer";

int score = 0;

GameState state;

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

void setPlayerName(char name[MAX_NAME_LENGTH]) {
	strcpy(playerName, name); // This might cause a bug
}

char* getPlayerName() {
	return playerName;
}

void incrementScore() {
	score++;
}

int getScore() {
	return score;
}

void setGameState(GameState s) {
	state = s;
}

GameState getGameState() {
	return state;
}
