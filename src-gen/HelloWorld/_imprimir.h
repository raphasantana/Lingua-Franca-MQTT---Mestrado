#ifndef _IMPRIMIR_H
#define _IMPRIMIR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_2049560816_H
#define TOP_LEVEL_PREAMBLE_2049560816_H
#endif
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
} _imprimir_in_t;
typedef struct {
    struct self_base_t base;
#line 24 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_imprimir.h"
#line 25 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_imprimir.h"
    _imprimir_in_t* _lf_in;
    // width of -2 indicates that it is not a multiport.
    int _lf_in_width;
    // Default input (in case it does not get connected)
    _imprimir_in_t _lf_default__in;
    reaction_t _lf__reaction_0;
    trigger_t _lf__in;
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _imprimir_self_t;
_imprimir_self_t* new__imprimir();
#endif // _IMPRIMIR_H
