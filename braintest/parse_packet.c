#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_MESSAGE_LENGTH  65536

void display_message();
void update_motor();
void parseDisplayMessage(uint8_t *packet);
void parseMotorMessage(uint8_t *packet);
void parsePacket(uint8_t *packet);

int main(){

    uint8_t packet[] = {0x1, 0x34, 0x05, 0x0, 0x48, 0x65, 0x6c, 0x6c, 0x6f};

    parsePacket(packet);
}


void parsePacket(uint8_t *packet){

    if(*packet == 0x1 && *(packet+1) == 0x34)
        parseDisplayMessage(packet);
    else if (*packet == 0x2 && *(packet+1) == 0x80)
        parseMotorMessage(packet);
}


void parseDisplayMessage(uint8_t *packet){

    char str[MAX_MESSAGE_LENGTH];
    int length = *(packet+2) | (*(packet+3) << 8);

    for(uint8_t i=0; i<length; i++){
        str[i] = *(packet+(length-1-i));
    }
    
    printf("%s", str);
}


void parseMotorMessage(uint8_t *packet){

}