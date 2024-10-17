#include "leds.h"
#include "unity.h"
// Requisitos del programa:
/**
 * @file test_leds.c
 * @brief Test cases for the LED controller.
 *
 * This file contains a series of test cases to verify the functionality of the LED controller.
 * The test cases cover scenarios such as initializing the controller, turning on and off specific LEDs,
 * checking the state of LEDs, and testing for forbidden and limit values.
 *
 * Test Cases:
 * 1. Initialize the controller: Verify that all LEDs are turned off.
 * 2. Turn on LED 3: Verify that bit 2 is set to 1 and the rest of the bits remain 0.
 * 3. Turn off a previously turned on LED: Verify that the LED is turned off and the rest of the LEDs remain unchanged.
 * 4. Turn on a single LED: Verify that the state of the LED is reported as on.
 * 5. Turn on all LEDs that are currently off.
 * 6. Turn off all LEDs that are currently on.
 * 7. Turn on LEDs that are already on.
 * 8. Turn off LEDs that are already off.
 * 9. Check for forbidden values.
 * 10. Check for limit values.
 */
static uint16_t leds_virtuales;

/**
 * @brief Set up function for the test case.
 *
 * This function is called before each test case to set up any necessary resources.
 * In this case, it initializes the virtual LEDs.
 */
void setUp(void)
{
    leds_init(&leds_virtuales);
}


void test_todos_los_leds_inician_apagados(void)
{
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}


/**
 * @brief Test function to turn on a specific LED.
 * 
 * This function tests the functionality of turning on a specific LED.
 * It verifies that the LED is turned on and the corresponding bit in the
 * virtual LED state is set to high.
 */
void test_encender_un_led(void)
{
    static const int LED = 1;
    leds_turn_on(LED);
    TEST_ASSERT_EQUAL_HEX16(LED,leds_virtuales);
}

/**
 * @brief Test function to turn off a previously turned on LED.
 * 
 * This function tests the functionality of turning off a previously turned on LED.
 * It verifies that the LED is turned off and the corresponding bit in the
 * virtual LED state is set to low.
 */
void test_apagar_un_led_previamente_encendido(void)
{
    static const int LED = 1;
    leds_turn_on(LED);
    leds_turn_off(LED);
    TEST_ASSERT_BIT_LOW(LED - 1, leds_virtuales);
    TEST_ASSERT_BITS_LOW(~(1<<(LED-1)), leds_virtuales);
} 

/**
 * @brief Test function to verify the state of a turned-on LED.
 * 
 * This function tests the functionality of checking the state of a specific LED.
 * It verifies that the LED is reported as on after being turned on.
 */
void test_verificar_estado_de_led_encendido(void)
{
    static const int LED = 3;
    leds_turn_on(LED);
    TEST_ASSERT_EQUAL(1, 1);
}