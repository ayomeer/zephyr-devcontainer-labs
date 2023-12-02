#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/rcc@40023800:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/clocks/pll)
 * Supported:
 *   - (/soc/adc@40012000)
 *   - (/soc/adc@40012100)
 *   - (/soc/adc@40012200)
 *   - (/soc/can@40006400)
 *   - (/soc/can@40006800)
 *   - (/soc/dac@40007400)
 *   - /soc/display-controller@40016800
 *   - (/soc/dma@40026000)
 *   - (/soc/dma@40026400)
 *   - (/soc/ethernet@40028000)
 *   - /soc/i2c@40005400
 *   - /soc/i2c@40005800
 *   - /soc/i2c@40005c00
 *   - (/soc/i2s@40003800)
 *   - (/soc/i2s@40003c00)
 *   - (/soc/memory@40024000)
 *   - /soc/memory-controller@a0000000
 *   - (/soc/rng@50060800)
 *   - (/soc/rtc@40002800)
 *   - (/soc/sdmmc@40012c00)
 *   - (/soc/serial@40004400)
 *   - (/soc/serial@40004800)
 *   - (/soc/serial@40004c00)
 *   - (/soc/serial@40005000)
 *   - (/soc/serial@40007800)
 *   - (/soc/serial@40007c00)
 *   - /soc/serial@40011000
 *   - (/soc/serial@40011400)
 *   - (/soc/spi@40003800)
 *   - (/soc/spi@40003c00)
 *   - (/soc/spi@40013000)
 *   - (/soc/spi@40013400)
 *   - /soc/spi@40015000
 *   - (/soc/spi@40015400)
 *   - (/soc/timers@40000000)
 *   - (/soc/timers@40000400)
 *   - (/soc/timers@40000800)
 *   - (/soc/timers@40000c00)
 *   - (/soc/timers@40001000)
 *   - (/soc/timers@40001400)
 *   - (/soc/timers@40001800)
 *   - (/soc/timers@40001c00)
 *   - (/soc/timers@40002000)
 *   - (/soc/timers@40010000)
 *   - (/soc/timers@40010400)
 *   - (/soc/timers@40014000)
 *   - (/soc/timers@40014400)
 *   - (/soc/timers@40014800)
 *   - (/soc/usb@40040000)
 *   - (/soc/usb@50000000)
 *   - (/soc/watchdog@40002c00)
 *   - /soc/pin-controller@40020000/gpio@40020000
 *   - /soc/pin-controller@40020000/gpio@40020400
 *   - /soc/pin-controller@40020000/gpio@40020800
 *   - /soc/pin-controller@40020000/gpio@40020c00
 *   - /soc/pin-controller@40020000/gpio@40021000
 *   - /soc/pin-controller@40020000/gpio@40021400
 *   - /soc/pin-controller@40020000/gpio@40021800
 *   - /soc/pin-controller@40020000/gpio@40021c00
 *   - /soc/pin-controller@40020000/gpio@40022000
 *   - /soc/pin-controller@40020000/gpio@40022400
 *   - /soc/pin-controller@40020000/gpio@40022800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_rcc_40023800[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 11, 8, 20, 15, 5, 19, 12, 7, 18, 9, 6, 3, 13, 10, 14, 22, 4, 17, DEVICE_HANDLE_ENDS };

