#include <mega32.h>
#include <delay.h>
#include <io.h>
#include <math.h>

void main(void)
{
    DDRA = DDRB = 0xFF;
    int i, a_index, b_index, flag = 0;
    char b[8] = {
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000
    };
    while (1) {
        flag = !flag;
        for(i = 0; i < 8; i++) {
            if(flag) {
                a_index = i;
                b_index = 7 - i;
            }
            else {
                a_index = 7 - i;
                b_index = i;
            }
            PORTA = b[a_index];
            PORTB = b[b_index];
            delay_ms(200);
            PORTA = PORTB = 0b00000000;
        }
    }
}
