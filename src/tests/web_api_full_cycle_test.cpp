#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

bool web_api_full_cycle_test() {
    const char *card = "00-00-00-00";

    DEBUG_TEST("start = hal.backend.start('%s')\n", card);
    auto start = hal.backend.start(card);
    DEBUG_TEST("start.valid = %s\n", start.valid ? "true" : "false");
    DEBUG_TEST("start.start = %s\n\n", start.start);


    DEBUG_TEST("query = hal.backend.query('%s')\n", card);
    auto query = hal.backend.query(card);
    DEBUG_TEST("query.valid = %s\n", query.valid ? "true" : "false");
    DEBUG_TEST("query.employee = %s\n", query.employee);
    DEBUG_TEST("query.first_name = %s\n", query.first_name);
    DEBUG_TEST("query.last_name = %s\n", query.last_name);
    DEBUG_TEST("query.has_invalid_entries = %s\n", query.has_invalid_entries ? "true" : "false");
    DEBUG_TEST("query.worked_period = %d\n", query.worked_period);
    DEBUG_TEST("query.worked_today = %d\n", query.worked_today);
    DEBUG_TEST("query.open_entry = %s\n", query.open_entry);
    DEBUG_TEST("query.open_entry_working = %d\n\n", query.open_entry_working);

    
    DEBUG_TEST("delay: 60");
    delay(10000);
    DEBUG_TEST(", 50");
    delay(10000);
    DEBUG_TEST(", 40");
    delay(10000);
    DEBUG_TEST(", 30");
    delay(10000);
    DEBUG_TEST(", 20");
    delay(10000);
    DEBUG_TEST(", 10");
    delay(10000);
    DEBUG_TEST(", 0!\n\n");


    DEBUG_TEST("query = hal.backend.query('%s')\n", card);
    query = hal.backend.query(card);
    DEBUG_TEST("query.valid = %s\n", query.valid ? "true" : "false");
    DEBUG_TEST("query.employee = %s\n", query.employee);
    DEBUG_TEST("query.first_name = %s\n", query.first_name);
    DEBUG_TEST("query.last_name = %s\n", query.last_name);
    DEBUG_TEST("query.has_invalid_entries = %s\n", query.has_invalid_entries ? "true" : "false");
    DEBUG_TEST("query.worked_period = %d\n", query.worked_period);
    DEBUG_TEST("query.worked_today = %d\n", query.worked_today);
    DEBUG_TEST("query.open_entry = %s\n", query.open_entry);
    DEBUG_TEST("query.open_entry_working = %d\n\n", query.open_entry_working);


    String open_entry = query.open_entry;
    if(open_entry =="NULL")
        return false;


    DEBUG_TEST("stop = hal.backend.end('%s', '%s')\n", card, query.open_entry);
    auto stop = hal.backend.end(card, query.open_entry);
    DEBUG_TEST("stop.valid = %s\n", stop.valid ? "true" : "false");
    DEBUG_TEST("stop.start = %s\n", stop.start);
    DEBUG_TEST("stop.end = %s\n", stop.end);
    DEBUG_TEST("stop.worked_minutes = %d\n\n", stop.worked_minutes);

    return stop.valid;
}