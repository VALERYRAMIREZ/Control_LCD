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

void Posicion_Cur4b(char fila, char columna)
{
    switch(fila)
    {
        case 1:
        {
            Envia_Com4b(EDDR | lin_1_i);
            break;  
        }
        case 2:
        {
            Envia_Com4b(EDDR | lin_2_i);
            break; 
        }
        case 3:
        {
            Envia_Com4b(EDDR | lin_3_i);
            break; 
        }
        case 4:
        {
            Envia_Com4b(EDDR | lin_4_i);
            break; 
        }
        default:
        {
            Envia_Com4b(EDDR | lin_1_i);
            break;  
        }
    }
}