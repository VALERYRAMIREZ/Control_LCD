/* 
 * File:                temprizadores.h
 * Author:              Valery Ramirez
 * Comments:            Encabezado para la configuraci�n de los temporizadores.
 * Revision history:    N/A
 */

#include "temporizadores.h"
#include "sistema.h"

/* Implementaci�n de las funciones para la configuraci�n de los temporizadores*/

void Confi_Timer1(unsigned int tempo1, unsigned int conf1)/* Funci�n para la 
                                         * configuraci�n del 
                                         * timer 1. */
{
    Sec_Osc(SOSCENH);
    T1CON = 0;
    TMR1 = 0;
    T1CON = conf1;                      
    PR1 = tempo1;                       /* No se inicia el timer 1 en esta
                                         * ci�n para dejar al usuario decidir
                                         * cuando encenderlo. */
}

void Inicia_Timer1(void)                /* Inicia el timer 1. */
{
    T1CONbits.TON = 1;
}  

void Detiene_Timer1(void)               /* Detiene el timer 1. */
{
    T1CONbits.TON = 0;
}

void Confi_Timer2(unsigned int tempo2, unsigned int confi2)/* Funci�n para
                                         * configurar el funcionamiento del
                                         * timer 2. */
{
    T2CON = 0;
    TMR2 = 0;
    T2CON = confi2;                      
    PR2 = tempo2*0x000a;
}

void retardo_us(unsigned long ret2)     /* Funci�n para generar retardos en us*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    T2CON = 0;
    T3CON = 0;
    TMR2 = 0;
    TMR3 = 0;
    T2CON = 0b0000000000001000;
    ret2 *= 0x000a;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer232();
    do
    {
        asm("nop");
    }while(IEC0bits.T3IE == 0);
    T2CONbits.T32 = 0;
    return;
}

void retardo_ms(unsigned long ret2)     /* Funci�n para generar retardos en ms*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    T2CON = 0;
    T3CON = 0;
    TMR2 = 0;
    TMR3 = 0;
    T2CON = 0b0000000000001000;
    ret2 *= 0x2710;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer2();
    while(IEC0bits.T3IE == 0);
    Detiene_Timer2();
    return;
}

void retardo_s(unsigned long ret2)      /* Funci�n para generar retardos en ms*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    T2CON = 0;
    T3CON = 0;
    TMR2 = 0;
    TMR3 = 0;
    T2CON = 0b0000000000001000;
    ret2 *= 0x00989680;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer2();
    while(IEC0bits.T3IE == 0);
    Detiene_Timer2();
    return;
}

void Inicia_Timer2(void)                /* Funci�n para iniciar el timer 2. */
{
    T2CONbits.TON = 1;
}

void Detiene_Timer2(void)               /* Funci�n para detener el timer 2. */
{
    T2CONbits.TON = 0;
}

void Inicia_Timer232(void)              /* Funcion para iniciar el timer 23 de*/
{                                       /* 32 bits.                           */
    T2CONbits.T32 = 1;
}

void Detiene_Timer232(void)             /* Funcion para iniciar el timer 23 de*/
{                                       /* 32 bits.                           */
    T2CONbits.T32 = 0;
}
