#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

bool web_api_ping_test() {
    auto ping = hal.backend.ping();

    DEBUG_TEST("ping.valid = %s\n", ping.valid ? "true" : "false");
    DEBUG_TEST("ping.uuid = %s\n", ping.uuid);
    DEBUG_TEST("ping.name = %s\n", ping.name);
    DEBUG_TEST("ping.is_active = %s\n", ping.is_active ? "true" : "false");

    return ping.valid;
}