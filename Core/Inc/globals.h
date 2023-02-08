/*
 * globals.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

#include "cmsis_os.h"
#include "req.h"

extern osMutexId_t lcdMutexHandle;

extern RTC_HandleTypeDef hrtc;

#endif /* INC_GLOBALS_H_ */
