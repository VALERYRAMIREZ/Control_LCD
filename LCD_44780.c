#include "LCD_44780.h"
#include "temporizadores.h"

/* Definición de funciones para el control de la pantalla LCD. */

void Inicia_LCD4(unsigned short dato)       /* función para inicializar la    */
{                                           /* pantalla LCD.                  */
    retardo_ms(16);                         /* Inicialización y espera.       */
    E = 0; 
    retardo_us(5);
    E = 1;
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_ms(10);

    E = 1;
    retardo_us(5);    
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);

    E = 1; 
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);

    E = 1; 
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);

    E = 1;   
    retardo_us(5); 
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    retardo_us(5);
    E = 0;  
    
    retardo_ms(100);                        /* Número de líneas y tipo de     */
                                            /* fuente.      */
    E = 1;
    retardo_us(5);
    RS = 0;
    RW = 0;
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                        /* Se apaga el LCD.               */

    E = 1;  
    retardo_us(5);  
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                  

    E = 1; 
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    retardo_us(5);
    E = 0;

    retardo_us(100);                        /* Se enciende el LCD.            */

    E = 1; 
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                  

    E = 1;       
    retardo_us(5); 
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                        /* Configuración del modo de
                                             *  entrada.                      */
    E = 1; 
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                  

    E = 1;     
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;                             /* Cursor encendido.                  */
    D6 = 0;                    
    D5 = 1;                             /* Incremento del cursor.             */
    D4 = 1;                             /* Desplazamiento del display al      */
    retardo_us(5);                      /* aparecer la data.                  */
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