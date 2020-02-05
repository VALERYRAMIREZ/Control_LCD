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
    PORTDbits.RD11 = 1;
    Inicia_Ciclo_Timer1();
    while(!IFS0bits.T1IF);
    PORTDbits.RD11 = 0;
    Detiene_Ciclo_Timer1();
    while(1);
    return 0;
}