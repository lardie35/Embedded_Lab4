#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= BIT6; //P1.6 OUTPUT

    //PWM GENERATOR
    TB0CCR0 = 8192;
    TB0CCTL1 = OUTMOD_7;
    TB0CCR1 = 1638.4;
    TB0CTL = TBSSEL_1 + MC_1 + TBCLR;
    TB0CCTL0 |= CCIE;
    TB0CCTL1 |= CCIE;
    TB0CCTL0 &=~CCIFG;
    TB0CCTL1 &=~CCIFG;
    _enable_interrupts();
}

#pragma vector = TIMER0_B0_VECTOR //define the interrupt service

__interrupt void ISR_TB0_CCR0 (void) {   //INTERRUPT SERVICE ROUTINE
    P1OUT |=BIT6;
    TB0CCTL0 &=~CCIFG;
}

#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_CCR1 (void) {
    P1OUT &=~BIT6;
    TB0CCTL1 &= ~CCIFG;
}
