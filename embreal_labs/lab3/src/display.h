#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

void display_init();
int display_eat_count(uint8_t philosopher, uint16_t count);
int display_claim_chopstick(uint8_t n, uint8_t chopstick_id);
int display_release_chopstick(uint8_t n, uint8_t chopstick_id);
int display_thinking(uint8_t n, bool is_thinking);

#endif /* DISPLAY_H_ */
