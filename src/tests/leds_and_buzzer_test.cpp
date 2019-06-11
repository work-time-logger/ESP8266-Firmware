#include <debug.h>
#include <globals/hal.h>
#include <Ticker.h>
#include "tests.h"

Ticker led_and_buzzer_test_buzzer_scheduler; // NOLINT(cert-err58-cpp)
Ticker led_and_buzzer_test_success_led_scheduler; // NOLINT(cert-err58-cpp)
Ticker led_and_buzzer_test_error_led_scheduler; // NOLINT(cert-err58-cpp)

bool led_and_buzzer_test() {
    led_and_buzzer_test_buzzer_scheduler.attach(8, []() {
        hal.buzzer.start(0.05);
    });

    led_and_buzzer_test_success_led_scheduler.attach(5, []() {
        hal.success_led.start(1);
    });

    led_and_buzzer_test_error_led_scheduler.attach(3, []() {
        hal.error_led.start(1);
    });

    return true;
}