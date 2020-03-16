#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>
#include <stdbool.h>

void hal_gpio_config_output(uint32_t gpio);
void hal_gpio_config_output_range(uint32_t gpio_start, uint32_t gpio_end);
void hal_gpio_config_input(uint32_t gpio);
void hal_gpio_config_input_range(uint32_t gpio_start, uint32_t gpio_end);

void hal_gpio_write(uint32_t gpio, uint32_t value);
bool hal_gpio_read(uint32_t gpio);
void hal_gpio_toggle(uint32_t gpio);
void hal_gpio_set(uint32_t gpio);
void hal_gpio_clear(uint32_t gpio);

#endif // HAL_GPIO_H