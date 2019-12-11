/* 
 * File:                E_S.c   
 * Author:              Valery Ramirez
 * Comments:            N/A
 * Revision history:    N/A
 */

#include "E_S.h"

void Confi_PuertoD(unsigned int pinesD) /* Funci�n para configurar el         */
{                                       /* funcionamiento del puerto D.       */
    TRISD = pinesD;
    ODCD = 0;
}

void Confi_PuertoE(unsigned char pinesE)/* Funci�n para configurar el         */
{                                       /* funcionamiento del puerto E.       */
    TRISE = pinesE;
    ODCE = 0;
}

void Confi_E_S(void)                    /* Funci�n para configurar el         */
{                                       /* funcionamiento de los puertos.     */
    Confi_PuertoD(0b1111000000000000);
    Confi_PuertoE(0b11110000);
}