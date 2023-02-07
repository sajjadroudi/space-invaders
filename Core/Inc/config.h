/*
 * config.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#define DIFFICULTY_EASY 0
#define DIFFICULTY_NORMAL 1
#define DIFFICULTY_HARD 2

#define GS_HERO_WON 1
#define GS_HERO_LOST -1
#define GS_NOT_FINISHED 0

void setDifficultyLevel(int level);

int getMoveEnemiesDownInterval();

int getHeroLevelHealth();

int getKilledEnemyCountToWin();

void incrementKilledEnemyCount();

void decrementHeroLevelHealth();

#endif /* INC_CONFIG_H_ */
