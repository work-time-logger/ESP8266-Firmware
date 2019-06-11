#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

bool web_api_query_test() {
    const char *card = "00-00-00-00";

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

    return query.valid;
}