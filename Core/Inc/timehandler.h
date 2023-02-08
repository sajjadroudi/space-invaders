/*
 * timehandler.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_TIMEHANDLER_H_
#define INC_TIMEHANDLER_H_

#include "req.h"

typedef struct {
    RTC_DateTypeDef dateVar;
    RTC_TimeTypeDef timeVar;
} __attribute__((aligned(32))) dateTimeType;

extern dateTimeType dateTime;

dateTimeType getDateTime();

void updateDateTime();


#endif /* INC_TIMEHANDLER_H_ */
