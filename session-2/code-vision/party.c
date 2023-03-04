#include <mega32.h>
#include <delay.h>
#include <io.h>
#include <math.h>

void main(void)
{
    int i, a, b, flag = 0;
    DDRA = DDRB = 0xFF;
    while (1) {
        flag = !flag;
        for(i = 0; i < 8; i++) {
            if(flag) {
                a = pow(2, i);
                b = pow(2, 7 - i);
            }
            else {
                a = pow(2, 7 - i);
                b = pow(2, i);
            }
            PORTA = a;
            PORTB = b;
            delay_ms(200);
            PORTA = PORTB = 0x00;
        }
    }
}
