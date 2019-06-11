#include <Arduino.h>
#include <Wire.h>

#include <debug.h>

#include <interfaces/hal/hal_interface.h>
#include <interfaces/app_logic/main_logic_interface.h>

#ifndef HARDWARE_VERSION
    #error "No valid HARDWARE_VERSION provided"
#elif HARDWARE_VERSION == compact
    #include <hardware/compact_hal.h>
    #include <app_logic/compact_logic.h>
#elif HARDWARE_VERSION == full
    #include <hardware/full_hal.h>
    #include <app_logic/full_logic.h>
#else
    #error "Unknown HARDWARE_VERSION provided"
#endif

#include <globals/hal.h>

#include <tests/tests.h>

main_logic_interface logic;

void setup(void)
{
    Serial.begin(9600);

    #ifndef HARDWARE_VERSION
        #error "No valid HARDWARE_VERSION provided"
    #elif HARDWARE_VERSION == compact
        hal = *compact_hal_get();
        logic = *compact_logic_get();
    #elif HARDWARE_VERSION == full
        hal = *full_hal_get();
        logic = *full_logic_get();
    #else
        #error "Unknown HARDWARE_VERSION provided"
    #endif

    hal_init(&hal);

    #ifdef RUN_TEST
        bool result = RUN_TEST();
        DEBUG_TEST("\n----------------------\n\nTest %s\n\n----------------------\n", result ? "Passed" : "Failed");
    #else
        logic.init(&hal);
    #endif
}

void loop(void)
{
    hal_event(&hal);

    #ifndef RUN_TEST
        logic.event(&hal);
    #endif
}