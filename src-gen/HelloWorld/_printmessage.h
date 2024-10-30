#ifndef _PRINTMESSAGE_H
#define _PRINTMESSAGE_H
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
} _printmessage_message_t;
typedef struct {
    struct self_base_t base;
#line 33 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_printmessage.h"
#line 34 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_printmessage.h"
    _printmessage_message_t* _lf_message;
    // width of -2 indicates that it is not a multiport.
    int _lf_message_width;
    // Default input (in case it does not get connected)
    _printmessage_message_t _lf_default__message;
    reaction_t _lf__reaction_0;
    trigger_t _lf__message;
    reaction_t* _lf__message_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _printmessage_self_t;
_printmessage_self_t* new__printmessage();
#endif // _PRINTMESSAGE_H
