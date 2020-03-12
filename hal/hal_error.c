#include "hal_error.h"

hal_error_t convert_sdk_error(ret_code_t err)
{
	switch(err)
	{
		case 0:
			return HAL_OK;
		default:
			return HAL_FAIL;
	}
}