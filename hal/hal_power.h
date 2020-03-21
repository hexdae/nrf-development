#ifndef HAL_POWER_H
#define HAL_POWER_H

#include "hal_error.h"

typedef enum
{
	HAL_POWER_ON, 	//< Normal power mode.
    HAL_LOW_POWER,	//< Low power mode.
    HAL_DEEP_SLEEP,	//< Deep sleep mode. 
}hal_power_mode_t;

void hal_power_initialize();
void hal_power_set_mode(hal_power_mode_t mode);

#endif // HAL_POWER_H