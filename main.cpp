/*
    Project : FlipFlop.cpp
    Micro   : Atmega32
    Crystal : 16MHz
    By      : Wayan Dadang
 */

#include <avr/io.h> //Macro Input Output AVR
#include <util/delay.h> //Macro Delay (Waktu Tunda)
#include "flipflop.h" // Macro header untuk class flipflop

int main(void)
{

    // Insert code
    // Insert code
    PinOut<PB,0> LED_KUNING; //Set Port B0 sebagai output LED Kuning
    PinOut<PB,1> LED_HIJAU;  //Set Port B1 sebagai output LED Hijau

    while(1){
        LED_KUNING.On(); //Set LED Kuning ON/Nyala/1
        LED_HIJAU.Off(); //Set LED Hijau OFF/Mati/0
        _delay_ms(500);  //Delay selama 0,5 derik

        LED_KUNING.Off(); //Set LED Kuning OFF/Mati/0
        LED_HIJAU.On();   //Set LED Hujau ON/Nyala/1
        _delay_ms(500);   //Delay selama 0,5 derik
    };

    return 0;
}
