#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

bool config_reading_test() {
    DEBUG_TEST("hal.device->name = %s\n", hal.device->name);
    DEBUG_TEST("hal.device->wifi_name = %s\n", hal.device->wifi_name);
    DEBUG_TEST("hal.device->wifi_password = %s\n", hal.device->wifi_password);
    DEBUG_TEST("hal.device->hmi = %s\n", hal.device->hmi ? "true" : "false");
    DEBUG_TEST("hal.config.get_server() = %s\n", hal.config.get_server());
    DEBUG_TEST("hal.config.get_token() = %s\n", hal.config.get_token());
    DEBUG_TEST("hal.config.get_ota_password() = %s\n", hal.config.get_ota_password());

    return true;
}