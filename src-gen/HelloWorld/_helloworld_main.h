#ifndef _HELLOWORLD_MAIN_H
#define _HELLOWORLD_MAIN_H
#include "include/core/reactor.h"
#include "_messagegenerator.h"
#include "_printmessage.h"
#include "_mqttsubscriber.h"
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
    struct self_base_t base;
#line 22 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_helloworld_main.h"
#line 23 "/home/linguafranca/lf-workspace/teste1/src-gen/HelloWorld/_helloworld_main.h"
} _helloworld_main_main_self_t;
_helloworld_main_main_self_t* new__helloworld_main();
#endif // _HELLOWORLD_MAIN_H
