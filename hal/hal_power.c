#include "hal_power.h"

#include "nrfx_power.h"

const nrfx_power_config_t nrf_power_config = {
	.dcdcen = 0,
	#if NRF_POWER_HAS_VDDH
    .dcdcenhv = 0,
	#endif
};

void hal_power_initialize()
{
	nrfx_power_init(&nrf_power_config);	
}

void hal_power_set_mode(hal_power_mode_t mode)
{
	switch(mode)
	{
		case HAL_LOW_POWER:
			NRF_POWER->SYSTEMOFF = 1;
			break;
		default:
			NRF_POWER->SYSTEMOFF = 0;
	}
}