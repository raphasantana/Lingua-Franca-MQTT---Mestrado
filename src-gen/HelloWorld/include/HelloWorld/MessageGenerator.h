#ifndef _messagegenerator_H
#define _messagegenerator_H
#ifndef _MESSAGEGENERATOR_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1971335911_H
#define TOP_LEVEL_PREAMBLE_1971335911_H
/*Correspondence: Range: [(8, 2), (16, 16)) -> Range: [(0, 0), (8, 16)) (verbatim=true; src=/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf)*/#include "platform.h" // Defines lf_critical_section_enter(), etc.
#include <string.h>   // Defines memcpy

#include "MQTTClient.h"//importando a biblioteca que sera utilizada.

  typedef struct MQTTSub_info{
      void* logical_action;

  }MQTTSub_info;
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct messagegenerator_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    string root;
    interval_t period;
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} messagegenerator_self_t;
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
} messagegenerator_message_t;
#endif
#endif
