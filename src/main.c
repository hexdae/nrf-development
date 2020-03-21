/* Standard Library headers */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* HAL headers */
#include "hal_gpio.h"
#include "hal_spi.h"
#include "hal_time.h"
#include "hal_power.h"

/* Waveshare e-Paper header */
#include "EPD_2in9.h"
#include "GUI_Paint.h"

/* Source headers */
#include "qrcodegen.h"

#define IMAGE_SIZE ((EPD_2IN9_WIDTH / 8) * EPD_2IN9_HEIGHT)
#define SSID       "SSID"
#define PASSWORD   "PASSWORD"

uint8_t image[IMAGE_SIZE];
char wifi_string[50];
const uint32_t LED = 17;

hal_spi_config_t spi_config = 
{
    .miso_pin = 0xFF,
    .mosi_pin = 27,
    .sck_pin = 26,
    .ss_pin = 25,
    .frequency = HAL_SPI_FREQ_4M,
};

void set_wifi_credentials(char* wifi_string, char* ssid, char* password)
{
    sprintf(wifi_string, "WIFI:S:%s;T:WPA;P:%s;;", ssid, password);
}   

void Paint_QR(const char *text, uint8_t scale, uint16_t cx, uint16_t cy) {

    // Make and print the QR Code symbol
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    qrcodegen_encodeText(
        text, 
        tempBuffer, 
        qrcode, 
        qrcodegen_Ecc_LOW,
        qrcodegen_VERSION_MIN, 
        qrcodegen_VERSION_MAX, 
        qrcodegen_Mask_AUTO, 
        true
    );

    int size = qrcodegen_getSize(qrcode);
    int border = 1;

    for (int y = -border; y < size + border; y++) {
        for (int x = -border; x < size + border; x++) {
            uint8_t color = qrcodegen_getModule(qrcode, x, y) ? BLACK : WHITE;
            Paint_DrawPoint(cx + (x * scale), cy + (y * scale), color, scale, DOT_FILL_AROUND);
        }
    }
}

int main(void)
{
    /* Set the Wi-Fi configuration */
    set_wifi_credentials(wifi_string, SSID, PASSWORD);

    /* Configure GPIOs */
    hal_gpio_config_input(EPD_BUSY_PIN);
    hal_gpio_config_output(EPD_RST_PIN);
    hal_gpio_config_output(EPD_DC_PIN);
    hal_gpio_config_output(LED);

    /* Configure SPI. */
    hal_spi_initialize(&spi_config);

    /* Initialize e-Paper display */
    EPD_2IN9_Init(EPD_2IN9_FULL);

    /* Display Wi-Fi QR Code */
    Paint_NewImage(image, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT, 270, WHITE);
    Paint_Clear(WHITE);
    Paint_DrawString_EN(80, 10, "Connect to Wi-Fi", &Font12, WHITE, BLACK);
    Paint_QR(wifi_string, DOT_PIXEL_2X2, 105, 50);
    EPD_2IN9_Display(image);

    /* Toggle LEDs. */
    while (true)
    {
        hal_gpio_toggle(LED);
        hal_delay_ms(100);
        hal_power_set_mode(HAL_LOW_POWER);
    }
}