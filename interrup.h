/* 
 * File:                interrup.h
 * Author:              Valery Ramirez
 * Comments:            Archivo de cabecera para configurar las fuentes de 
 *                      interrupci�n.
 * Revision history:    N/A
 */
  
#ifndef INTERRUP_H
#define	INTERRUP_H

#include <xc.h>
#include "globales.h"

/*            Definici�n de constantes a usar en las interrupciones.          */

void Inicia_Interr(void);           /* Prototipo de funci�n para configurar e
                                     * iniciar las fuentes de interrupci�n.   */

/* Prototipos de funci�n para manejar las fuentes de interrupci�n */

void __attribute__((interrupt(no_auto_psv))) _T1Interrupt(void);/* Prototipo de
                                             * funci�n para manejar la
                                             * interrupci�n del timer 1.      */

void __attribute__((interrupt(no_auto_psv))) _T2Interrupt(void);/* Prototipo de
                                             * funci�n para manejar la
                                             * interrupci�n del timer 2.      */

void __attribute__((interrupt(no_auto_psv))) _CNInterrupt(void);/* Prototipo de
                                             * funci�n para manejar la
                                             * interrupci�n por notificaci�n
                                             * de cambio en los pines
                                             * seleccionados.                 */
#endif	/* INTERRUP_H */

