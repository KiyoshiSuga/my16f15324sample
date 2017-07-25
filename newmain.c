/* 
 * File:   newmain.c
 * Author: user
 *
 * Created on 2017/06/28, 22:50
 */



// PIC16F15324 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC = HS    // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = EXT1X  // Power-up default value for COSC bits (HFINTOSC (1MHz))
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit (CLKOUT function is enabled; FOSC/4 clock appears at OSC2)
#pragma config CSWEN = OFF      // Clock Switch Enable bit (The NOSC and NDIV bits cannot be changed by user software)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (FSCM timer disabled)

// CONFIG2
#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = OFF      // Brown-out reset enable bits (Brown-out reset disabled)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control (The PPSLOCK bit can be set and cleared repeatedly by software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config BBSIZE = BB512   // Boot Block Size Selection bits (512 words boot block size)
#pragma config BBEN = OFF       // Boot Block Enable bit (Boot Block disabled)
#pragma config SAFEN = OFF      // SAF Enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block Write Protection bit (Application Block not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration Register not write protected)
#pragma config WRTSAF = OFF     // Storage Area Flash Write Protection bit (SAF not write protected)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (UserNVM code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void interrupt isr(void){
    if(PIR0bits.TMR0IF){
        TMR0H=64;
        TMR0L=0;
        PIR0bits.TMR0IF = 0;
        PORTCbits.RC3 = (unsigned)!PORTCbits.RC3;
//        PORTCbits.RC3 = (unsigned)!PORTCbits.RC3;
//        PORTCbits.RC3 = (unsigned)!PORTCbits.RC3;
    }
}
void main(void) {
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    ANSELCbits.ANSC2 = 0;
    TRISCbits.TRISC2 = 0;

    ANSELCbits.ANSC3 = 0;
    TRISCbits.TRISC3 = 0;
    
    T0CON0bits.T0EN = 1;
    T0CON0bits.T016BIT = 1;
    T0CON0bits.T0OUTPS = 0;
    T0CON1bits.T0CS = 2;
    T0CON1bits.T0ASYNC = 0;
    T0CON1bits.T0CKPS = 5;
    PIE0bits.TMR0IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    while(1){
        PORTCbits.RC2 = (unsigned)!PORTCbits.RC2;
//        asm("nop");
//        asm("nop");
//        asm("nop");
//        asm("nop");    
    }
}

