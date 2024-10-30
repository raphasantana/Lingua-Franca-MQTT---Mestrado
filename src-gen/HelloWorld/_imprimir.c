#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/Imprimir.h"
#include "_imprimir.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _imprimirreaction_function_0(void* instance_args) {
    _imprimir_self_t* self = (_imprimir_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _imprimir_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    #line 8 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    // Using a thread-safe print function provided by the runtime.
    lf_print("Hello World! %d", in->value);
#line 16 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_imprimir.c"
}
#include "include/api/reaction_macros_undef.h"
_imprimir_self_t* new__imprimir() {
    _imprimir_self_t* self = (_imprimir_self_t*)lf_new_reactor(sizeof(_imprimir_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _imprimirreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_reactions[0] = &self->_lf__reaction_0;
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    self->_lf__in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(int);
    return self;
}
