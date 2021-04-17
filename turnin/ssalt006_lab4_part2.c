/*	Author: Skyler Saltos 
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description:
 *	Buttons are connected to PA0 and PA1. Output for PORTC is initially 7. Pressing PA0 increments PORTC once (stopping at 9).
 *	Pressing PA1 decrements PORTC once (stopping at 0). If both buttons are depressed (even if not initially simultaneously), PORTC resets to 0
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum SM2_States {SM2_Start, SM2_initial, SM2_Increment, SM2_Decrement, SM2_wait_minus, SM2_ReadyButton, SM2_Reset, SM2_wait_plus } SM2_State;


int main(void) {
    /* Insert DDR and PORT initializations */
	
	DDRA = 0x00; PORTA = 0xFF; // Port A as input
	DDRC = 0xFF; PORTC = 0x00; // Port C as output

	

    /* Insert your solution below */
    while (1) {

	unsigned char A0 = PINA & 0x01;
	unsigned char A1 = PINA & 0x02;
	unsigned char tempC; // hold value of PORTB for if checks 
switch(SM2_State) { // Transitions
      case SM2_Start:
         SM2_State = SM2_initial;
         break;

         case SM2_initial: 
         if (1) {
            SM2_State = SM2_ReadyButton;
         }
         break;

      case SM2_Increment: 
         if (1) {
            SM2_State = SM2_wait_plus;
         }
         break;

      case SM2_Decrement: 
         if (1) {
            SM2_State = SM2_wait_minus;
         }
         break;

      case SM2_wait_minus:

         if (!A0 && A1) {
            SM2_State = SM2_wait_minus;
         }

         else if (!A0 && !A1) {
            SM2_State = SM2_ReadyButton;
         }

         else if (A0 && A1) {
            SM2_State = SM2_Reset;
         }

	 else if ( A0 && !A1 ){
	    SM2_State = SM2_Increment;
	 }
         break;

      case SM2_ReadyButton:

         if (!A0 && !A1) {
            SM2_State = SM2_ReadyButton;
         }

         else if (A0 && !A1) {
            SM2_State = SM2_Increment;
         }

         else if (!A0 && A1) {
            SM2_State = SM2_Decrement;
         }

	 else if ( A0 && A1){
	    SM2_State = SM2_Reset;
	 }
         break;

      case SM2_Reset:

         if (1) {
            SM2_State = SM2_ReadyButton;
         }
         break;

      case SM2_wait_plus: 

         if (A0 && !A1) {
            SM2_State = SM2_wait_plus;
         }

         else if (!A0 && !A1) {
            SM2_State = SM2_ReadyButton;
         }

         else if (A0 && A1) {
            SM2_State = SM2_Reset;
         }

	 else if (!A0 && A1){
	    SM2_State = SM2_Decrement;

	 }
         break;

      default:
         SM2_State = SM2_initial;
   } // Transitions

   switch(SM2_State) { // State actions
      case SM2_initial:
         PORTC = 0x07;
         break;

      case SM2_Increment:
	 tempC = PORTC; 
         if ( tempC < 0x09 ){
         PORTC = PORTC + 0x01;
         }//checks if max reached and increments otherwise 
         break;

      case SM2_Decrement:
	 tempC = PORTC;
         if ( tempC > 0x00 ){
         PORTC = PORTC - 0x01;
         }//checks if min reached and decrements otherwise 
         break;

      case SM2_wait_minus:
         break;

      case SM2_ReadyButton:
         break;

      case SM2_Reset:
         PORTC = 0x00;
         break;

      case SM2_wait_plus:
         break;
		
      default:
     	 break;
   } // State actions


   
	}//end infinite while loop

    return 1;

}//end main
