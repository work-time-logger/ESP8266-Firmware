#include "void_logic.h"

#include "interfaces/hal/hal_interface.h"


void void_logic_init(const hal_interface * device);
void void_logic_event(const hal_interface * device);

static const struct main_logic_interface void_logic = {
    void_logic_init,
    void_logic_event
};

const struct main_logic_interface *void_logic_get() {
    return &void_logic;
}

void void_logic_init(const hal_interface * device){

}

void void_logic_event(const hal_interface * device){

}