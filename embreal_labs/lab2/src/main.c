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
 * Zephyr application to demonstrate threads, mutexes and semaphores.
 * Used in EmbReal Lab exercise 2.
 *
 ******************************************************************************/

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/zephyr.h>

/* Size of thread stack in bytes */
#define STACK_SIZE 1024

/* Thread priorities */
/* Cooperative (non-preemptible)*/
// #define PRIORITY0 -1
// #define PRIORITY1 -2
// #define PRIORITY2 -3

/* Preemptible */
#define PRIORITY0 1
#define PRIORITY1 1
#define PRIORITY2 1



#define TS_MAX_PRIO -99 // prio range from -99 to +99
#define TS_LENGTH 200   // Time slice length in ms

/* IO Config */
#define LED0_NODE DT_NODELABEL(mc_led0)
#define LED1_NODE DT_NODELABEL(mc_led1)
#define LED2_NODE DT_NODELABEL(mc_led2)

#define SLEEP_TIME_US 500000 // 0.5s

// Get spec from overlay file using node labels
static struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);


/* Setup Threads */
static struct k_thread thread0;
static struct k_thread thread1;
static struct k_thread thread2;

// Define memory regions to use for thread stacks
K_THREAD_STACK_DEFINE(stack0, STACK_SIZE);
K_THREAD_STACK_DEFINE(stack1, STACK_SIZE);
K_THREAD_STACK_DEFINE(stack2, STACK_SIZE);
// => syms "stack0", ..., "stack2" 

// Declarations of thread functions defined later in this file
static void blink0(void *p1, void *p2, void *p3);
static void blink1(void *p1, void *p2, void *p3);
static void blink2(void *p1, void *p2, void *p3);
static void blink(const struct gpio_dt_spec led, int sleep_time_us);

int main()
{
	printk("Program Start \n");

	// configure IO
	gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
	gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
	gpio_pin_configure_dt(&led2, GPIO_OUTPUT_INACTIVE);

	// Activate time sliceing for round robin
	k_sched_time_slice_set(TS_LENGTH, TS_MAX_PRIO); // Yields current thread after each TS_LENGTH

	// Create led blink threads
	k_thread_create(&thread0, stack0, STACK_SIZE, blink0, NULL, NULL, NULL,
	                PRIORITY0, 0, K_NO_WAIT);

	k_thread_create(&thread1, stack1, STACK_SIZE, blink1, NULL, NULL, NULL,
					PRIORITY1, 0, K_NO_WAIT);

	k_thread_create(&thread2, stack2, STACK_SIZE, blink2, NULL, NULL, NULL,
					PRIORITY2, 0, K_NO_WAIT);
	/*
	k_thread_create Parameters:
		new_thread – Pointer to uninitialized struct k_thread
		stack – Pointer to the stack space.
		stack_size – Stack size in bytes.
		entry – Thread entry function.
		p1 – 1st entry point parameter.
		p2 – 2nd entry point parameter.
		p3 – 3rd entry point parameter.
		prio – Thread priority.
		options – Thread options.
		delay – Scheduling delay, or K_NO_WAIT (for no delay).
	*/
}

/* -------------------------------------------------------------------------------
 * Thread entry functions
 * ------------------------------------------------------------------------------- */

static void blink0(void *p1, void *p2, void *p3)
{
	k_thread_name_set(NULL, "thread 0"); // for tracing and debugging (NULL -> current thread)
	blink(led0, SLEEP_TIME_US);
}

static void blink1(void *p1, void *p2, void *p3)
{
	k_thread_name_set(NULL, "thread 1"); // for tracing and debugging (NULL -> current thread)
	blink(led1, SLEEP_TIME_US);
}

static void blink2(void *p1, void *p2, void *p3)
{
	k_thread_name_set(NULL, "thread 2"); // for tracing and debugging (NULL -> current thread)
	blink(led2, SLEEP_TIME_US);
}

/** Blink LED in infinite loop */
void blink(const struct gpio_dt_spec led, int sleep_time_us)
{
	while (1) {
		// print which thread is using function
		printk("%s start \n", k_thread_name_get(k_current_get()));

		gpio_pin_toggle_dt(&led);

		k_busy_wait(sleep_time_us); // execute do nothing 
		//k_usleep(sleep_time_us); // put thread in sleep state (reschedule point)
							     // -> other threads can jump in

		printk("%s end \n", k_thread_name_get(k_current_get()));
	}
}
