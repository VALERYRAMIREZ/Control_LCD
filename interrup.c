#include "interrup.h"

void Inicia_Interr(void)                /* Funci�n para configurar e iniciar
                                         * las fuentes de interrupci�n.       */
{
    IEC0bits.T3IE = 1;                  /* Se habilita la interrupci�n        */
                                        /* para el timer de 32 bits, se       */
    IPC2bits.T3IP = 1;                  /* establece la prioridad de la       */
    IFS0bits.T3IF = 0;                  /* interrupci�n en 1 y se borra la    */
                                        /* la bandera del timer de 32         */
                                        /* bits.                              */
    
    IEC1bits.CNIE = 1;                  /* Se habilitan los pines CN62 a CN65 */
    IPC4bits.CNIP = 2;                  /* para detectar el cambio de estado, */
    IFS1bits.CNIF = 0;                  /* esto es, los Puerto E,4 a Puerto   */
    CNEN4 = 0xc000;                     /* E,7 para detectar la tecla         */
    CNEN5 = 0x0003;                     /* presionada. Tambi�n se configur� la*/
                                        /* prioridad de la interrupci�n por   */
                                        /* notificaci�n de cambio de estado en*/
                                        /* 2, un nivel m�s alta que la del    */
                                        /* temporizador.                      */
}

/* Funciones para el manejo de interrupciones */

void __attribute__((interrupt(no_auto_psv))) _T3Interrupt(void)/* Funci�n para*/
{                                           /* manejo de la interrupci�n del  */
    T2CONbits.TON = 0;                      /* timer 32 para usarlo como      */
    IFS0bits.T3IF = 0;                      /* temporizador de 32 bits.       */
}

void __attribute__((interrupt(no_auto_psv))) _CNInterrupt(void)/* Funci�n para*/
{                                       /* el manejo de la interrupci�n por   */
                                        /* cambio de estado en los terminales */
    IFS1bits.CNIF = 0;                  /* habilitados para este tipo de      */
                                        /* interrupci�n.                      */
}
