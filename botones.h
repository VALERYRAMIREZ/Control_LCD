/* 
 * File:                botones.h
 * Author:              Valery Ramirez
 * Comments:            Librer�a para la manipulaci�n de los botones, teclado.
 * Revision history:    N/A
 */

#ifndef XC_BOTONES_H
#define	XC_BOTONES_H

#include <xc.h> 

/* Definiciones de constantes usadas para el teclado*/

char Lee_Teclado(unsigned char teclado);/* Prototipo de funci�n para
                                        * determinar cu�l bot�n del teclado se
                                        * ley�.                               */

char det_Tecla(unsigned char lectura);/* Prototipo de funci�n para
                                        * asignar el valor de la tecla
                                        * presionada.                         */

#endif	/* XC_BOTONES_H */

