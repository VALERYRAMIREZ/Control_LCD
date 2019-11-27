#include "LCD_44780.h"
#include "temporizadores.h"

/* Definición de funciones para el control de la pantalla LCD. */

void Inicia_LCD4(void)                      /* Función para inicializar la    */
{                                           /* pantalla LCD.                  */
    PORTD = 0;
    
    retardo_ms(16);
                                     
    Envia_Com(0x30);
    
    retardo_ms(10);
    
    Envia_Com(0x30);
    
    retardo_us(100);
    
    Envia_Com(0x30);

    retardo_us(100);
    
    Envia_Com(CF);
    
    Envia_Com4b(CF | 0x08);
    
    Envia_Com4b(CF | 0x08);
    
    Envia_Com4b(CME);
    
    Envia_Com4b(EAP | 0x06);

    Borra_Pant4b();
}

void Envia_Com(unsigned int comandoLCD)
{
    retardo_us(5);
    E = 1;
    PORTD = comandoLCD | 0x100;
    retardo_us(5);
    E = 0;
}

void Envia_Com4b(unsigned int comandoLCD4)/* Función para enviar comando con  */
{                                       /* la pantalla incializada en modo    */
    Envia_Com(comandoLCD4 & 0xf0);      /* de 4 bits.                         */
    Envia_Com((comandoLCD4 << 4) & 0xf0);
}

void Borra_Pant4b(void)                 /* Función para borrar pantalla en    */
{                                       /* modo de 4 bits.                    */
    Envia_Com4b(BP);
    retardo_ms(2);
}

void Retorno_Carro4b(void)              /* Función para realizar retorno de   */
{                                       /* en modo de 4 bits.                 */
    Envia_Com4b(RC);
    retardo_ms(2);
}

void Conf_Modo_Ent4b(unsigned int modo) /* Coloca la dirección de la DDRAM    */
{                                       /* se quiera incrementar o decrementar*/
    Envia_Com4b(CME | modo);            /* también especifica el salto del    */
    retardo_us(40);                     /* cursor durante una lectura o       */
}                                       /* escritura de datos.                */

void Enc_Apa4b(unsigned int interr)     /* Enciende y apaga la pantalla, el   */
{                                       /* el cursor, también sirve para      */
    Envia_Com4b(EAP | interr);          /* hacer parpadear el cursor en la    */
    retardo_us(40);                     /* posición actual.                   */
}

void Desp_Cur4b(unsigned int direc)     /* Mueve el cursor o desplaza la      */
{                                       /* pantalla sin cambiar el contenido  */
    Envia_Com4b(CDD | direc);           /* de la DDRAM.                       */
    retardo_us(40);
}

void Conf_Func4b(unsigned int funcion)  /* Configura la longitud del bus de   */
{                                       /* de datos, el número de líneas de la*/
    Envia_com4b(CF | funcion);          /* pantalla y la fuente de los        */
    retardo_us(40);                     /* caracteres.                        */
}

void Conf_CGRAM4b(unsigned int dirC)    /* Establece la dirección de la CGRAM */     
{                                       /* para poder enviar o recibr datos a */
    Envia_Com4b(ECGR | dirC);           /* esa dirección.                     */
    retardo_us(40);                     
}

void Conf_DDRAM4b(unsigned int dirD)    /* Establece la dirección de la DDRAM */
{                                       /* para poder enviar o recibir datos a*/
    Envia_Com4b(EDDR | dirD);           /* esa dirección.                     */
    retardo_us(40);
}

void Lee_BF4b(unsigned int dirB)        /* Lee la bandera de ocupado y también*/
{                                       /* lee el valor del contador de       */
    Envia_Com4b(LBFD | dirB);           /* direcciones.                       */
    retardo_us(5);
}

void Esc_DCRAM4b(unsigned int car)      /* Escribe dato a la DDRAM o CGRAM e  */
{                                       /* incrementa o decrementa el contador*/
    Envia_Com4b(EDCD | car);            /* de direcciones.                    */
    retardo_us(40);                    
}                                       

/* Debo seguir trabajando en las función Lee_DCRAM4b para retornar el dato    */

//Lee_DCRAM4b(unsigned int dat)           /* Lee dato de la DDRAM o CGRAM e     */
//{                                       /* incrementa o decrementa el contador*/
//    Envia_Com4b(LDCD | dat)             /* de direcciones.                    */
//    retardo_us(40);
//}

void Posicion_Cur4b(char fila, char columna)
{
    switch(fila)
    {
        case 1:
        {
            Envia_Com4b(EDDR | (lin_1_i + columna));
            break;  
        }
        case 2:
        {
            Envia_Com4b(EDDR | (lin_2_i + columna));
            break; 
        }
        case 3:
        {
            Envia_Com4b(EDDR | (lin_3_i + columna));
            break; 
        }
        case 4:
        {
            Envia_Com4b(EDDR | (lin_4_i + columna));
            break; 
        }
        default:
        {
            Envia_Com4b(EDDR | (lin_1_i + columna));
            break;  
        }
    }
}