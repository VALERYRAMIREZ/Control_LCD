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

/* Definici�n de constantes para la selecci�n de animaci�n en la pantalla     */

#define         NOR     0           /* Mensaje impreso completo al instante.  */
#define         IZQ     1           /* Mensaje impreso de izquierda a derecha.*/
#define         DER     2           /* Mensaje impreso de derecha a izquiera. */
#define         ARR     3           /* Mensaje impreso de arriba a abajo.     */
#define         ABA     4           /* Mensaje impreso de abaja a arriba.     */

/* Definici�n de prototipos de funci�n para el control de la pantalla LCD.    */

void Inicia_LCD4(void);                 /* Prototipo de funci�n para
                                         * inicializar la pantalla LCD.       */

void Envia_Com(unsigned int comandoLCD);/* Prototipo de funci�n para enviar
                                         * un comando a la pantalla LCD.      */

void Envia_Com_RAM(unsigned int ComandoLCD);/* Prototipo de funci�n para
                                         * enviar un comando de escritura a la
                                         * CGRAM o DDRAM de la pantalla LCD en
                                         * ormato de 4 bits.                  */

void Envia_Com4b(unsigned int comandoLCD4);/* Prototipo de funci�n para enviar
                                         * un comando a la pantalla LCD en
                                         * formato de 4 bits.                 */

void Envia_Com_RAM4b(unsigned int comandoLCD4);/* Prototipo de funci�n para
                                         * enviar un comando de manipulaci�n de
                                         * la CGRAM o DDRAM con la pantalla en
                                         * modo de 4 bits.                    */

void Borra_Pant4b(void);                /* Prototipo de funci�n para borrar la
                                         * pantalla LCD.                      */

void Retorno_Carro4b(void);             /* Prototipo de funci�n para hacer el
                                         * retorno de carro en modo de 4 bits.*/

void Conf_Modo_Ent4b(unsigned int modo);/* Prototipo de funci�n para          */
                                        /* configurar el contador de direcci�n*/
                                        /* adem�s de de especificar el        */
                                        /* el deplazamiento de la pantalla o  */
                                        /* cursor durante una escritura o     */
                                        /* de datos.                          */

void Enc_Apa4b(unsigned int interr);    /* Prototipo de funci�n para encender */
                                        /* y apagar la pantalla, tambi�n      */
                                        /* configura el parpadeo del caracter */
                                        /* en la posici�n del cursor.         */

void Desp_Cur4b(unsigned int direc);    /* Prototipo de funci�n para desplazar*/
                                        /* el cursor sin cambiar el contenido */
                                        /* de la DDRAM.                       */

void Conf_Func4b(unsigned int funcion);  /* Prototipo de funci�n para          */
                                        /* establecer la logntud del bus de   */
                                        /* datos, el n�mero de l�neas de la   */
                                        /* pantalla y el tama�o de los        */
                                        /* caracteres.                        */

void Conf_CGRAM4b(unsigned int dirC);   /* Prototipo de funci�n para          */
                                        /* establecer la direcci�n de la CGRAM*/

void Conf_DDRAM4b(unsigned int dirD);   /* Prototipo de funci�n para          */
                                        /* establecer la direcci�n de la CGRAM*/

/* Debo seguir trabajando en las funci�n Lee_BF4b para retornar el dato       */
//Lee_BF4b(unsigned int dirB);            /* Prototipo de funci�n para y leer la*/
//                                        /* bandera de ocupado y el contenido  */
//                                        /* de el contador de direcciones      */

void Esc_DCRAM4b(char *fra, char anim); /* Prototipo de funci�n para          */
                                        /* escribir datos a la DDRAM o CGRAM, */
                                        /* e incrementar o decrementar el     */
                                        /* contador de direcciones.           */

/* Debo seguir trabajando en las funci�n Lee_DCRAM4b para retornar el dato    */

//Lee_DCRAM4b(unsigned int dat)           /* Lee dato de la DDRAM o CGRAM e     */
//{                                       /* incrementa o decrementa el contador*/
//    Envia_Com4b(LDCD | dat)             /* de direcciones.                    */
//    retardo_us(40);
//}                       */

void Posicion_Cur4b(char fila, char columna);/* Prototipo de funci�n para mover
                                         * el cursor hacia una direcci�n.     */

void Mensaje_Ent(char *mensaje);        /* Prototipo de funci�n para imprimir
                                         * el mensaje completo sin animaci�n. */

void Mensaje_Izq(char *mensaje);        /* Prototipo de funci�n para imprimir
                                         * el mensaje con los caracteres
                                         * apareciendi de izquierda a derecha.*/

void Mensaje_Der(char *mensaje);        /* Prototipo de funci�n para imprimir
                                         * el mensaje con los caracteres
                                         * apareciendo de derecha a izquierda.*/

void Menu(void);                        /* Prototipo de funci�n para seleccionar
                                         * el men� a desplegar en la panalla
                                         * LCD.                               */



#endif	/* LCD_44780_H */
