#ifndef TESTS_H
#define TESTS_H

typedef bool (*test_run)(void);

bool web_api_ping_test();
bool web_api_query_test();
bool web_api_full_cycle_test();
bool card_reading_test();
bool config_reading_test();
bool led_and_buzzer_test();
bool wifi_quality_test();
bool reset_wifi_config();

#endif //TESTS_H
