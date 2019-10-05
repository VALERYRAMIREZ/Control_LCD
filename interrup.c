#include "interrup.h"

void Inicia_Interr(void)                    /* Función para configurar e iniciar
                                             * las fuentes de interrupción. */
{
    IEC0bits.T3IE = 1;                      /* Se habilita la interrupción    */
                                            /* para el timer de 32 bits, se   */
    IPC2bits.T3IP = 1;                      /* establece la prioridad de la   */
    IFS0bits.T3IF = 0;                      /* interrupción en 1 y se borra la*/
                                            /* y se borra la bandera de       */
                                            /* del timer de 32 bits.          */
}                                           


/* Funciones para el manejo de interrupciones */

void __attribute__((interrupt(auto_psv))) _T3Interrupt(void)/* Función para   */
{                                           /* manejo de la interrupción del  */
    T2CONbits.TON = 0;                      /* timer 32 para usarlo como      */
    IFS0bits.T3IF = 0;                      /* temporizador de 32 bits.       */
    IEC0bits.T3IE = 0;
}
