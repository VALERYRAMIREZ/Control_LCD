/* 
 * File:                mensajes.h
 * Author:              Valery Ramirez
 * Comments:            Archivo de cabecera para el manejo de mensajes.
 * Revision history:    N/A
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MENSAJES_H
#define	XC_MENSAJES_H

#include <xc.h> // include processor files - each processor file is guarded.  

/* Definici�n de prototipos de funci�n.                                       */

unsigned char Dim_Mensaje(char *mensaje);/* Prototipo de funci�n para            
                                         * determinar la cantidad de elementos
                                         * en un string.                      */

#endif	/* XC_MENSAJES_H */

