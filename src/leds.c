#include "leds.h"

static uint16_t * leds_puerto;


static int led_it_bit(int led_index) { return 1 << (led_index - 1); }

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
    
    *leds_puerto |= led_it_bit(led);
}

/**
 * @brief Turns off the specified LED.
 *
 * This function sets the state of the specified LED to off.
 *
 * @param led The identifier of the LED to turn off.
 */
void leds_turn_off(int led)
{
    *leds_puerto = 0;
}

/**
 * @brief returns the state of a specified LED.
 *
 * This function returns the state of the specified LED
 *
 * @param led The identifier of the LED to verify the state
 */
int leds_state(int led)
{
    return ((*leds_puerto & (1 << led)) != 0);
}