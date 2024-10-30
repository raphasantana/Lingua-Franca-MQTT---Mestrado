#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/MessageGenerator.h"
#include "_messagegenerator.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _messagegeneratorreaction_function_0(void* instance_args) {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _messagegenerator_message_t* message = &self->_lf_message;
    #line 191 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    size_t length = snprintf(NULL,0,"%s %d", self->root,self->count)+1;
    
    char* buffer = (char*)malloc(length);
    
    snprintf(buffer,length,"%s %d", self->root,self->count++);
    
    lf_set_array(message,buffer,length);
    
    tag_t tag = lf_tag();
    
    lf_print("Gerador de Mensagem:"PRINTF_TAG " mensagem publicada: %s", tag.time - lf_time_start(),tag.microstep,message->value);
#line 24 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_messagegenerator.c"
}
#include "include/api/reaction_macros_undef.h"
_messagegenerator_self_t* new__messagegenerator() {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)lf_new_reactor(sizeof(_messagegenerator_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _messagegeneratorreaction_function_0;
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
