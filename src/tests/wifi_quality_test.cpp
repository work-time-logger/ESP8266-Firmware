#include <debug.h>
#include <globals/hal.h>
#include "tests.h"

#include <ESP8266WiFi.h>

bool wifi_quality_test() {
    DEBUG_TEST("SSID: %s\n", WiFi.SSID().c_str());
    DEBUG_TEST("BSSID: %s\n", WiFi.BSSIDstr().c_str());
    DEBUG_TEST("RSSI: %d\n", WiFi.RSSI());
    DEBUG_TEST("gateway IP: %s\n", WiFi.gatewayIP().toString().c_str());
    DEBUG_TEST("subnet mask: %s\n", WiFi.subnetMask().toString().c_str());
    DEBUG_TEST("mac address: %s\n", WiFi.macAddress().c_str());
    DEBUG_TEST("IP address: %s\n", WiFi.localIP().toString().c_str());

    return true;
}