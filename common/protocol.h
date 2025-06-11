#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>
#include <stdlib.h>

#define MAX_TLV_VALUE_SIZE 256

// Typy wiadomości
#define TLV_LOGIN        1
#define TLV_GUESS        2
#define TLV_RESULT       3
#define TLV_RANKING      4
#define TLV_DISCONNECT   5
#define TLV_SERVER_ANNOUNCE 6

// Struktura TLV
typedef struct {
    uint8_t type;
    uint16_t length;
    uint8_t value[MAX_TLV_VALUE_SIZE];
} tlv_t;

// Funkcje
int encode_tlv(const tlv_t* msg, uint8_t* buffer, size_t bufsize);
int decode_tlv(const uint8_t* buffer, size_t bufsize, tlv_t* msg);

#endif // PROTOCOL_H
