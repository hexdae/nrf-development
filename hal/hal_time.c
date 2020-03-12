#include "hal_time.h"

#include "nrf_delay.h"

void hal_delay_ms(uint32_t ms)
{
	nrf_delay_ms(ms);
}