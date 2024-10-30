#ifndef _CONTAR_H
#define _CONTAR_H
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
} _contar_out_t;
typedef struct {
    struct self_base_t base;
    #line 13 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    int somar;
#line 26 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_contar.h"
    #line 14 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    int count;
#line 29 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_contar.h"
    _contar_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
} _contar_self_t;
_contar_self_t* new__contar();
#endif // _CONTAR_H
