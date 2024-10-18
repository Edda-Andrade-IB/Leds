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
 * 7. Check for forbidden values. (Requirement 9)
 * 8. Check for limit values. (Requirement 10)
 * 9. Turn on multiple LEDs: Verify that multiple LEDs can be turned on simultaneously. (Requirement 4)
 * 10. Turn off multiple LEDs: Verify that multiple LEDs can be turned off simultaneously. (Requirement 4)
 */
static uint16_t leds_virtuales;
#define ERROR_CODE -1
#define SUCCESS_CODE 1

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

/**
 * @brief Test to verify that all LEDs are turned on when the function leds_turn_all_on() is called.
 *
 * This test ensures that the function leds_turn_all_on() correctly sets all bits in the
 * leds_virtuales variable to 1, indicating that all LEDs are turned on.
 *
 * @note The expected value of leds_virtuales after calling leds_turn_all_on() is 0xFFFF.
 */
void test_encender_todos_los_leds_apagados(void)
{
    leds_turn_all_on();
    TEST_ASSERT_EQUAL_HEX16(0XFFFF, leds_virtuales);
}

/**
 * @brief Test function to verify that all LEDs are turned off.
 *
 * This function calls the `leds_turn_all_off` function to turn off all LEDs
 * and then asserts that the `leds_virtuales` variable is equal to 0x00,
 * indicating that all LEDs are indeed turned off.
 */
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

/**
 * @brief Test function to verify the functionality of turning off multiple LEDs.
 *
 * This function tests the ability to turn off multiple LEDs after they have been turned on.
 * It turns on LEDs 1, 5, and 12, then turns them off, and finally asserts that the virtual
 * LEDs register is 0x00, indicating that all LEDs are off.
 *
 * @note This function uses the `leds_turn_on` and `leds_turn_off` functions to control the LEDs.
 *       It also uses the `TEST_ASSERT_EQUAL_HEX16` macro to verify the final state of the LEDs.
 */
void test_apagar_multiples_leds(void)
{
    static const int LED1 = 1;
    static const int LED5 = 5;
    static const int LED12 = 12;
    leds_turn_all_off();
    leds_turn_on(LED1);
    leds_turn_on(LED5);
    leds_turn_on(LED12);
    TEST_ASSERT_EQUAL_HEX16(0x0811, leds_virtuales);
    leds_turn_off(LED1);
    leds_turn_off(LED5);
    leds_turn_off(LED12);
    TEST_ASSERT_EQUAL_HEX16(0x00, leds_virtuales);
}

/**
 * @brief Test function to verify the boundary values for turning on LEDs.
 *
 * This function tests the behavior of the `leds_turn_on` function by turning on
 * two LEDs at the boundary values. It asserts that the virtual LEDs variable
 * (`leds_virtuales`) matches the expected value after turning on the LEDs.
 *
 * @note The boundary values tested are LED1 (16) and LED2 (1).
 */
void test_verificar_valores_limites(void)
{
    static const int LED1 = 16;
    static const int LED2 = 1;
    leds_turn_on(LED1);
    leds_turn_on(LED2);
    TEST_ASSERT_EQUAL_HEX16(0x8001, leds_virtuales);
}

/**
 * @brief Test function to verify the behavior of turning on LEDs that are out of valid range.
 *
 * This function tests the `leds_turn_on` function with LED indices that are outside the valid range.
 * It checks if the function correctly returns an error code when attempting to turn on LEDs with
 * indices that are either too high, negative, or zero.
 *
 * Test cases:
 * - LED index 17 (out of upper bound)
 * - LED index -4 (negative index)
 * - LED index 0 (invalid index)
 *
 * Expected behavior:
 * - The `leds_turn_on` function should return `ERROR_CODE` for each of the invalid LED indices.
 */
void test_encender_leds_fuera_de_limites(void)
{
    static const int LED1 = 17, LED2 = -4, LED3 = 0;
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_on(LED1));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_on(LED2));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_on(LED3));
}

/**
 * @brief Test function to verify that attempting to turn off LEDs outside the valid range returns an error.
 *
 * This function tests the `leds_turn_off` function with LED indices that are outside the valid range.
 * It uses the following invalid LED indices:
 * - LED1: 33 (above the valid range)
 * - LED2: -12 (below the valid range)
 * - LED3: 0 (assuming 0 is outside the valid range)
 *
 * The function asserts that the `leds_turn_off` function returns `ERROR_CODE` for each of these invalid indices.
 */
void test_apagar_leds_fuera_de_limites(void)
{
    static const int LED1 = 33, LED2 = -12, LED3 = 0;
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_off(LED1));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_off(LED2));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_turn_off(LED3));
}

/**
 * @brief Test function to verify the state of LEDs that are out of valid range.
 *
 * This function tests the `leds_state` function with LED indices that are outside
 * the valid range. It checks if the function correctly returns an error code for
 * these invalid indices.
 *
 * @details
 * The test cases include:
 * - LED index 33, which is above the valid range.
 * - LED index -12, which is below the valid range.
 * - LED index 0, which is typically considered out of range if the valid indices start from 1.
 *
 * The expected behavior is that the `leds_state` function returns `ERROR_CODE` for each of these
 * invalid indices.
 */
void test_verificar_estado_de_led_fuera_de_limites(void)
{
    static const int LED1 = 33, LED2 = -12, LED3 = 0;
    ;
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_state(LED1));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_state(LED2));
    TEST_ASSERT_EQUAL(ERROR_CODE, leds_state(LED3));
}