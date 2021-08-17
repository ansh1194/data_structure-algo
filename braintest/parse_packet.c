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
    int length = *(packet+2) | (*(packet+3) >> 8);
    // printf("%d", length);

    for(uint8_t i=0; i<length; i++){
        str[i] = *(packet+4 +i);
    }
    // printf("%s", str);
    display_message(str);
}


void parseMotorMessage(uint8_t *packet){

    uint32_t forward_back = 0;
    uint32_t left_right = 0;
    uint8_t temp = 0;

    int length = *(packet+2) | (*(packet+3) << 8); 

    for(uint8_t i=0; i<length; i++){
        
        temp = (*(packet+ 4 + i));
        printf("%d \n", temp);
        if(i>4){
            left_right |= temp;
            left_right = left_right << 8;
        }else{
            forward_back |= temp;
            forward_back = forward_back << 8;
        }

    }
    printf("%d \n", forward_back);
    printf("%d \n", left_right);
    // printf("%ld \n", temp);
    // printf("%ld, %ld", (temp&0xFFFF0000)>>32, temp&0xFFFF);
}

void display_message(char *str){

}