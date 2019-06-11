#include <debug.h>
#include <globals/hal.h>
#include "tests.h"


bool reset_wifi_config() {
    hal.config.force();

    return true;
}