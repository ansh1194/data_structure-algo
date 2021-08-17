#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_MESSAGE_LENGTH  65536

void display_message(char *str);
void update_motor();
void parseDisplayMessage(uint8_t *packet);
void parseMotorMessage(uint8_t *packet);
void parsePacket(uint8_t *packet);

int main(){

    // uint8_t packet[] = {0x1, 0x34, 0x05, 0x0, 0x48, 0x65, 0x6c, 0x6c, 0x6f};

    uint8_t packet[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0xbf};

    parsePacket(packet);

    return 0;
}


void parsePacket(uint8_t *packet){

    if(*packet == 0x1 && *(packet+1) == 0x34){
        parseDisplayMessage(packet);
        // printf("display message");
    }
    else if (*packet == 0x2 && *(packet+1) == 0x80)
        parseMotorMessage(packet);
}


void parseDisplayMessage(uint8_t *packet){

    char str[MAX_MESSAGE_LENGTH];
    int length = *(packet+2) | (*(packet+3) << 8);
    // printf("%d", length);

    for(uint8_t i=0; i<length; i++){
        str[i] = *(packet+4 +i);
    }
    
    display_message(str);
}


void parseMotorMessage(uint8_t *packet){

    int forward_back;
    int left_right;
    uint64_t temp;

    int length = *(packet+2) | (*(packet+3) << 8); 

    for(uint8_t i=0; i<length; i++){
        temp |= (*(packet+3) << 2^(3*i));
    }
    printf("%ld \n", temp);
    printf("%ld, %ld", (temp&0xFFFF0000)>>32, temp&0xFFFF);
}

void display_message(char *str){

}