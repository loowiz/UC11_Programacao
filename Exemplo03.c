/* ============================================================
 * CT Eletroeletrônica EaD
 * -----------------------
 * NOME:        03 - Uso de Delay
 * DESCRIÇÃO:   Testes de entradas e saídas
 * DATA:        28/11/2019
 * ========================================================== */


// ==========================================================
// BIBLIOTECAS
// ==========================================================
#include <xc.h>
// ==========================================================


// ==========================================================
// CONFIGURAÇÕES DO MICROCONTROLADOR
// ==========================================================
#pragma config  FOSC    = HS
#pragma config  PLLDIV  = 1
#pragma config  CPUDIV  = OSC1_PLL2
#pragma config  USBDIV  = 1
#pragma config  BORV    = 0
#pragma config  WDTPS   = 1
#pragma config  MCLRE   = ON
#pragma config	PWRT=ON, LVP=OFF, IESO=OFF, WDT=OFF, PBADEN=OFF, BOR=OFF
#pragma config  CCP2MX=OFF, LPT1OSC=OFF, ICPRT=OFF, XINST=OFF, VREGEN=OFF
#pragma config  CP0=OFF, CP1=OFF, CP2=OFF, CP3=OFF, CPB=OFF, CPD=OFF, WRTD = OFF
#pragma config  WRT0=OFF, WRT1=OFF, WRT2=OFF, WRT3=OFF, WRTC = OFF, WRTB = OFF
#pragma config  EBTR0=OFF, EBTR1=OFF, EBTR2=OFF, EBTR3=OFF, EBTRB=OFF
// ==========================================================


// ==========================================================
// DEFINIÇÕES
// ==========================================================
#define _XTAL_FREQ 4000000
// ==========================================================


// ==========================================================
// PROGRAMA PRINCIPAL
// ==========================================================
void main(void) {
    // ------------------------------------------------------
    // CONFIGURAÇÕES INICIAIS
    // ------------------------------------------------------
    TRISDbits.RD0 = 0;  // Configura pino RD0 como saída
    // ------------------------------------------------------
    
    while(1){
        PORTDbits.RD0 = 0; // Desliga pino RD0
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        PORTDbits.RD0 = 1; // Desliga pino RD0
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
    }
}
// ==========================================================
