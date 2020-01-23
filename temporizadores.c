/* 
 * File:                temprizadores.h
 * Author:              Valery Ramirez
 * Comments:            Encabezado para la configuraci�n de los temporizadores.
 * Revision history:    N/A
 */

#include "temporizadores.h"
#include "sistema.h"

/* Implementaci�n de las funciones para la configuraci�n de los temporizadores*/

void Ciclo_Timer1(unsigned int tempo1, unsigned int conf1) /* Funci�n para la  */
{                                       /* configuraci�n del timer 1.         */
    Sec_Osc(SOSCENH);                   /* No se inicia el timer 1 en esta    */
    T1CON = 0;                          /* ci�n para dejar al usuario decidir */
    TMR1 = 0;                           /* cuando encenderlo.                 */
    T1CON = conf1;                      /* Est� configurado para contar 100ms */
    PR1 = tempo1*0x0ccd;                /* y se usar� para hacer el reloj en  */
}                                       /* tiempo real.                       */

void Inicia_Ciclo_Timer1(void)          /* Inicia el timer 1.                 */
{
    T1CONbits.TON = 1;
}  

void Detiene_Ciclo_Timer1(void)         /* Detiene el timer 1.                */
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

void Confi_Timer23(void)                /* Funci�n para configurar el         */
{                                       /* temporizador de 32 bits, usado para*/
    T2CON = 0;                          /* el manejo de la pantalla LCD.      */
    T3CON = 0;
    TMR2 = 0;
    TMR3 = 0;  
    T2CON = 0b0000000000001000;
}

void retardo_us(unsigned long ret2)     /* Funci�n para generar retardos en us*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    Confi_Timer23();
    T2CON = 0b0000000000001000;
    ret2 *= 0x000a;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer2();
    while(T2CONbits.TON == 1)
    {
        asm("nop");
    }
    Detiene_Timer2();
    return;
}

void retardo_ms(unsigned long ret2)     /* Funci�n para generar retardos en ms*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    Confi_Timer23();
    ret2 *= 0x2710;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer2();
    while(T2CONbits.TON == 1)
    {
        asm("nop");
    }
    Detiene_Timer2();
    return;
}

void retardo_s(unsigned long ret2)      /* Funci�n para generar retardos en ms*/
{                                       /* m�ximo 1000us. */
    if(ret2 > 1000)
    {
        ret2 = 1000;
    }
    Confi_Timer23();
    ret2 *= 0x00989680;
    PR2 = (unsigned int) ret2;          /* Valores a precargar en PR2 a PR3   */
    ret2 >>= 16;                        /* para generar retardos en us.       */
    PR3 = (unsigned int) ret2;
    Inicia_Timer2();
    while(T2CONbits.TON == 1)
    {
        asm("nop");
    }
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

/*                  Funciones para el manejo del temporizador 4.              */

void Confi_Timer4()                     /* Funci�n para                       */
{                                       /* configurar el funcionamiento del   */
    T4CON = 0;                          /* temporizador 4.                    */
    TMR4 = 0;                     
    PR4 = 0;                            /* FALTA LLENAR ESTA FUNCI�N.         */
    //PR4 = tempo4*0x000a;
}



void retardo_T4_ms(unsigned long ret4)  /* Funci�n para generar retardos en ms*/
{                                       /* m�ximo 1000us.                     */
    if(ret4 > 1000)                     /* La funci�n est� dise�ada para      */
    {                                   /* iniciar el temporizador y salir de */
        ret4 = 1000;                    /* la misma y de esa manera no        */
    }                                   /* bloquear el funcionamiento del     */
    Confi_Timer4();                     /* programa.                          */
    PR4 = ret4*0x512;
    Inicia_Timer4();
    return;
}

void Inicia_Timer4(void)                /* Inicia el timer 4.                 */
{
    T4CONbits.TON = 1;
}  

void Detiene_Timer4(void)               /* Detiene el timer 4.                */
{
    T4CONbits.TON = 0;
}

void Confi_Timer45(void)                /* Configuraci�n del temporizador45   */
{                                       /* (modo de 32 bits) a ser usado para */
    T4CON = 0;                          /* el ciclo del sistema.              */
    T5CON = 0;
    TMR4 = 0;
    TMR5 = 0;  
    T4CON = 0b0000000000001000;
}

void Ciclo45_ms(unsigned long ret45)    /* Funci�n para generar retardos en ms  */
{                                       /* m�ximo 1000us.                       */
    if(ret45 > 1000)
    {
        ret45 = 1000;
    }
    IFS1bits.T5IF = 0;                  
    Confi_Timer45();                    /* Se configura el timer45 de 32 bits.   */
    ret45 *= 0x2710;
    PR4 = (unsigned int) ret45;         /* Valores a precargar en PR4 a PR5 para */
    ret45 >>= 16;                       /* generar retardos en ms. Esta funci�n  */
    PR5 = (unsigned int) ret45;         /* al creada para darle una frecuencia de*/
    Inicia_Timer4();                    /* ciclo al sistema, no bloquea la
                                         * ejecuci�n de c�digo hasta que termina
                                         * sino que inicia el temporizador para
                                         * luego saltar a la rutina de interrupci�n
                                         * respectiva.                           */
    return;
}

//void Inicia_Ciclo45(void)               /* Funcion para iniciar el timer 45 de*/
//{                                       /* 32 bits.                           */
//    T4CONbits.TON = 1;
//}
//
//void Detiene_Ciclo45(void)              /* Funci�n para iniciar el timer 45 de*/
//{                                       /* 32 bits.                           */
//    T4CONbits.TON = 0;
//}
