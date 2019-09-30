/* 
 * File:                LCD_44780.h
 * Author:              Valery Ramirez
 * Comments:            Configuración de control para pantalla LCD basada en
 *                      el controlador HD44780
 * Revision history:    N/A
 */
  
#ifndef LCD_44780_H
#define	LCD_44780_H

#include <xc.h> 

/* Definición de terminales para el control de la pantalla LCD. */

#define         RS      PORTDbits.RD0
#define         RW      PORTDbits.RD1
#define         E       PORTDbits.RD2
#define         D7      PORTDbits.RD3
#define         D6      PORTDbits.RD4
#define         D5      PORTDbits.RD5
#define         D4      PORTDbits.RD6
#define         D3      PORTDbits.RD7
#define         D2      PORTDbits.RD8
#define         D1      PORTDbits.RD9
#define         D0      PORTDbits.RD10

/* Definición de prototipos de función para el control de la pantalla LCD.    */

void Inicia_LCD4(unsigned short dato);      /* Prototipo de función para
                                             * inicializar la pantalla LCD.   */

#endif	/* LCD_44780_H */
