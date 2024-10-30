#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/MQTTSubscriber.h"
#include "_mqttsubscriber.h"
// *********** From the preamble, verbatim:
#line 96 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
int message_arrived(void *info, char* topic_name, int topic_length, MQTTClient_message *message){

    MQTTSub_info* my_info = (MQTTSub_info*)info;

    lf_print("\nMessagem Recebida no topico %s: Mesagem: %s",topic_name, (char*)message->payload);

    lf_schedule_copy(((MQTTSub_info*)info)->logical_action,
        0,
        (char*)message->payload,
        message->payloadlen
    );

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topic_name);

    return 1;
}//Essa função, representa a mensagem que será passada para o callback.

void sub_perda_conexao(void *info, char *cause){
    lf_print("Conexao perdida Subscriber por: %s",cause);
}//Essa função, representa a mensagem que será passada para o callback.
#line 29 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _mqttsubscriberreaction_function_0(void* instance_args) {
    _mqttsubscriber_self_t* self = (_mqttsubscriber_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _mqttsubscriber_act_t* act = &self->_lf_act;
    #line 128 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    int res;
    
    MQTTClient_connectOptions sub_connect_options = MQTTClient_connectOptions_initializer;
    
    res = MQTTClient_create(&self->client, self->address,self->clientID,MQTTCLIENT_PERSISTENCE_NONE, NULL);
    
    if(res != MQTTCLIENT_SUCCESS){
        lf_print("\n 1.Falha na criacao do subscriber com: %d.", res);
    }else{
        lf_print("\n 1.Criacao subcribe feita com sucesso - Create Sucess");
    }
    
    sub_connect_options.keepAliveInterval = 10;
    sub_connect_options.cleansession = 1;
    
    self->info.logical_action=act;
    
    res = MQTTClient_setCallbacks(self->client,&self->info,sub_perda_conexao,message_arrived,NULL);
    if(res != MQTTCLIENT_SUCCESS){
        lf_print("\n 2.Callback nao esta funcionando:  %d.", res);
    }else{
        lf_print("\n 2.Callback funcionando corretamente. Setcalback Sucess");
    }
    
    res = MQTTClient_connect(self->client,&sub_connect_options);
    if(res != MQTTCLIENT_SUCCESS){
        lf_print("\n 3.Falha na conexao o subscriber com: %d.", res);
    }else{
        lf_print("\n 3.Conexao subcribe feita com sucesso - Conexão Sucess");
    }
    
    res = MQTTClient_subscribe(self->client,self->topic, 2);
    if(res != MQTTCLIENT_SUCCESS){
        lf_print("\n 4.Subscriber nao funcionando:  %d.", res);
    }else{
        lf_print("\n 4.Subscriber funcionando corretamente. Subscribe sucess");
    }
#line 76 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _mqttsubscriberreaction_function_1(void* instance_args) {
    _mqttsubscriber_self_t* self = (_mqttsubscriber_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _mqttsubscriber_act_t* act = &self->_lf_act;
    // Set the fields of the action struct to match the current trigger.
    act->is_present = (bool)self->_lf__act.status;
    act->has_value = ((self->_lf__act.tmplt.token) != NULL && (self->_lf__act.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)act, (self->_lf__act.tmplt.token));
    if (act->has_value) {
        act->value = (char*)(self->_lf__act.tmplt.token)->value;
        act->length = (self->_lf__act.tmplt.token)->length;
    }
    lf_critical_section_exit(self->base.environment);
    _mqttsubscriber_message_t* message = &self->_lf_message;
    #line 170 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    lf_set_token(message,act->token);
    lf_print("\n Entrou aqui");
#line 98 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _mqttsubscriberreaction_function_2(void* instance_args) {
    _mqttsubscriber_self_t* self = (_mqttsubscriber_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 176 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient_disconnect(self->client, 10000);
    MQTTClient_destroy(&self->client);
    lf_print("\n Desconectando o Cliente Subscriber: %s.", self->clientID);
#line 109 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.c"
}
#include "include/api/reaction_macros_undef.h"
_mqttsubscriber_self_t* new__mqttsubscriber() {
    _mqttsubscriber_self_t* self = (_mqttsubscriber_self_t*)lf_new_reactor(sizeof(_mqttsubscriber_self_t));
    self->_lf_act._base.trigger = &self->_lf__act;
    self->_lf_act.parent = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _mqttsubscriberreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _mqttsubscriberreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _mqttsubscriberreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__shutdown.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__shutdown_reactions[0] = &self->_lf__reaction_2;
    self->_lf__shutdown.last_tag = NEVER_TAG;
    self->_lf__shutdown.reactions = &self->_lf__shutdown_reactions[0];
    self->_lf__shutdown.number_of_reactions = 1;
    self->_lf__shutdown.is_timer = false;
    self->_lf__act.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__act.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__act_reactions[0] = &self->_lf__reaction_1;
    self->_lf__act.reactions = &self->_lf__act_reactions[0];
    self->_lf__act.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__act.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__act.is_physical = false;
    
    self->_lf__act.tmplt.type.element_size = sizeof(char);
    self->_lf_act.type.element_size = sizeof(char);
    return self;
}
