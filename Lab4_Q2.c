#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= BIT6; //P1.6 OUTPUT
    P1SEL1 |= BIT6; //P1.6 OPTIONS SELECT
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 16384-1; //PWM PERIOD
    TB0CCTL1 = OUTMOD_7; //CCR1 RESET/SET
    TB0CCR1 = 1638.3; //CCR1 PWM DUTY CYCLE
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR; //ACLK, UP MODE, CLEAR TBR

    while(1)
    {
        P1OUT ^=BIT6; //FOR DEBUGGER
    }
}
