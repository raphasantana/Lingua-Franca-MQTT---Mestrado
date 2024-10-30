#ifndef _mqttpublisher2_H
#define _mqttpublisher2_H
#ifndef _MQTTPUBLISHER2_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_2060213567_H
#define TOP_LEVEL_PREAMBLE_2060213567_H
/*Correspondence: Range: [(7, 2), (10, 23)) -> Range: [(0, 0), (3, 23)) (verbatim=true; src=/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf)*/#include "platform.h" // Defines lf_critical_section_enter(), etc.
#include <string.h>   // Defines memcpy

#include "MQTTClient.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct mqttpublisher2_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    string topic;
    string address;
    MQTTClient client;
    char* clientID;
    MQTTClient_message mqtt_msg;
    int end[0]; // placeholder; MSVC does not compile empty structs
} mqttpublisher2_self_t;
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
} mqttpublisher2_in_t;
#endif
#endif
