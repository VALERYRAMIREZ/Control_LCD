/* 
 * File:                LCD_44780.h
 * Author:              Valery Ramirez
 * Comments:            Configuraci�n de control para pantalla LCD basada en
 *                      el controlador HD44780
 * Revision history:    N/A
 */
  
#ifndef LCD_44780_H
#define	LCD_44780_H

#include <xc.h> 

/* Definici�n de terminales para el control de la pantalla LCD. */

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

/* Definici�n de constantes para usar en los comandos de control para la
   pantalla LCD                                                               */

#define         BP      0x01            /* Borrar pantalla                    */
#define         RC      0x02            /* Retorno de carro                   */
#define         CME     0x04            /* Configuraci�n del modo de entrada  */
#define         EAP     0x08            /* Encender-apagar pantalla           */
#define         CDD     0x10            /* Desplazamiento del cursor o display*/
#define         CF      0x20            /* Configuraci�n de funci�n           */
#define         ECGR    0x40            /* Establecer direcci�n de la CGRAM   */
#define         EDDR    0x80            /* Establecer direcci�n de la DDRAM   */
#define         LBFD    0x100           /* Leer bandera de ocupado y contenido
                                         * del contador.                      */
#define         EDCD    0x200           /* Escribe dato a la DD o CG RAM e
                                           incrementa o decrementa el contador
                                           de direcci�n (AC).                 */
#define         LDCD    0x300           /* Lee dato de la DD o CG RAM e
                                           incrementa o decrementa el contador
                                           de direcci�n (AC).                 */

/* Definici�n de posici�n inicial de las l�neas para la pantalla de 4 l�neas
   por 16 caracteres.                                                         */

#define         lin_1_i 0x80
#define         lin_1_f 0x8f
#define         lin_2_i 0xc0
#define         lin_2_f 0xcf
#define         lin_3_i 0x90
#define         lin_3_f 0x9f
#define         lin_4_i 0xd0
#define         lin_4_f 0xdf

/* Definici�n de prototipos de funci�n para el control de la pantalla LCD.    */

void Inicia_LCD4(void);                 /* Prototipo de funci�n para
                                         * inicializar la pantalla LCD.       */

void Envia_Com(unsigned int comandoLCD);/* Prototipo de funci�n para enviar
                                         * un comando a la pantalla LCD.      */

void Envia_Com4b(unsigned int ComandoLCD4);/* Prototipo de funci�n para enviar
                                         * un comando a la pantalla LCD en
                                         * formato de 4 bits.                 */

void Posicion_Cur4b(char fila, char columna);/* Prototipo de funci�n para mover
                                         * el cursor hacia una direcci�n.     */

#endif	/* LCD_44780_H */
