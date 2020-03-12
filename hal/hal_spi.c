#include "hal_spi.h"

#include "nrfx_spi.h"

#define SPI_INSTANCE 0
static const nrfx_spi_t spi = NRFX_SPI_INSTANCE(SPI_INSTANCE);
static volatile bool spi_xfer_done;

static const int hal_to_nrf_spi_frequency_map[] =
{
	[HAL_SPI_FREQ_125K] = NRF_SPI_FREQ_125K,
    [HAL_SPI_FREQ_250K] = NRF_SPI_FREQ_250K,
    [HAL_SPI_FREQ_500K] = NRF_SPI_FREQ_500K,
    [HAL_SPI_FREQ_1M] = NRF_SPI_FREQ_1M,
    [HAL_SPI_FREQ_2M] = NRF_SPI_FREQ_2M,
    [HAL_SPI_FREQ_4M] = NRF_SPI_FREQ_4M,
    [HAL_SPI_FREQ_8M] = NRF_SPI_FREQ_8M
};


static inline int nrf_spi_frequency(hal_spi_frequency_t frequency)
{
	return hal_to_nrf_spi_frequency_map[frequency];
}


nrfx_spi_evt_handler_t spi_event_handler(nrfx_spi_evt_t const * p_event, void * p_context)
{
    spi_xfer_done = true;
    return NULL;
}


void hal_spi_initialize(hal_spi_config_t* config)
{
	nrfx_spi_config_t spi_config = NRFX_SPI_DEFAULT_CONFIG;
    spi_config.ss_pin   = config->ss_pin;
    spi_config.miso_pin = config->miso_pin;
    spi_config.mosi_pin = config->mosi_pin;
    spi_config.sck_pin  = config->sck_pin;
    spi_config.frequency = nrf_spi_frequency(config->frequency); 
    nrfx_spi_init(&spi, &spi_config, NULL, NULL);
}


void hal_spi_write(uint8_t* data, size_t size)
{
    static const int TX_FLAGS = 0x0;
    nrfx_spi_xfer_desc_t tx = NRFX_SPI_XFER_TX(data, size); 
	nrfx_spi_xfer(&spi, &tx, TX_FLAGS);
}


void hal_spi_read(uint8_t* data, size_t size)
{
    static const int RX_FLAGS = 0x0;
    nrfx_spi_xfer_desc_t rx = NRFX_SPI_XFER_RX(data, size);
	nrfx_spi_xfer(&spi, &rx, RX_FLAGS);
}