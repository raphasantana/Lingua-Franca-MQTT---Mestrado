#ifndef _MESSAGEGENERATOR_H
#define _MESSAGEGENERATOR_H
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
} _messagegenerator_message_t;
typedef struct {
    struct self_base_t base;
    #line 183 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    string root;
    #line 184 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    interval_t period;
#line 37 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_messagegenerator.h"
    #line 187 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    int count;
#line 40 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_messagegenerator.h"
    _messagegenerator_message_t _lf_message;
    int _lf_message_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
} _messagegenerator_self_t;
_messagegenerator_self_t* new__messagegenerator();
#endif // _MESSAGEGENERATOR_H
