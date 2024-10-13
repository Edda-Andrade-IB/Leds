#include "leds.h"

static uint16_t * leds_puerto;

/**
 * @brief Initializes the LED module.
 *
 * This function initializes the LED module by assigning the given port address to the global variable `leds_puerto`
 * and setting the port value to 0.
 *
 * @param puerto A pointer to the port address where the LEDs are connected.
 */
void leds_init(uint16_t *puerto)
{
    leds_puerto = puerto;
    *leds_puerto = 0;
}

/**
 * @brief Turns on a specific LED.
 *
 * This function turns on the LED specified by the `led` parameter by setting the port value to 4.
 *
 * @param led The index of the LED to turn on.
 */
void leds_turn_on(int led)
{
    *leds_puerto = 4;
}

void leds_turn_off(int led)
{
    *leds_puerto = 0;
}