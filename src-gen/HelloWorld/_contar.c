#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/Contar.h"
#include "_contar.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _contarreaction_function_0(void* instance_args) {
    _contar_self_t* self = (_contar_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _contar_out_t* out = &self->_lf_out;
    #line 18 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    lf_set(out, self->count);
    self->count += self->somar;
#line 15 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_contar.c"
}
#include "include/api/reaction_macros_undef.h"
_contar_self_t* new__contar() {
    _contar_self_t* self = (_contar_self_t*)lf_new_reactor(sizeof(_contar_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _contarreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
