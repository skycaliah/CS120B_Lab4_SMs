/*	Author: Skyler Saltos 
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description:
 *	Design a digital lock that requires the sequence PA2 pressed and 
 *	released and then PA1 pressed to unlock a door and PA7 locks the
 *	door from inside. 
 *
 *	I acknowledge all contenet contained herin, excluding template or
 *	example code is my original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

 
enum SM1_States {SM1_Start, SM1_init, SM1_waitAction, SM1_poundPressed, SM1_unlockWait, SM1_UnlockDoor, SM1_LockDoor } SM1_State;




int main(void) {
    /* Insert DDR and PORT initializations */
	
	DDRA = 0x00; PORTA = 0xFF; // Port A as input
	DDRB = 0xFF; PORTB = 0x00; // Port B as output
	DDRC = 0xFF; PORTC = 0x00; // Port C as watch for current state 

    /* Insert your solution below */
    while (1) {

	unsigned char A0 = PINA & 0x01;
	unsigned char A1 = PINA & 0x02;
	unsigned char A2 = PINA & 0x04;
	unsigned char A7 = PINA & 0x80;
   

   switch(SM1_State) { // Transitions
      case SM1_Start:
         SM1_State = SM1_init;
         break;

         case SM1_init:
            SM1_State = SM1_waitAction;
         break;

      case SM1_waitAction: 
         if (!A0 && !A1 && A2 && !A7) {
            SM1_State = SM1_poundPressed;
         }
         else if (!A0 && !A1 && !A2 && A7) {
            SM1_State = SM1_LockDoor;
         }
         else {
            SM1_State = SM1_waitAction;
         }
         break;

      case SM1_poundPressed: 
         if (!A0 && !A1 && A2 && !A7) {
            SM1_State = SM1_poundPressed;
         }
         else if (!A0 && !A1 && !A2 && !A7) {
            SM1_State = SM1_unlockWait;
         }
         else {
            SM1_State = SM1_waitAction;
         }
         break;

      case SM1_unlockWait: 
         if (!A0 && !A1 && !A2 && !A7) {
            SM1_State = SM1_unlockWait;
         }
         else if (!A0 && A1 && !A2 && !A7) {
            SM1_State = SM1_UnlockDoor;
         }
         else {
            SM1_State = SM1_waitAction;
         }
         break;

      case SM1_UnlockDoor: 
         if (!A0 && !A1 && !A2 && !A7) {
            SM1_State = SM1_waitAction;
         }
         else if (!A0 && A1 && !A2 && !A7) {
            SM1_State = SM1_UnlockDoor;
         }
         break;

      case SM1_LockDoor: 
         if (!A0 && !A1 && !A2 && A7) {
            SM1_State = SM1_LockDoor;
         }
         else {
            SM1_State = SM1_waitAction;
         }
         break;

      default:
         SM1_State = SM1_init;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_init:
         PORTB = 0x00;
         break;

      case SM1_waitAction:
         break;

      case SM1_poundPressed:
         break;

      case SM1_unlockWait:
         break;

      case SM1_UnlockDoor:
        PORTB = (PORTB & 0x00) | 0x01;
         break;

      case SM1_LockDoor:
         PORTB = (PORTB & 0x00) | 0x00;
         break;

      default: // ADD default behaviour below
     	 break;
   } // State actions






	}//end infinite while loop

    return 1;

}//end main
