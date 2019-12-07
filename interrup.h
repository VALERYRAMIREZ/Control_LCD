/* 
 * File:                interrup.h
 * Author:              Valery Ramirez
 * Comments:            Archivo de cabecera para configurar las fuentes de 
 *                      interrupción.
 * Revision history:    N/A
 */
  
#ifndef INTERRUP_H
#define	INTERRUP_H

#include <xc.h> 

void Inicia_Interr(void);                   /* Prototipo de función para
                                             * configurar e iniciar las fuentes
                                             * de interrupción. */


/* Prototipos de función para manejar las fuentes de interrupción */

void __attribute__((interrupt(auto_psv))) _T2Interrupt(void);/* Prototipo de
                                             * función para manejar la
                                             * interrupción del timer 2. */
#endif	/* INTERRUP_H */

