/* 

Blink LED by AVR c 

Developed by: Walid Amriou
Last update: November 2020

*/

#include <avr/io.h> // Defines pins, ports, etc 
#include <util/delay.h> // Functions to waste time

int main(void) {
    // We use the register DDRB to direct the port "B" pins, and DDRB is the Data Direction 
    // register for port “B”. This means that if you set this register to 0xFF (by running 
    // DDRB |= 0xFF ), all ports or pins in the “B” I/O port act as outputs. If you set DDRB 
    // to 0x00 (it’s initialized to 0x00 by default), then ports or pins in the “B” I/O port 
    // act as inputs. on general: DDRx data-direction registers (port x).
    // Note that the default state with of all the pins is "input mode".
    // For our example we set the pins PB0 and PB1 as output so our code is 0b00000011
    // we can set by DDRB |= 0b00000011;   or we can:
    //DDRB |= (1<<0); // for PB0, and it means DDRB = DDRB | 0b00000001 
    DDRC |= (1<<7); // for PB1, and it means DDRB = DDRB | 0b00000010
    // we use bitwise OR operation when we need to turn on or off a particular LED 
    // without disturbing any of the others.
    
    while (1) {
        // Turn on first & seconde LED bits/pins in PORTB
        // PORTx with port x is data registers
        // You can use this line: PORTB = 0b00000011;
        // Or use OR bitwise (the best)
        //PORTB |=(1<<0); // on PB0 (Digital pin 8 in Arduino Uno)
        PORTC |=(1<<7); // on PB1 (Digital pin 9 in Arduino Uno)
        _delay_ms(1000);  // wait 
        PORTC &=~(1<<7); // on PB1 (Digital pin 9 in Arduino Uno)
        _delay_ms(1000); // wait 
    } 
    
    return (0); // This line is never reached 
}
