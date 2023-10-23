/*******************************************************************************
 *  _____       ______   ____
 * |_   _|     |  ____|/ ____|  Institute of Embedded Systems
 *   | |  _ __ | |__  | (___    Zurich University of Applied Sciences
 *   | | | '_ \|  __|  \___ \   8401 Winterthur, Switzerland
 *  _| |_| | | | |____ ____) |
 * |_____|_| |_|______|_____/
 *
 *******************************************************************************
 *
 * Zephyr application to demonstrate serial print and GPIO function.
 * Used in EmbReal Lab exercise 1.
 *
 ******************************************************************************/

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/zephyr.h>

#define SLEEP_TIME_MS 1

/*
 * Exercise 2
 * Get button / LED devive from the devicetree
 */

#define SW0_NODE DT_NODELABEL(mc_t0)
#define SW1_NODE DT_NODELABEL(mc_t1)

#define LED0_NODE DT_NODELABEL(mc_led0)
#define LED1_NODE DT_NODELABEL(mc_led1)

/* Check if devices are defined in device tree */
// BUILD_ASSERT(DT_NODE_HAS_STATUS(SW0_NODE, okay),
//              "SW0 node not found or not enabled");
// BUILD_ASSERT(DT_NODE_HAS_STATUS(SW1_NODE, okay),
//              "SW1 node not found or not enabled");
// BUILD_ASSERT(DT_NODE_HAS_STATUS(LED0_NODE, okay),
//              "LED0 node not found or not enabled");
// BUILD_ASSERT(DT_NODE_HAS_STATUS(LED1_NODE, okay),
//              "LED1 node not found or not enabled");

/*
 * Exercise 3
 * Create GPIO structs for switches and LEDs
 */
// gpio device tree structs                      in MC1-Board.overlay   v
static const struct gpio_dt_spec SW0_spec = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
static const struct gpio_dt_spec SW1_spec = GPIO_DT_SPEC_GET(SW1_NODE, gpios);

static const struct gpio_dt_spec LED0_spec = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec LED1_spec = GPIO_DT_SPEC_GET(LED1_NODE, gpios);

int main(void)
{
	int rc;

	/*
	 * Exercise 4
	 * Configure GPIOs for switches as inputs and GPIOs for LEDs as outputs
	 */

	rc = gpio_pin_configure_dt(&SW0_spec, GPIO_INPUT);
	printk("GPIO for SW0 configured. Returned %d\n", rc);

	rc = gpio_pin_configure_dt(&SW1_spec, GPIO_INPUT);
	printk("GPIO for SW1 configured. Returned %d\n", rc);

	rc = gpio_pin_configure_dt(&LED0_spec, GPIO_OUTPUT);
	printk("GPIO for LED0 configured. Returned %d\n", rc);

	rc = gpio_pin_configure_dt(&LED1_spec, GPIO_OUTPUT);
	printk("GPIO for LED1 configured. Returned %d\n", rc);

	/*
	 * Exercise 1
	 * Print a kernel debug message to your serial console
	 */
	printk("Hello Again!");

	while (1) {
		/*
		 * Exercise 5
		 * Periodically check switch states and set LEDs accordingly
		 */
		
		// Map switch states to LED states
		gpio_pin_set_dt(&LED0_spec, gpio_pin_get_dt(&SW0_spec));
		gpio_pin_set_dt(&LED1_spec, gpio_pin_get_dt(&SW1_spec));

		k_msleep(SLEEP_TIME_MS);
	}
}
