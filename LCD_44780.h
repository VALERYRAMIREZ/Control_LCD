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

#define         RS      PORTDbits.RD10
#define         RW      PORTDbits.RD9
#define         E       PORTDbits.RD8
#define         D7      PORTDbits.RD7
#define         D6      PORTDbits.RD6
#define         D5      PORTDbits.RD5
#define         D4      PORTDbits.RD4
#define         D3      PORTDbits.RD3
#define         D2      PORTDbits.RD2
#define         D1      PORTDbits.RD1
#define         D0      PORTDbits.RD0

/* Definición de constantes para usar en los comandos de control para la
   pantalla LCD                                                               */

#define         BP      0x01            /* Borrar pantalla                    */
#define         RC      0x02            /* Retorno de carro                   */
#define         CME     0x04            /* Configuración del modo de entrada  */
#define         EAP     0x08            /* Encender-apagar pantalla           */
#define         CDD     0x10            /* Desplazamiento del cursor o display*/
#define         CF      0x20            /* Configuración de función           */
#define         DCGR    0x40            /* Establecer dirección de la CGRAM   */
#define         DDDR    0x80            /* Establecer dirección de la DDRAM   */
#define         LBFD    0x100           /* Leer bandera de ocupado y contenido
                                        /* del contador.                      */
#define         EDCD    0x200           /* Escribe dato a la DD o CG RAM e
                                           incrementa o decrementa el contador
                                           de dirección (AC).                      */
#define         LDCD    0x300           /* Lee dato de la DD o CG RAM e
                                           incrementa o decrementa el contador
                                           de dirección (AC).                 */

/* Definición de prototipos de función para el control de la pantalla LCD.    */

void Inicia_LCD4(unsigned short dato);      /* Prototipo de función para
                                             * inicializar la pantalla LCD.   */

void Envia_Com(unsigned int comandoLCD);    /* Prototipo de función para enviar
                                             * un comando a la pantalla LCD.  */

void Desplaza_Cur(char dir, char salto);    /* Prototipo de función para mover
                                             * el cursor hacia una dirección. */

#endif	/* LCD_44780_H */

