#include "full_hal.h"

#include "drivers/generic_config_manager.h"
#include "drivers/generic_ota_updater.h"
#include "drivers/void_rfid_reader.h"
#include "drivers/web_api_backend.h"
#include "drivers/void_buzzer.h"
#include "drivers/void_led.h"
#include "drivers/void_rtc.h"

static const struct device_capabilities core_capabilities = {
    "CORE WTL for CONFIG",
    "CORE WTL Configuration",
    "password",
    false
};

static const struct hal_interface core_hal = { // NOLINT(cert-err58-cpp)
    .device = &core_capabilities,
    .config = *generic_config_manager_get(),
    .ota = *generic_ota_updater_get(),
    .backend = *web_api_backend_get(),
    .buzzer = *void_buzzer_get(),
    .success_led = *void_led_get(),
    .error_led = *void_led_get(),
    .rfid = *void_rfid_reader_get(),
    .rtc = *void_rtc_get()
};

const struct hal_interface *core_hal_get() {
    return &core_hal;
}