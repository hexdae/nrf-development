#ifndef HAL_SPI_H
#define HAL_SPI_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "hal_error.h"

typedef enum {
	HAL_SPI_FREQ_125K,   ///< 125 kbps.
    HAL_SPI_FREQ_250K,   ///< 250 kbps.
    HAL_SPI_FREQ_500K,   ///< 500 kbps.
    HAL_SPI_FREQ_1M,     ///< 1 Mbps.
    HAL_SPI_FREQ_2M,     ///< 2 Mbps.
    HAL_SPI_FREQ_4M,     ///< 4 Mbps.
    HAL_SPI_FREQ_8M,     ///< 8 Mbps.
} hal_spi_frequency_t;

typedef struct config {
    uint32_t sck_pin;
    uint32_t mosi_pin;
    uint32_t miso_pin;
    uint32_t ss_pin;
    hal_spi_frequency_t frequency;
} hal_spi_config_t;

hal_error_t hal_spi_initialize(hal_spi_config_t* config);
hal_error_t hal_spi_write(uint8_t* data, size_t size);
hal_error_t hal_spi_read(uint8_t* data, size_t size);

#endif //HAL_SPI_H