#ifndef _APIHTTP_H
#define _APIHTTP_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_506088957_H
#define TOP_LEVEL_PREAMBLE_506088957_H
#include "MQTTClient.h"
#endif
typedef struct {
    struct self_base_t base;
#line 11 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_apihttp.h"
    #line 10 "/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf"
    MQTTClient client;
#line 14 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_apihttp.h"
    reaction_t _lf__reaction_0;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _apihttp_self_t;
_apihttp_self_t* new__apihttp();
#endif // _APIHTTP_H
