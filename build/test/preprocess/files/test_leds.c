#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"
static uint16_t leds_virtuales;















void setUp(void)

{

    leds_init(&leds_virtuales);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_UINT16);

}

void test_encender_un_led(void)

{

    static const int LED = 1;

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((LED)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

}

void test_apagar_un_led_previamente_encendido(void)

{

    static const int LED = 1;

    leds_turn_on(LED);

    leds_turn_off(LED);

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (LED - 1))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(72));

    UnityAssertBits((UNITY_INT)((~(1<<(LED-1)))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(73));

}















void test_verificar_estado_de_led_encendido(void)

{

    static const int LED = 3;

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((leds_state(LED))), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_todos_los_leds_apagados(void)

{

    leds_virtuales = 0xAA;

    leds_turn_all_on();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0XFFFF)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_HEX16);

}
