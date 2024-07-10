/*
 * Project name:
     Button (Demonstration of using Button Library)
 * Copyright:
     (c) Mikroelektronika, 2010.
 * Revision History:
     20080110:
       - initial release;
 * Description:
     This program demonstrates usage on-board button as PORTB input.
     On every PB0 one-to-zero transition PORTC is inverted.
 * Test configuration:
     MCU:             ATmega128
                      http://www.atmel.com/dyn/resources/prod_documents/doc2467.pdf
     Dev.Board:       BIGAVR6 - ac:Buttons
                      http://www.mikroe.com/eng/products/view/322/bigavr6-development-system/
     Oscillator:      External Clock 08.0000 MHz
     Ext. Modules:    -
     SW:              mikroC PRO for AVR
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
 * NOTES:
     - Make sure you turn ON the PORTC LEDs (SW12.3)
     - Put button jumper (J12) into VCC position and pull-down PORTB
*/

bit oldstate;                       // Old state flag

void main() {

  DDB0_bit = 0;                     // Set PB0 pin as input
  DDRC  = 0xFF;                     // Configure PORTC as output
  PORTC = 0xAA;                     // Initial PORTC value
  
  oldstate = 0;                     // Oldstate initial value
  
  do {
    if (Button(&PINB, 0, 1, 1)) {   // Detect logical one
      oldstate = 1;                 // Update flag
    }
    if (oldstate && Button(&PINB, 0, 1, 0)) { // Detect one-to-zero transition
      PORTC = ~PORTC;               // Invert PORTC
      oldstate = 0;                 // Update flag
    }
  } while(1);                       // Endless loop
}