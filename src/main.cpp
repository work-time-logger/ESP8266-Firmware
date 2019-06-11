#include <Arduino.h>
#include <Wire.h>

#include <debug.h>

#include <interfaces/hal/hal_interface.h>
#include <interfaces/app_logic/main_logic_interface.h>

#if !defined(HARDWARE_CORE_VERSION) && !defined(HARDWARE_COMPACT_VERSION) && !defined(HARDWARE_FULL_VERSION)
    #error "No valid hardware version provided"
#endif

#ifdef HARDWARE_CORE_VERSION
    #ifdef HW_LOADED
        #error "Multiple hardawre versions provided!"
    #endif
    #define HW_LOADED

    #include <hardware/core_hal.h>
    #include <app_logic/void_logic.h>
#endif

#ifdef HARDWARE_COMPACT_VERSION
    #ifdef HW_LOADED
        #error "Multiple hardawre versions provided!"
    #endif
    #define HW_LOADED

    #include <hardware/compact_hal.h>
    #include <app_logic/compact_logic.h>
#endif

#ifdef HARDWARE_FULL_VERSION
    #ifdef HW_LOADED
        #error "Multiple hardawre versions provided!"
    #endif
    #define HW_LOADED

    #include <hardware/full_hal.h>
    #include <app_logic/full_logic.h>
#endif

#include <globals/hal.h>

#include <tests/tests.h>

main_logic_interface logic;

void setup(void)
{
    Serial.begin(9600);

    #ifdef HARDWARE_CORE_VERSION
        hal = *core_hal_get();
        logic = *void_logic_get();
    #endif

    #ifdef HARDWARE_COMPACT_VERSION
        hal = *compact_hal_get();
        logic = *compact_logic_get();
    #endif

    #ifdef HARDWARE_FULL_VERSION
        hal = *full_hal_get();
        logic = *full_logic_get();
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