#include "LCD_44780.h"
#include "temporizadores.h"

/* Definici�n de funciones para el control de la pantalla LCD. */

void Inicia_LCD4(unsigned short dato)       /* funci�n para inicializar la    */
{                                           /* pantalla LCD.                  */
    retardo_ms(16);                         /* Inicializaci�n y espera.       */
    
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(1);
    E = 0;
    
    retardo_ms(10);
    
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
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
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    retardo_us(1);
    E = 0;  
    
    retardo_ms(100);                        /* N�mero de l�neas y tipo de     */
                                            /* fuente.      */
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    retardo_us(1);
    E = 0;
    
    retardo_us(100);                        /* Se apaga el LCD.               */
    
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
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
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    retardo_us(1);
    E = 0;

    retardo_us(100);                        /* Se enciende el LCD.            */
    
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
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
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 1;
    retardo_us(1);
    E = 0;
    
    retardo_us(100);                        /* Configuraci�n del modo de
                                             *  entrada.                      */
    RS = 0;
    RW = 0;
    retardo_us(1);
    E = 1;
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
    D7 = 1;                             /* Cursor encendido.                  */
    D6 = 0;                    
    D5 = 1;                             /* Incremento del cursor.             */
    D4 = 1;                             /* Desplazamiento del display al      */
    retardo_us(1);                      /* aparecer la data.                  */
    E = 0;
}