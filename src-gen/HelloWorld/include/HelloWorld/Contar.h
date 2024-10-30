#ifndef _contar_H
#define _contar_H
#ifndef _CONTAR_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_2049560816_H
#define TOP_LEVEL_PREAMBLE_2049560816_H
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct contar_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int somar;
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} contar_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} contar_out_t;
#endif
#endif