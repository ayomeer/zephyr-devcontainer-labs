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
 * Implementation of the dining philosophers problem
 *
 ******************************************************************************/

/******************
 * MUTEX VERSION
******************/

#include <SEGGER_SYSVIEW.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/random/rand32.h>
#include <zephyr/zephyr.h>

#include "display.h"

// Already defined in util.h
// #define MAX(x, y) (((x) > (y)) ? (x) : (y))
// #define MIN(x, y) (((x) < (y)) ? (x) : (y))

/* Philosopher eat time */
#define EAT_TIME 1500

/* Philosopher thinking time */
#define MAX_THINKING_TIME (EAT_TIME * 4)
#define MIN_THINKING_TIME EAT_TIME

/* Stack size for each thread in bytes */
#define STACK_SIZE 2048

/* Philosopher thread priority */
#define PRIO_PHIL 1

/* Arrays for semaphores (chopsticks) and philosopher eat counter. */
struct k_mutex chopsticks[CONFIG_NUM_PHIL]; // CONFIG_NUM_PHIL defined in prj.conf
uint16_t phil_eat_count[CONFIG_NUM_PHIL];

/* Data for philosopher threads */
static K_THREAD_STACK_ARRAY_DEFINE(stacks, CONFIG_NUM_PHIL, STACK_SIZE);
static struct k_thread threads[CONFIG_NUM_PHIL];

static void philosopher(void *p1, void *p2, void *p3);
static void claim_chopstick(uint8_t n, uint8_t chopstick_id);
static void release_chopstick(uint8_t n, uint8_t chopstick_id);

void main()
{
	/* Initialize mutexes */
	for (uint8_t n = 0; n < CONFIG_NUM_PHIL; ++n) {
		k_mutex_init(&chopsticks[n]);
	}

	display_init();

	/* Start threads */
	for (uint8_t n = 0; n < CONFIG_NUM_PHIL; ++n) {
		k_thread_create(&threads[n], &stacks[n][0], STACK_SIZE,
		                philosopher, INT_TO_POINTER(n), NULL, NULL,
		                PRIO_PHIL, 0, K_NO_WAIT);
	}
	/*
		INT_TO_POINTER(n): 	&n points to value of n, which is different, when
							threads run. Need pointer to constant int value
	*/
	return;
}


/** --- Philosopher (entry) thread functions ------------------------------------------*/
static void philosopher(void *p1, void *p2, void *p3) // arg p1 = {0,1,2,3,4,5}, num_phil
{
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	uint8_t n = POINTER_TO_INT(p1); // change pointer arg back to normal variable

	uint8_t left_chopstick = n;
	uint8_t right_chopstick = (n + CONFIG_NUM_PHIL - 1) % CONFIG_NUM_PHIL;

	while (1) {
		/* Philosopher thinking for a random time between MIN_THINKING_TIME and MAX_THINKING_TIME */
		display_thinking(n, true);
		k_msleep(MIN_THINKING_TIME + sys_rand32_get() % (MAX_THINKING_TIME - MIN_THINKING_TIME));	         
		display_thinking(n, false);
		/* NOTE:
			k_msleep() to let other threads run
		*/

		/* Philosopher *tries* to grab chopsticks to start eating */
		// Resource hirarchy solution: take lower idx chopstick first
		claim_chopstick(n, MIN(left_chopstick, right_chopstick));
		k_msleep(6000); // /!\ FORCING DEADLOCK
		claim_chopstick(n, MAX(left_chopstick, right_chopstick));

		/* If both chopsticks acquired, philosopher starts eating */
		k_busy_wait(EAT_TIME * USEC_PER_MSEC);
		/* NOTE:
			k_busy_wait() does NOT let other threads run
		*/

		// Done eating
		release_chopstick(n, left_chopstick);
		release_chopstick(n, right_chopstick);
		
		// Update eat count after finishing eating
		phil_eat_count[n] += 1;
		display_eat_count(n, phil_eat_count[n]);
	}
}

/* --- Philosopher actions --------------------------------------------------------- */
static void claim_chopstick(uint8_t n, uint8_t chopstick_id)
{
	k_mutex_lock(&chopsticks[chopstick_id], K_FOREVER); 
	display_claim_chopstick(n, chopstick_id);
}

static void release_chopstick(uint8_t n, uint8_t chopstick_id)
{
	display_release_chopstick(n, chopstick_id);
	k_mutex_unlock(&chopsticks[chopstick_id]);
}

