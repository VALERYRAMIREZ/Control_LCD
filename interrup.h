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

void Inicia_Interr(void);                   /* Prototipo de funci�n para
                                             * configurar e iniciar las fuentes
                                             * de interrupci�n. */


/* Prototipos de funci�n para manejar las fuentes de interrupci�n */

void __attribute__((interrupt(auto_psv))) _T2Interrupt(void);/* Prototipo de
                                             * funci�n para manejar la
                                             * interrupci�n del timer 2. */
#endif	/* INTERRUP_H */

