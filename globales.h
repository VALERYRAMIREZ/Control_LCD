/* 
 * File:                globales.h
 * Author:              Valery Ramirez
 * Comments:            Archivo creado para manejar las definiciones de 
 *                      variables globales a usar en el sistema.
 * Revision history:    N/A
 */
 
#ifndef XC_GLOBALES_H
#define	XC_GLOBALES_H

#include <xc.h>  

/*              Variables globales a usar en el sistema.                      */

typedef union                           /* Variable tipo estructura para      */
{                                       /* marcar eventos de interrupciones en*/
    unsigned int banderas;              /* marcar eventos de interrupciones en*/
    struct                              /* las interrupciones.                */
    {                                   
        unsigned int restantes:15;
        unsigned int tecla:1;           /* Bandera para indicar el uso de la 
                                         * interrupci�n por notificaci�n de
                                         * cambio en un pin.                  */
    };
} SENALES;

#endif	/* XC_GLOBALES_H */

