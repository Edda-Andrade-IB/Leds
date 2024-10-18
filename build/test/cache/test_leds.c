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

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT16);

}

void test_encender_un_led(void)

{

    static const int LED = 1;

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((LED)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX16);

}

void test_apagar_un_led_previamente_encendido(void)

{

    static const int LED = 1;

    leds_turn_on(LED);

    leds_turn_off(LED);

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (LED - 1))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(84));

    UnityAssertBits((UNITY_INT)((~(1 << (LED - 1)))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(85));

}















void test_verificar_estado_de_led_encendido(void)

{

    static const int LED = 3;

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((leds_state(LED))), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);

}

void test_encender_todos_los_leds_apagados(void)

{

    leds_turn_all_on();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0XFFFF)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_HEX16);

}

void test_apagar_todos_los_leds_encendidos(void)

{

    leds_turn_all_off();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_HEX16);

}

void test_encender_multiples_leds(void)

{

    static const int LED7 = 7;

    static const int LED13 = 13;

    static const int LED15 = 15;

    leds_turn_on(LED7);

    leds_turn_on(LED13);

    leds_turn_on(LED15);

    uint16_t expected_state = (1 << (LED7 - 1)) | (1 << (LED13 - 1)) | (1 << (LED15 - 1));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((expected_state)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_HEX16);

}

void test_apagar_multiples_leds(void)

{

    static const int LED1 = 1;

    static const int LED5 = 5;

    static const int LED12 = 12;

    leds_turn_all_off();

    leds_turn_on(LED1);

    leds_turn_on(LED5);

    leds_turn_on(LED12);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0811)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_HEX16);

    leds_turn_off(LED1);

    leds_turn_off(LED5);

    leds_turn_off(LED12);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_HEX16);

}

void test_verificar_valores_limites(void)

{

    static const int LED1 = 16;

    static const int LED2 = 1;

    leds_turn_on(LED1);

    leds_turn_on(LED2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(191), UNITY_DISPLAY_STYLE_HEX16);

}

void test_encender_leds_fuera_de_limites(void)

{

    static const int LED1 = 17, LED2 = -4, LED3 = 0;

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_on(LED1))), (

   ((void *)0)

   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_on(LED2))), (

   ((void *)0)

   ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_on(LED3))), (

   ((void *)0)

   ), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_INT);

}

void test_apagar_leds_fuera_de_limites(void)

{

    static const int LED1 = 33, LED2 = -12, LED3 = 0;

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_off(LED1))), (

   ((void *)0)

   ), (UNITY_UINT)(231), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_off(LED2))), (

   ((void *)0)

   ), (UNITY_UINT)(232), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_turn_off(LED3))), (

   ((void *)0)

   ), (UNITY_UINT)(233), UNITY_DISPLAY_STYLE_INT);

}

void test_verificar_estado_de_led_fuera_de_limites(void)

{

    static const int LED1 = 33, LED2 = -12, LED3 = 0;

    ;

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_state(LED1))), (

   ((void *)0)

   ), (UNITY_UINT)(256), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_state(LED2))), (

   ((void *)0)

   ), (UNITY_UINT)(257), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((leds_state(LED3))), (

   ((void *)0)

   ), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_INT);

}