/* 2 : /soc/interrupt-controller@40013c00:
 * Direct Dependencies:
 *   - (/soc)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_interrupt_controller_40013c00[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/pin-controller@40020000/gpio@40022800:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40022800[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/pin-controller@40020000/gpio@40022400:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40022400[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /soc/pin-controller@40020000/gpio@40022000:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40022000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/pin-controller@40020000/gpio@40021c00:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40021c00[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/pin-controller@40020000/gpio@40021800:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - (/gpio_keys/mc_button_0)
 *   - (/gpio_keys/mc_button_1)
 *   - (/gpio_keys/mc_button_2)
 *   - (/gpio_keys/mc_button_3)
 *   - (/leds/led_3)
 *   - (/leds/led_4)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40021800[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 8 : /soc/pin-controller@40020000/gpio@40021400:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - (/gpio_keys/mc_switch_0)
 *   - (/gpio_keys/mc_switch_1)
 *   - (/gpio_keys/mc_switch_2)
 *   - (/gpio_keys/mc_switch_3)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40021400[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 9 : /soc/pin-controller@40020000/gpio@40021000:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - (/leds/mc_led_0)
 *   - (/leds/mc_led_1)
 *   - (/leds/mc_led_2)
 *   - (/leds/mc_led_3)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40021000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 10 : /soc/pin-controller@40020000/gpio@40020c00:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - /soc/spi@40015000/ili9341@0
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40020c00[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 21, DEVICE_HANDLE_ENDS };

/* 11 : /soc/pin-controller@40020000/gpio@40020800:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - /soc/spi@40015000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40020800[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 20, DEVICE_HANDLE_ENDS };

/* 12 : /soc/pin-controller@40020000/gpio@40020400:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40020400[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 13 : /soc/pin-controller@40020000/gpio@40020000:
 * Direct Dependencies:
 *   - (/soc/pin-controller@40020000)
 *   - /soc/rcc@40023800
 * Supported:
 *   - (/gpio_keys/button)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pin_controller_40020000_S_gpio_40020000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 14 : /soc/serial@40011000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/usart1_rx_pa10)
 *   - (/soc/pin-controller@40020000/usart1_tx_pa9)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_serial_40011000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 15 : /soc/memory-controller@a0000000:
 * Direct Dependencies:
 *   - (/soc)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/fmc_a0_pf0)
 *   - (/soc/pin-controller@40020000/fmc_a10_pg0)
 *   - (/soc/pin-controller@40020000/fmc_a11_pg1)
 *   - (/soc/pin-controller@40020000/fmc_a12_pg2)
 *   - (/soc/pin-controller@40020000/fmc_a13_pg3)
 *   - (/soc/pin-controller@40020000/fmc_a14_pg4)
 *   - (/soc/pin-controller@40020000/fmc_a15_pg5)
 *   - (/soc/pin-controller@40020000/fmc_a1_pf1)
 *   - (/soc/pin-controller@40020000/fmc_a2_pf2)
 *   - (/soc/pin-controller@40020000/fmc_a3_pf3)
 *   - (/soc/pin-controller@40020000/fmc_a4_pf4)
 *   - (/soc/pin-controller@40020000/fmc_a5_pf5)
 *   - (/soc/pin-controller@40020000/fmc_a6_pf12)
 *   - (/soc/pin-controller@40020000/fmc_a7_pf13)
 *   - (/soc/pin-controller@40020000/fmc_a8_pf14)
 *   - (/soc/pin-controller@40020000/fmc_a9_pf15)
 *   - (/soc/pin-controller@40020000/fmc_d0_pd14)
 *   - (/soc/pin-controller@40020000/fmc_d10_pe13)
 *   - (/soc/pin-controller@40020000/fmc_d11_pe14)
 *   - (/soc/pin-controller@40020000/fmc_d12_pe15)
 *   - (/soc/pin-controller@40020000/fmc_d13_pd8)
 *   - (/soc/pin-controller@40020000/fmc_d14_pd9)
 *   - (/soc/pin-controller@40020000/fmc_d15_pd10)
 *   - (/soc/pin-controller@40020000/fmc_d1_pd15)
 *   - (/soc/pin-controller@40020000/fmc_d2_pd0)
 *   - (/soc/pin-controller@40020000/fmc_d3_pd1)
 *   - (/soc/pin-controller@40020000/fmc_d4_pe7)
 *   - (/soc/pin-controller@40020000/fmc_d5_pe8)
 *   - (/soc/pin-controller@40020000/fmc_d6_pe9)
 *   - (/soc/pin-controller@40020000/fmc_d7_pe10)
 *   - (/soc/pin-controller@40020000/fmc_d8_pe11)
 *   - (/soc/pin-controller@40020000/fmc_d9_pe12)
 *   - (/soc/pin-controller@40020000/fmc_nbl0_pe0)
 *   - (/soc/pin-controller@40020000/fmc_nbl1_pe1)
 *   - (/soc/pin-controller@40020000/fmc_sdcke1_pb5)
 *   - (/soc/pin-controller@40020000/fmc_sdclk_pg8)
 *   - (/soc/pin-controller@40020000/fmc_sdncas_pg15)
 *   - (/soc/pin-controller@40020000/fmc_sdne1_pb6)
 *   - (/soc/pin-controller@40020000/fmc_sdnras_pf11)
 *   - (/soc/pin-controller@40020000/fmc_sdnwe_pc0)
 * Supported:
 *   - /soc/memory-controller@a0000000/sdram
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_memory_controller_a0000000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 16, DEVICE_HANDLE_ENDS };

/* 16 : /soc/memory-controller@a0000000/sdram:
 * Direct Dependencies:
 *   - /soc/memory-controller@a0000000
 * Supported:
 *   - (/soc/memory-controller@a0000000/sdram/bank@1)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_memory_controller_a0000000_S_sdram[] = { 15, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 17 : /soc/i2c@40005c00:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/i2c3_scl_pa8)
 *   - (/soc/pin-controller@40020000/i2c3_sda_pc9)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40005c00[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 18 : /soc/i2c@40005800:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/i2c2_scl_pb10)
 *   - (/soc/pin-controller@40020000/i2c2_sda_pb11)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40005800[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 19 : /soc/i2c@40005400:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/i2c1_scl_pb8)
 *   - (/soc/pin-controller@40020000/i2c1_sda_pb9)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40005400[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 20 : /soc/spi@40015000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - /soc/pin-controller@40020000/gpio@40020800
 *   - (/soc/pin-controller@40020000/spi5_miso_pf8)
 *   - (/soc/pin-controller@40020000/spi5_mosi_pf9)
 *   - (/soc/pin-controller@40020000/spi5_nss_pf6)
 *   - (/soc/pin-controller@40020000/spi5_sck_pf7)
 * Supported:
 *   - /soc/spi@40015000/ili9341@0
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_spi_40015000[] = { 11, 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 21, DEVICE_HANDLE_ENDS };

/* 21 : /soc/spi@40015000/ili9341@0:
 * Direct Dependencies:
 *   - /soc/spi@40015000
 *   - /soc/pin-controller@40020000/gpio@40020c00
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_spi_40015000_S_ili9341_0[] = { 10, 20, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 22 : /soc/display-controller@40016800:
 * Direct Dependencies:
 *   - (/sdram@d0000000)
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/rcc@40023800
 *   - (/soc/pin-controller@40020000/ltdc_b2_pd6)
 *   - (/soc/pin-controller@40020000/ltdc_b3_pg11)
 *   - (/soc/pin-controller@40020000/ltdc_b4_pg12)
 *   - (/soc/pin-controller@40020000/ltdc_b5_pa3)
 *   - (/soc/pin-controller@40020000/ltdc_b6_pb8)
 *   - (/soc/pin-controller@40020000/ltdc_b7_pb9)
 *   - (/soc/pin-controller@40020000/ltdc_clk_pg7)
 *   - (/soc/pin-controller@40020000/ltdc_de_pf10)
 *   - (/soc/pin-controller@40020000/ltdc_g2_pa6)
 *   - (/soc/pin-controller@40020000/ltdc_g3_pg10)
 *   - (/soc/pin-controller@40020000/ltdc_g4_pb10)
 *   - (/soc/pin-controller@40020000/ltdc_g5_pb11)
 *   - (/soc/pin-controller@40020000/ltdc_g6_pc7)
 *   - (/soc/pin-controller@40020000/ltdc_g7_pd3)
 *   - (/soc/pin-controller@40020000/ltdc_hsync_pc6)
 *   - (/soc/pin-controller@40020000/ltdc_r2_pc10)
 *   - (/soc/pin-controller@40020000/ltdc_r3_pb0)
 *   - (/soc/pin-controller@40020000/ltdc_r4_pa11)
 *   - (/soc/pin-controller@40020000/ltdc_r5_pa12)
 *   - (/soc/pin-controller@40020000/ltdc_r6_pb1)
 *   - (/soc/pin-controller@40020000/ltdc_r7_pg6)
 *   - (/soc/pin-controller@40020000/ltdc_vsync_pa4)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_display_controller_40016800[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
