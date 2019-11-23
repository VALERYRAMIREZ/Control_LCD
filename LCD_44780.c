#include "LCD_44780.h"
#include "temporizadores.h"

/* Definición de funciones para el control de la pantalla LCD. */

void Inicia_LCD4(unsigned short dato)       /* Función para inicializar la    */
{                                           /* pantalla LCD.                  */
    PORTD = 0;
    
    retardo_ms(16);
                                     
    E = 1;
    PORTD = 0x30 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_ms(10);
    
    E = 1;
    PORTD = 0x30 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x30 | 0x100;
    retardo_us(5);
    E = 0;

    retardo_us(100);
    
    E = 1;
    PORTD = 0x20 | 0x100;
    retardo_us(5);
    E = 0;

    retardo_us(100);
    
    E = 1;
    PORTD = 0x02 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x08 | 0x100;
    retardo_us(5);
    E = 0;    
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x20 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x80 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x00 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x60 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x00 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0xe0 | 0x100;
    retardo_us(5);
    E = 0;

    retardo_us(100);
    
    E = 1;
    PORTD = 0x00 | 0x100;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);
    
    E = 1;
    PORTD = 0x10 | 0x100;
    retardo_us(5);
    E = 0;
}

void Desplaza_Cur(char dir, char salto)
{
    retardo_us(100);                        /* Desplazamiento del cursor hacia*/
                                            /* una dirección: dir = i = i el  */
    RS = 0;                                 /* dir = i, cursor se mueve a la  */
    RW = 0;                                 /*          izquierda.            */
    retardo_us(1);                          /* dir = d, cursor se mueve a la  */
    E = 1;                                  /*          derecha.              */
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(1);
    E = 0;
    
    retardo_us(100);                  
    
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
    D7 = 0;                             /* Cursor encendido.                  */
    D6 = 1;                    
    D5 = salto;                         /* Incremento del cursor.             */
    D4 = dir;                           /* Desplazamiento del display al      */
    retardo_us(1);                      /* aparecer la data.                  */
    E = 0;
}