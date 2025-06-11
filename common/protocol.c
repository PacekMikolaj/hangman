#include "protocol.h"
#include <string.h>
#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <arpa/inet.h>
#endif


int encode_tlv(const tlv_t* msg, uint8_t* buffer, size_t bufsize) {
    if (bufsize < 3 + msg->length) return -1;

    buffer[0] = msg->type;
    uint16_t len_net = htons(msg->length);
    memcpy(&buffer[1], &len_net, 2);
    memcpy(&buffer[3], msg->value, msg->length);

    return 3 + msg->length;
}

int decode_tlv(const uint8_t* buffer, size_t bufsize, tlv_t* msg) {
    if (bufsize < 3) return -1;

    msg->type = buffer[0];
    uint16_t len_net;
    memcpy(&len_net, &buffer[1], 2);
    msg->length = ntohs(len_net);

    if (msg->length > MAX_TLV_VALUE_SIZE || bufsize < 3 + msg->length) return -1;

    memcpy(msg->value, &buffer[3], msg->length);
    return 0;
}
