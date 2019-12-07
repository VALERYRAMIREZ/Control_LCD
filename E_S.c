/* 
 * File:                E_S.c   
 * Author:              Valery Ramirez
 * Comments:            N/A
 * Revision history:    N/A
 */

#include "E_S.h"

void Confi_PuertoD(unsigned int pinesD) /* Función para configurar el
                                         * funcionamiento del puerto D. */
{
    TRISD = pinesD;
    ODCD = 0;
}