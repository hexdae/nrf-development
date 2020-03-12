#include <stdbool.h>
#include <stdint.h>

#include "hal_gpio.h"
#include "hal_time.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    const uint32_t LEDS_NUM = 4;
    const uint32_t LEDS[] = {17, 18, 19, 20};

    /* Configure output LEDs. */
    for (uint32_t i = 0; i < LEDS_NUM; ++i)
    {
        hal_gpio_config_output(LEDS[i]);
        hal_gpio_clear(LEDS[i]);
    }

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            hal_gpio_toggle(LEDS[i]);
            hal_delay_ms(500);
        }
    }
}