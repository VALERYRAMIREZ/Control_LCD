#include "interrup.h"

void Inicia_Interr(void)                    /* Funci�n para configurar e iniciar
                                             * las fuentes de interrupci�n. */
{
    IEC0bits.T3IE = 1;                      /* Se habilita la interrupci�n    */
                                            /* para el timer de 32 bits, se   */
    IPC2bits.T3IP = 1;                      /* establece la prioridad de la   */
    IFS0bits.T3IF = 0;                      /* interrupci�n en 1 y se borra la*/
                                            /* y se borra la bandera de       */
                                            /* del timer de 32 bits.          */
}                                           


/* Funciones para el manejo de interrupciones */

void __attribute__((interrupt(auto_psv))) _T3Interrupt(void)/* Funci�n para   */
{                                           /* manejo de la interrupci�n del  */
    T2CONbits.TON = 0;                      /* timer 32 para usarlo como      */
    IFS0bits.T3IF = 0;                      /* temporizador de 32 bits.       */
    IEC0bits.T3IE = 0;
}
