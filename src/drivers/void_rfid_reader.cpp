#include "void_rfid_reader.h"

void void_rfid_reader_init();
void void_rfid_reader_event();
void void_rfid_reader_set_callback(void (*callback)(char read_card[]));

static const struct rfid_reader_interface void_rfid_reader = {
    void_rfid_reader_init,
    void_rfid_reader_event,
    void_rfid_reader_set_callback
};

const struct rfid_reader_interface *void_rfid_reader_get() {
    return &void_rfid_reader;
}

void void_rfid_reader_init() {

}

void void_rfid_reader_event() {

}

void void_rfid_reader_set_callback(void (*callback)(char read_card[])) {

}