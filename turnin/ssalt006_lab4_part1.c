/*	Author: Skyler Saltos 
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description:
 *		PB0 and PB1 each connect to an LED, and PB0's LED is initially on. 
 *		Pressing a button connected to PA0 turns off PB0's LED and turns on PB1's LED, staying that way after button release. 
 *		 Pressing the button again turns off PB1's LED and turns on PB0's LED.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum L_States { L_Start, L_OneOn, L_WaitOne, L_WaitZero, L_ZeroOn }
L_State;



int main(void) {
    /* Insert DDR and PORT initializations */
	
	DDRA = 0x00; PORTA = 0xFF; // Port A as input
	DDRB = 0xFF; PORTB = 0x00; // Port B as output

	

    /* Insert your solution below */
    while (1) {

    	   unsigned char PinZero = 0x00;	    
	   PinZero = PINA & 0x01; // variable to hold the value of the last pin in A which represents the button toggle

	switch(L_State){ // transitions 

		case L_Start:
			L_State = L_ZeroOn;
			break;
	
		case L_ZeroOn: //initial state
			if( PinZero == 0x01 ){
				L_State = L_ZeroOn;
			}//remain in current state

			else if ( PinZero == 0x00 ){
				L_State = L_WaitZero;
			}//go to wait state 

			break;

		case L_WaitZero:
			if( PinZero == 0x00 ){
				L_State = L_WaitZero;
			}//remain in current state


			else if ( PinZero == 0x01 ){
				L_State = L_OneOn;

			}//transition to next light toggle 
			
			break;

		case L_OneOn:
			if( PinZero == 0x01){
				L_State = L_OneOn;
			}//remain in current state

			else if ( PinZero == 0x00 ){
				L_State = L_WaitOne;

			}//transition to wait state as button released 

			break;


		case L_WaitOne:
			if( PinZero == 0x00 ){
				L_State = L_WaitOne;

			}//remain in wait

			else if ( PinZero == 0x01 ) {
				L_State = L_ZeroOn;

			}//toggle light to ZeroOn


			break;

		default:
			L_State = L_Start;
			break;



}//end switch for transitions



switch(L_State){ // state actions 


	case L_Start:
		break;

	case L_ZeroOn:
		PORTB = (PORTB & 0x00) | 0x01;
		break;

	case L_WaitZero:
		break;

	case L_OneOn:
		PORTB = (PORTB & 0x00) | 0x02;
		break;

	case L_WaitOne:
		break;

	default:
		break;



}//end switch for state actions

   
	}//end infinite while loop

    return 1;

}//end main
