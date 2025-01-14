#include <stdint.h>
#include <stdio.h>
#include "leds.h"

static uint16_t *leds_puerto;

#define ERROR_CODE -1
#define SUCCESS_CODE 1

/**
 * @brief Checks if the given LED index is within the valid range.
 *
 * This function verifies whether the provided LED index is between 1 and 16, inclusive.
 * If the index is outside this range, an error code is returned. Otherwise, a success code is returned.
 *
 * @param led The index of the LED to check.
 * @return int Returns ERROR_CODE if the index is invalid, otherwise returns SUCCESS_CODE.
 */
int check_led_index(int led)
{
    if (led < 1 || led > 16)
    {
        return ERROR_CODE;
    }
    return SUCCESS_CODE;
}
/**
 * @brief Computes the bitmask for a given LED index.
 *
 * This function takes an LED index and returns the corresponding bitmask
 * by shifting 1 to the left by (led_index - 1) positions.
 *
 * @param led_index The index of the LED (1-based index).
 * @return The bitmask corresponding to the given LED index.
 */
static int led_it_bit(int led_index) { return 1 << (led_index - 1); }

/**
 * @brief Initializes the LED module.
 *
 * This function initializes the LED module by assigning the provided port address to the global variable `leds_puerto`.
 * It also ensures that all LEDs are turned off initially by setting the port value to 0.
 *
 * @param puerto A pointer to the port address where the LEDs are connected.
 */
void leds_init(uint16_t *puerto)
{
    if (puerto == NULL)
    {
        return;
    }
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
int leds_turn_on(int led)
{
    if (check_led_index(led) == ERROR_CODE)
    {
        return ERROR_CODE;
    }
    else
    {

        *leds_puerto |= led_it_bit(led);
        return SUCCESS_CODE;
    }
}

/**
 * @brief Turns off the specified LED.
 *
 * This function sets the state of the specified LED to off.
 *
 * @param led The identifier of the LED to turn off.
 */
int leds_turn_off(int led)
{
    if (check_led_index(led) == ERROR_CODE)
    {
        return ERROR_CODE;
    }
    else

        *leds_puerto &= ~led_it_bit(led);
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
    if (check_led_index(led) == ERROR_CODE)
    {
        return ERROR_CODE;
    }
    else
    {
        return (*leds_puerto & led_it_bit(led)) != 0;
    }
}

/**
 * @brief Turns all LEDs on.
 *
 * This function sets all bits of the LED port to 1, effectively turning on all LEDs connected to the port.
 */
void leds_turn_all_on(void)
{
    *leds_puerto = 0xFFFF;
}

/**
 * @brief Turns off all LEDs.
 *
 * This function sets the value of the LED port to 0, effectively turning off all the LEDs connected to the port.
 */
void leds_turn_all_off(void)
{
    *leds_puerto = 0;
}
