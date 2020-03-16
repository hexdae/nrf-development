#ifndef HAL_ERROR_H
#define HAL_ERROR_H

#include <stdint.h>

#include "sdk_errors.h"

typedef enum {
	HAL_OK,
	HAL_FAIL,
} hal_error_t;


hal_error_t hal_convert_sdk_error(ret_code_t err);

#endif // HAL_ERROR_H