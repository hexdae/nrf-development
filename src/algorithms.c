#include "algorithms.h"

uint8_t 
retry (bool (*function)(), uint8_t max_attempts)
{
	for(uint8_t attempt = 0; attempt < max_attempts; attempt++)
	{
		if(function())
		{
			return attempt;
		}
	}
	return max_attempts;
}