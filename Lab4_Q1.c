#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDT_ADLY_250;  // interval timer
    P6OUT &= ~BIT6; //green LED
    P6DIR |= BIT6; //green LED
    PM5CTL0 &= ~LOCKLPM5; //Low power mode stopped
    SFRIE1 |= WDTIE;
    _enable_interrupts();
    while (1);
}
#pragma vector=WDT_VECTOR
__interrupt void wdtled(void)
{
    P6OUT^=BIT6; //green LED activated after interrupt
}
