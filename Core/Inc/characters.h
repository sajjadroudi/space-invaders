/*
 * characters.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_CHARACTERS_H_
#define INC_CHARACTERS_H_

#include "req.h"

#define CT_SPACE 0
#define CT_HERO 1
#define CT_ENEMY 2
#define CT_BULLET 3

typedef enum {
	UP,
	DOWN
} Dir;

typedef struct {
	int row;
	int col;
	Dir direction;
} Bullet;

extern byte enemyByte[];

extern byte heroByte[];

extern byte spaceByte[];

extern byte bulletByte[];

#endif /* INC_CHARACTERS_H_ */
