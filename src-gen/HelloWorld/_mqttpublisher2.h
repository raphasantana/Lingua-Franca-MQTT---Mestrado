#ifndef _MQTTPUBLISHER2_H
#define _MQTTPUBLISHER2_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_2060213567_H
#define TOP_LEVEL_PREAMBLE_2060213567_H
#include "platform.h" // Defines lf_critical_section_enter(), etc.
#include <string.h>   // Defines memcpy

#include "MQTTClient.h"
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char* value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _mqttpublisher2_in_t;
typedef struct {
    struct self_base_t base;
    #line 16 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    string topic;
    #line 17 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    string address;
#line 32 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttpublisher2.h"
    #line 21 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient client;
    #line 22 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    char* clientID;
    #line 23 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient_message mqtt_msg;
#line 39 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttpublisher2.h"
    _mqttpublisher2_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _mqttpublisher2_in_t _lf_default__in;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _mqttpublisher2_self_t;
_mqttpublisher2_self_t* new__mqttpublisher2();
#endif // _MQTTPUBLISHER2_H
