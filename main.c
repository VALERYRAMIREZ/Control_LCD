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
#include "LCD_44780.h"

int main(void) {
    Tipo_Osc(PROSC);
    Confi_PuertoD(0b1111000000000000);
    Inicia_Interr();
    Inicia_LCD4();
    Posicion_Cur4b(2,5);

    while(T2CONbits.TON == 1)
    {
        PORTDbits.RD6 = 1;   
    }
    while(T2CONbits.TON == 0)
    {
        PORTDbits.RD6 = 0;
    }
    while(1);
    return 0;
}