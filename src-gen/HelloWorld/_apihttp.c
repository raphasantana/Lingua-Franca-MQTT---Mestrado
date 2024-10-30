#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/Apihttp.h"
#include "_apihttp.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _apihttpreaction_function_0(void* instance_args) {
    _apihttp_self_t* self = (_apihttp_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 14 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient client;
    
    MQTTClient_create(&self->client, self->address, self->clientID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
#line 16 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_apihttp.c"
}
#include "include/api/reaction_macros_undef.h"
_apihttp_self_t* new__apihttp() {
    _apihttp_self_t* self = (_apihttp_self_t*)lf_new_reactor(sizeof(_apihttp_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _apihttpreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}
