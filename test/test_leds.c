#include "leds.h"
#include "unity.h"

/**
 * @file test_leds.c
 * @brief Test cases for the LED controller.
 *
 * This file contains a series of test cases to verify the functionality of the LED controller.
 * The test cases cover scenarios such as initializing the controller, turning on and off specific LEDs,
 * checking the state of LEDs, and testing for forbidden and limit values.
 *
 * Requirements:
 * 1. With initialization, all LEDs are turned off.
 * 2. Turn on an individual LED.
 * 3. Turn off an individual LED.
 * 4. Turn on and off multiple LEDs.
 * 5. Turn on all LEDs at once.
 * 6. Turn off all LEDs at once.
 * 7. Check the state of an LED that is on.
 * 8. Check the state of an LED that is off.
 * 9. Check parameter limits.
 * 10. Check parameters outside the limits.
 *
 * * Test Cases:
 * 1. Initialize the controller: Verify that all LEDs are turned off. (Requirement 1)
 * 2. Turn on LED 3: Verify that bit 2 is set to 1 and the rest of the bits remain 0. (Requirement 2)
 * 3. Turn off a previously turned on LED: Verify that the LED is turned off and the rest of the LEDs remain unchanged. (Requirement 3)
 * 4. Turn on a single LED: Verify that the state of the LED is reported as on. (Requirement 7)
 * 5. Turn on all LEDs that are currently off. (Requirement 5)
 * 6. Turn off all LEDs that are currently on. (Requirement 6)
 * 7. Turn on LEDs that are already on. (Requirement 2)
 * 8. Turn off LEDs that are already off. (Requirement 3)
 * 9. Check for forbidden values. (Requirement 9)
 * 10. Check for limit values. (Requirement 10)
 * 11. Turn on multiple LEDs: Verify that multiple LEDs can be turned on simultaneously. (Requirement 4)
 * 12. Turn off multiple LEDs: Verify that multiple LEDs can be turned off simultaneously. (Requirement 4)
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
    TEST_ASSERT_EQUAL_HEX16(LED, leds_virtuales);
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
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
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
    TEST_ASSERT_EQUAL(1, leds_state(LED));
}

//* 5. Turn on all LEDs that are currently off.
void test_encender_todos_los_leds_apagados(void)
{
    leds_turn_all_on();
    TEST_ASSERT_EQUAL_HEX16(0XFFFF, leds_virtuales);
}

//* 6. Turn off all LEDs that are currently on.
void test_apagar_todos_los_leds_encendidos(void)
{
    leds_turn_all_off();
    TEST_ASSERT_EQUAL_HEX16(0x00, leds_virtuales);
}

 
/**
 * @brief Test function to verify the functionality of turning on multiple LEDs.
 *
 * This function tests the ability to turn on multiple LEDs simultaneously.
 * It turns on LEDs 7, 13, and 15, and then checks if the virtual LED state
 * matches the expected state.
 *
 * @note This function uses the `leds_turn_on` function to turn on the LEDs
 * and `TEST_ASSERT_EQUAL_HEX16` to assert the expected state.
 */
 void test_encender_multiples_leds(void)
{
    static const int LED7 = 7;
    static const int LED13 = 13;
    static const int LED15 = 15;
    leds_turn_on(LED7);
    leds_turn_on(LED13);
    leds_turn_on(LED15);
    uint16_t expected_state = (1 << (LED7 - 1)) | (1 << (LED13 - 1)) | (1 << (LED15 - 1));
    TEST_ASSERT_EQUAL_HEX16(expected_state, leds_virtuales);
}
 


