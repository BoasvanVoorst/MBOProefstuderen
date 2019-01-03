#include <msp430.h> 
#include <stdbool.h>
#include <stdint.h>

/**
 * main.c
 *
 * Inputs:
 * p1.3 = Compare
 *
 * p2.0 = A0
 * p2.1 = A1
 * p2.2 = A2
 *
 * p2.3 = B0
 * p2.4 = B1
 * p2.5 = B2
 *
 * Outputs:
 * p1.6 = Led
 * p1.7 = Buzzer
 *
 * this code is written by Boas van Voorst,
 * this code is only written to be used at the Hogeschool Rotterdam
 * and is for learning purpose only
 *
 * v1 is written on 12/28/2018
 *
 */

#define Equal 1
#define Less 2
#define Greater 3

int compare(void);
void Led(int);
void Buzzer(int);

int A = 0;
int B = 0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR = 1<<7 | 1<<6 | 1<<0;// set the pins as outputs
    P1SEL |= 1<<7; // select output pin for pwm
    P1OUT = 0; // whole port 1 turns off
    P2DIR = ~( 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0 ); // set the pins as inputs
    P2OUT = 0; // whole port 2 turns off

     __delay_cycles(1100); // delay 1 ms @ 1.1 MHz

    // Student code ------------------------------------------------------------------------------------

    // End Student code --------------------------------------------------------------------------------

    return 0;
}

/*
 * this function compares the input signals
 * this function must be written bij de student
 */
int compare(void){

    A = P2IN & 0b00000111; // change to correct value
    B = (P2IN >> 3) & 0b00000111; // change to correct value

    // Student code ------------------------------------------------------------------------------------

    // End student code --------------------------------------------------------------------------------

    return 0; // return value if function fails
}

/*
 * this function controls the state form the led.
 * this function must be written by the student.
 */
void Led(int state){
    // Student code ------------------------------------------------------------------------------------

    // End Student code --------------------------------------------------------------------------------
}

/*
 * this function controls the buzzer and his emiting frequentie
 */
void Buzzer(int PeriodTime){

    TA0CCR0 = PeriodTime; //Set the period in the Timer A0 Capture/Compare 0 register to x us.
    TA0CCTL1 = OUTMOD_7;
    TA0CCR1 = (PeriodTime/2); //The period in microseconds that the power is ON. It's half the time, which translates to a 50% duty cycle.
    TA0CTL = TASSEL_2 + MC_1; //TASSEL_2 selects SMCLK as the clock source, and MC_1 tells it to count up to the value in TA0CCR0.

    //start timer
    int i = 0;
    for(i = 0;i<1000;i++){
        __delay_cycles(1100); // delay 1 ms @ 1.1 MHz
    }
    // end timer

    TA0CTL = TASSEL_2 + MC_0; // stops counting up the timer // stops pwm
}
