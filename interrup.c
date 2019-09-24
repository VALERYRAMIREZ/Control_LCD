#include "interrup.h"

void Inicia_Interr(void)                    /* Funci�n para configurar e iniciar
                                             * las fuentes de interrupci�n. */
{
    IPC2bits.T3IP = 1;                      /* Se habilita la interrupci�n del*/
    IFS0bits.T3IF = 0;                      /* timer 2 con prioridad 1 (la */
    IEC0bits.T3IE = 1;                      /* inmediata superior a la del CPU*/
                                            /* la cual es cero . */
}

/* Funciones para el manejo de interrupciones */

void __attribute__((interrupt(auto_psv))) _T3Interrupt(void)/* Funci�n para   */
{                                           /* manejo de la interrupci�n del  */
    T2CONbits.TON = 0;                      /* timer 32 para usarlo como      */
    IFS0bits.T3IF = 0;                      /* temporizador de 32 bits.       */
    IEC0bits.T3IE = 0;
}
