#include "algorithms.h"

void 
retry (bool (*function)(), uint8_t attempts)
{
	for(uint8_t attempt = 0; attempt < attempts; attempts++)
	{
		if(function())
		{
			break;
		}
	}
}