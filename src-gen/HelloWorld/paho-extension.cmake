
# Taken from: https://github.com/eclipse/paho.mqtt.cpp/tree/master/cmake
# find the Paho MQTT C library

set(_PAHO_MQTT_C_LIB_NAME paho-mqtt3c)

find_library(PAHO_MQTT_C_LIBRARIES NAMES ${_PAHO_MQTT_C_LIB_NAME})
unset(_PAHO_MQTT_C_LIB_NAME)
find_path(PAHO_MQTT_C_INCLUDE_DIRS NAMES MQTTAsync.h)

add_library(PahoMqttC::PahoMqttC UNKNOWN IMPORTED)

set_target_properties(PahoMqttC::PahoMqttC PROPERTIES
    IMPORTED_LOCATION "${PAHO_MQTT_C_LIBRARIES}"
    INTERFACE_INCLUDE_DIRECTORIES "${PAHO_MQTT_C_INCLUDE_DIRS}"
    IMPORTED_LINK_INTERFACE_LANGUAGES "C")

include_directories(${PAHO_MQTT_C_INCLUDE_DIRS})
target_link_libraries(${LF_MAIN_TARGET} PRIVATE ${PAHO_MQTT_C_LIBRARIES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLF_PRINT_LOG_LEVEL=DEBUG")
