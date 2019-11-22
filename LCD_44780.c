#include "LCD_44780.h"
#include "temporizadores.h"

/* Definici�n de funciones para el control de la pantalla LCD. */

void Inicia_LCD4(unsigned short dato)       /* funci�n para inicializar la    */
{                                           /* pantalla LCD.                  */
    retardo_ms(16);                         /* Inicializaci�n y espera.       */
    
    E = 0;                                  /* Escribo 03h (1/4)              */
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

    E = 1;                                  /* Escribo 03h (2/4)              */
    retardo_us(5);                           
    RS = 0;
    RW = 0;
    D7 = 1;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);

    E = 1;                                  /* Escribo 03h (3/4)              */
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

    E = 1;                                  /* Escribo 03h (4/4)              */
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

    E = 1;                                  /* N�mero de l�neas y tipo de     */
    retardo_us(5);                          /* fuente.                        */
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    retardo_us(5);
    E = 0;  
    
    retardo_ms(100);                        
                                            
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
    
    retardo_us(100);                       

    E = 1;                                 /* Se apaga el LCD.               */
    retardo_us(5);  
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
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

    retardo_us(100);                        

    E = 1;                                  /* Se enciende el LCD.            */
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
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
    
    retardo_us(100);                       
                                             
    E = 1;                                  /* Configuraci�n del modo de      */
    retardo_us(5);                          /*  entrada.                      */
    RS = 0;
    RW = 0;
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    retardo_us(5);
    E = 0;
    
    retardo_us(100);                  

    E = 1;     
    retardo_us(5);   
    RS = 0;
    RW = 0;
    D7 = 0;                             /* Cursor encendido.                  */
    D6 = 1;                    
    D5 = 1;                             /* Incremento del cursor.             */
    D4 = 1;                             /* Desplazamiento del display al      */
    retardo_us(5);                      /* aparecer la data.                  */
    E = 0;
}

void Desplaza_Cur(char dir, char salto)
{
    retardo_us(100);                        /* Desplazamiento del cursor hacia*/
                                            /* una direcci�n: dir = i = i el  */
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