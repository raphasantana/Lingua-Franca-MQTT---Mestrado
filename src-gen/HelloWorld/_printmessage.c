#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/PrintMessage.h"
#include "_printmessage.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _printmessagereaction_function_0(void* instance_args) {
    _printmessage_self_t* self = (_printmessage_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _printmessage_message_t* message = self->_lf_message;
    if (message->is_present) {
        message->length = message->token->length;
        message->value = (char*)message->token->value;
    } else {
        message->length = 0;
    }
    int message_width = self->_lf_message_width; SUPPRESS_UNUSED_WARNING(message_width);
    #line 209 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    tag_t tag = lf_tag();
    lf_print("Mostrador de Mensagem:"PRINTF_TAG " subscriber recebe: %s", tag.time - lf_time_start(),tag.microstep,message->value);
#line 22 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_printmessage.c"
}
#include "include/api/reaction_macros_undef.h"
_printmessage_self_t* new__printmessage() {
    _printmessage_self_t* self = (_printmessage_self_t*)lf_new_reactor(sizeof(_printmessage_self_t));
    // Set input by default to an always absent default input.
    self->_lf_message = &self->_lf_default__message;
    // Set the default source reactor pointer
    self->_lf_default__message._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _printmessagereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__message.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__message.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__message_reactions[0] = &self->_lf__reaction_0;
    self->_lf__message.reactions = &self->_lf__message_reactions[0];
    self->_lf__message.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__message.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__message.tmplt.type.element_size = sizeof(char);
    return self;
}
