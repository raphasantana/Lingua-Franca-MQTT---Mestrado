#ifndef _MQTTSUBSCRIBER_H
#define _MQTTSUBSCRIBER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1971335911_H
#define TOP_LEVEL_PREAMBLE_1971335911_H
#include "platform.h" // Defines lf_critical_section_enter(), etc.
#include <string.h>   // Defines memcpy

#include "MQTTClient.h"//importando a biblioteca que sera utilizada.

  typedef struct MQTTSub_info{
      void* logical_action;

  }MQTTSub_info;
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
} _mqttsubscriber_message_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    char* value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _mqttsubscriber_act_t;
typedef struct {
    struct self_base_t base;
    #line 90 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    string topic;
    #line 91 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    string address;
#line 53 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.h"
    #line 122 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient client;
    #line 123 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    char* clientID;
    #line 124 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTSub_info info;
#line 60 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_mqttsubscriber.h"
    _mqttsubscriber_act_t _lf_act;
    _mqttsubscriber_message_t _lf_message;
    int _lf_message_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
    trigger_t _lf__act;
    reaction_t* _lf__act_reactions[1];
} _mqttsubscriber_self_t;
_mqttsubscriber_self_t* new__mqttsubscriber();
#endif // _MQTTSUBSCRIBER_H
