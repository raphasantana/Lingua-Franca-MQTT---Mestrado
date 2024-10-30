#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/HelloWorld.h"
#include "_helloworld_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_helloworld_main_main_self_t* new__helloworld_main() {
    _helloworld_main_main_self_t* self = (_helloworld_main_main_self_t*)lf_new_reactor(sizeof(_helloworld_main_main_self_t));

    return self;
}
