#ifndef _apihttp_H
#define _apihttp_H
#ifndef _APIHTTP_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_506088957_H
#define TOP_LEVEL_PREAMBLE_506088957_H
/*Correspondence: Range: [(3, 4), (3, 27)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/home/linguafranca/lf-workspace/teste1/src/HelloWorld.lf)*/#include "MQTTClient.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct apihttp_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    MQTTClient client;
    int end[0]; // placeholder; MSVC does not compile empty structs
} apihttp_self_t;
#endif
#endif
