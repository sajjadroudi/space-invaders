/*
 * timehandler.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Sajjad
 */

#include "timehandler.h"

dateTimeType dateTime;

void updateDateTime() {
    HAL_RTC_GetTime(&hrtc, &dateTime.timeVar, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &dateTime.dateVar, RTC_FORMAT_BIN);
}

dateTimeType getDateTime() {
    return dateTime;
}
