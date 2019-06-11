#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

void card_reading_test_callback(char read_card[])
{
    DEBUG_TEST("New Card Read: %s\n", read_card);
}

bool card_reading_test() {
    hal.rfid.set_callback(card_reading_test_callback);
    return true;
}