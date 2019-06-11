#include "void_buzzer.h"

void void_buzzer_init();
void void_buzzer_start(float seconds);
void void_buzzer_stop();

static const struct buzzer_interface void_buzzer = {
    void_buzzer_init,
    void_buzzer_start,
    void_buzzer_stop
};

const struct buzzer_interface *void_buzzer_get() {
    return &void_buzzer;
}

void void_buzzer_init() {

}

void void_buzzer_start(float seconds) {

}

void void_buzzer_stop() {

}