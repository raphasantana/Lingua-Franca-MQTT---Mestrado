#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/HelloWorld/MQTTPublisher2.h"
#include "_mqttpublisher2.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _mqttpublisher2reaction_function_0(void* instance_args) {
    _mqttpublisher2_self_t* self = (_mqttpublisher2_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 28 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    // Poderia utilizar a funcao lf_critical_section_enter - Ela coloca essa secao como critica, nao permitindo multiplas threads.
    LF_PRINT_LOG("Testando");
    
    MQTTClient_connectOptions pub_connect_options = MQTTClient_connectOptions_initializer;
    
    MQTTClient_create(&self->client, self->address, self->clientID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    
    
    pub_connect_options.keepAliveInterval = 20;
    pub_connect_options.cleansession = 1;
    
    int rc;
    
    if ((rc = MQTTClient_connect(self->client, &pub_connect_options)) != MQTTCLIENT_SUCCESS) {
    lf_print_error_and_exit("MQTTPublisher: Failed to connect to MQTT broker.\n"
      "Perhaps one is not running? Return code: %d", rc);
    } else{
        LF_PRINT_LOG("MQTTPublisher: connected to broker.");
    }
#line 32 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttpublisher2.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _mqttpublisher2reaction_function_1(void* instance_args) {
    _mqttpublisher2_self_t* self = (_mqttpublisher2_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _mqttpublisher2_in_t* in = self->_lf_in;
    if (in->is_present) {
        in->length = in->token->length;
        in->value = (char*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    #line 52 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient_deliveryToken delivery=0;
    int length = in->length;
    char* message;
    
    message = (char*)malloc(sizeof(char)*length); //Alocacao Dinamica da memoria.
    memcpy(message,in->value,length);// Funcao para copiar a mensagem do 2 para o 1 argumento e com o tamanho igual ao 3.
    
    instant_t timestamp = lf_time_logical();
    printf("Tempo logico: %lld\n", timestamp);
    //encode_int64(timestamp, (unsigned char*)(message+length-sizeof(instant_t)));//Pega o timestamp e insere como uma dequencia de bits inserida na mensagem.
    
    self->mqtt_msg.payload = message;
    self->mqtt_msg.payloadlen = length;
    self->mqtt_msg.qos=2;
    self->mqtt_msg.retained=0;
    
    MQTTClient_publishMessage(self->client,self->topic,&self->mqtt_msg,&delivery);
    
    printf("Messagem Enviada");
#line 66 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttpublisher2.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _mqttpublisher2reaction_function_2(void* instance_args) {
    _mqttpublisher2_self_t* self = (_mqttpublisher2_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 76 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    lf_print("\n Desconectando o Cliente: %s.", self->clientID);
    MQTTClient_disconnect(self->client, 10000);
    MQTTClient_destroy(&self->client);
#line 77 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttpublisher2.c"
}
#include "include/api/reaction_macros_undef.h"
_mqttpublisher2_self_t* new__mqttpublisher2() {
    _mqttpublisher2_self_t* self = (_mqttpublisher2_self_t*)lf_new_reactor(sizeof(_mqttpublisher2_self_t));
    // Set input by default to an always absent default input.
    self->_lf_in = &self->_lf_default__in;
    // Set the default source reactor pointer
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _mqttpublisher2reaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _mqttpublisher2reaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _mqttpublisher2reaction_function_2;
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
    self->_lf__in.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__in_reactions[0] = &self->_lf__reaction_1;
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    self->_lf__in.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__in.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(char);
    return self;
}
