#include "interrup.h"

void Inicia_Interr(void)                /* Función para configurar e iniciar
                                         * las fuentes de interrupción.       */
{
    IEC0bits.T3IE = 1;                  /* Se habilita la interrupción        */
                                        /* para el timer de 32 bits, se       */
    IPC2bits.T3IP = 1;                  /* establece la prioridad de la       */
    IFS0bits.T3IF = 0;                  /* interrupción en 1 y se borra la    */
                                        /* la bandera del timer de 32         */
                                        /* bits.                              */
    
    IEC1bits.CNIE = 1;                  /* Se habilitan los pines CN62 a CN65 */
    IPC4bits.CNIP = 2;                  /* para detectar el cambio de estado, */
    IFS1bits.CNIF = 0;                  /* esto es, los Puerto E,4 a Puerto   */
    CNEN4 = 0xc000;                     /* E,7 para detectar la tecla         */
    CNEN5 = 0x0003;                     /* presionada. También se configuró la*/
                                        /* prioridad de la interrupción por   */
                                        /* notificación de cambio de estado en*/
                                        /* 2, un nivel más alta que la del    */
                                        /* temporizador.                      */
}

/* Funciones para el manejo de interrupciones */

void __attribute__((interrupt(no_auto_psv))) _T3Interrupt(void)/* Función para*/
{                                           /* manejo de la interrupción del  */
    T2CONbits.TON = 0;                      /* timer 32 para usarlo como      */
    IFS0bits.T3IF = 0;                      /* temporizador de 32 bits.       */
}

void __attribute__((interrupt(no_auto_psv))) _CNInterrupt(void)/* Función para*/
{                                       /* el manejo de la interrupción por   */
                                        /* cambio de estado en los terminales */
    IFS1bits.CNIF = 0;                  /* habilitados para este tipo de      */
                                        /* interrupción.                      */
}
