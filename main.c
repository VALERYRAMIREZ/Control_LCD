/*
 * File:   main.c
 * Author: valery
 *
 * Created on 5 de septiembre de 2019, 14:54
 */


#include <xc.h>
#include "sistema.h"
#include "E_S.h"
#include "temporizadores.h"
#include "interrup.h"
#include "mensajes.h"
#include "LCD_44780.h"

int main(void) {
    Tipo_Osc(PROSC);
    Confi_E_S();
    Inicia_Interr();
    Inicia_LCD4();
    Posicion_Cur4b(1,1);
    Ciclo_Timer1(100,0b0000000000000010);
    PORTDbits.RD11 = 1;
    while(IFS0bits.T1IF);
    PORTDbits.RD11 = 0;
    while(1);
    return 0;
}