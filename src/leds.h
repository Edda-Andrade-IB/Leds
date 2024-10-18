#include <stdint.h>

/*
* @brief Initializes the LED module.
* by EddaAndrade
*/

void leds_init(uint16_t *puerto);

int leds_turn_on(int led);

int leds_turn_off(int led);

int leds_state(int led);

void leds_turn_all_on(void);

void leds_turn_all_off(void);
