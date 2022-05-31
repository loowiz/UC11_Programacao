/* ============================================================
 * CT Eletroeletrônica EaD
 * -----------------------
 * NOME:        04 - Display e IOs
 * DESCRIÇÃO:   Testes com Display e entradas e saídas
 * DATA:        05/12/2019
 * ========================================================== */


// ==========================================================
// BIBLIOTECAS
// ==========================================================
#include <xc.h>
#include <delays.h>
#include "lcd.h"
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
#define _XTAL_FREQ  4000000

// --------- ENTRADAS --------- 
#define Botao_01        PORTBbits.RB1
#define Botao_02        PORTBbits.RB0
#define Botao_03        PORTCbits.RC2
#define Botao_04        PORTCbits.RC4
#define Tris_Botao_01   TRISBbits.TRISB1
#define Tris_Botao_02   TRISBbits.TRISB0
#define Tris_Botao_03   TRISCbits.TRISC2

// --------- SAÍDAS --------- 
#define LED_01      PORTDbits.RD0
#define LED_02      PORTDbits.RD1
#define LED_03      PORTDbits.RD2
#define LED_04      PORTDbits.RD3
#define LED_05      PORTDbits.RD4
#define LED_06      PORTDbits.RD5
#define LED_07      PORTDbits.RD6
#define LED_08      PORTDbits.RD7
#define Tris_LED_01 TRISDbits.TRISD0
#define Tris_LED_02 TRISDbits.TRISD1
#define Tris_LED_03 TRISDbits.TRISD2
#define Tris_LED_04 TRISDbits.TRISD3
#define Tris_LED_05 TRISDbits.TRISD4
#define Tris_LED_06 TRISDbits.TRISD5
#define Tris_LED_07 TRISDbits.TRISD6
#define Tris_LED_08 TRISDbits.TRISD7
// ==========================================================


// ==========================================================
// PROGRAMA PRINCIPAL
// ==========================================================
void main(void) {
    // ------------------------------------------------------
    // CONFIGURAÇÕES INICIAIS
    // ------------------------------------------------------
    Tris_Botao_01 = 1;      // Configura pino do botão como entrada
    Tris_Botao_02 = 1;      // Configura pino do botão como entrada
    Tris_Botao_03 = 1;      // Configura pino do botão como entrada
    //TRISCbits.RC4 = 1;    // Apenas para mostrar que o pino RC4 não é configurado como entrada desta forma no 18F4550
                            // RC4 é ativada pelas opções de USB abaixo.
    UCON = 0x00;            //** PARA O PIC 18F4550: desativa opções de USB para utilizar a porta RC4 como entrada
    UCFGbits.UTRDIS = 1;    //** PARA O PIC 18F4550: desativa opções de USB para utilizar a porta RC4 como entrada
    
    Tris_LED_01 = 0;        // Configura pino do LED como saída
    Tris_LED_02 = 0;        // Configura pino do LED como saída
    Tris_LED_03 = 0;        // Configura pino do LED como saída
    Tris_LED_04 = 0;        // Configura pino do LED como saída
    Tris_LED_05 = 0;        // Configura pino do LED como saída
    Tris_LED_06 = 0;        // Configura pino do LED como saída
    Tris_LED_07 = 0;        // Configura pino do LED como saída
    Tris_LED_08 = 0;        // Configura pino do LED como saída
    
    IniciaLCD();            // Função que configura e inicializa LCD
    // ------------------------------------------------------
    
	LimpaLCD();                     // Limpa tela do display
	PosicionaLCD(1,1);              // Posiciona o cursor na linha 1 e coluna 1
	StringLCD("  SENAI CFP 118 ");  // Estreve texto
	PosicionaLCD(2,1);              // Posiciona o cursor na linha 2 e coluna 1
	StringLCD(" A. JACOB LAFER ");  // Estreve texto
    
    while(1){
        if(Botao_01 == 1){
            LED_03 = 0;            // Desliga pino RD0
            Delay10KTCYx(10);      // Delay de 100ms [10000*(1us)*50]
            LED_03 = 1;            // Desliga pino RD0
            Delay10KTCYx(10);      // Delay de 100ms [10000*(1us)*50]    
        }
        else {
            LED_01 = 0;            // Desliga pino RD0
            Delay10KTCYx(50);      // Delay de 500ms [10000*(1us)*50]
            LED_01 = 1;            // Desliga pino RD0
            Delay10KTCYx(50);      // Delay de 500ms [10000*(1us)*50]
        }
    }
}
// ==========================================================
