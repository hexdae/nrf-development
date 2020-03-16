#include "hal_gpio.h"

#include "nrf_gpio.h"


void hal_gpio_config_output(uint32_t gpio)
{
	nrf_gpio_cfg_output(gpio);
}


void hal_gpio_config_output_range(uint32_t gpio_start, uint32_t gpio_end)
{
	nrf_gpio_range_cfg_output(gpio_start, gpio_end);
}


void hal_gpio_config_input(uint32_t gpio)
{
	nrf_gpio_cfg_input(gpio, NRF_GPIO_PIN_PULLDOWN);
}


void hal_gpio_config_input_range(uint32_t gpio_start, uint32_t gpio_end)
{
	nrf_gpio_range_cfg_input(gpio_start, gpio_end, NRF_GPIO_PIN_PULLDOWN);
}


void hal_gpio_write(uint32_t gpio, uint32_t value)
{
	nrf_gpio_pin_write(gpio, value);
}


bool hal_gpio_read(uint32_t gpio)
{
	if (nrf_gpio_pin_dir_get(gpio) == NRF_GPIO_PIN_DIR_OUTPUT)
	{
		return nrf_gpio_pin_out_read(gpio);
	}
	return nrf_gpio_pin_read(gpio);
}


void hal_gpio_toggle(uint32_t gpio)
{
	nrf_gpio_pin_toggle(gpio);
}


void hal_gpio_set(uint32_t gpio)
{
	nrf_gpio_pin_set(gpio);
}


void hal_gpio_clear(uint32_t gpio)
{
	nrf_gpio_pin_clear(gpio);
}