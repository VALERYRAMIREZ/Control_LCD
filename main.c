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
    Confi_PuertoD(0b1111000000000000);
    Inicia_Interr();
    Inicia_Interr();
    Inicia_LCD4();
    Posicion_Cur4b(1,1);
    Esc_DCRAM4b("El menú para hoy",2);
    while(1);
    return 0;
}