#include "io430.h"
#define MOTOR_2 BIT4 //ENTRADA 1
#define MOTOR_2 BIT5 //ENTRADA 2
#define MOTOR_2 BIT6 //ENTRADA 3
#define MOTOR_2 BIT7 //ENTRADA 4
#define MOTOR_1 BIT3 //SALIDA 1
#define MOTOR_1 BIT2 //SALIDA 2
#define MOTOR_1 BIT1 //SALIDA 3
#define MOTOR_1 BIT0 //SALIDA 4
#define M1_ENABLE 0x20
#define M1_2 0x08
#define M1_1 0x80


int columna=0, renglon=0, ,teclas=0,mascara=0;

int main( void ){
// Stop watchdog timer to prevent time out reset
WDTCTL = WDTPW + WDTHOLD;
  
P1DIR |= BIT4; //Declaras las salidas en el puerto 1
P1DIR |= BIT5;
P1DIR |= BIT6;
P1DIR |= BIT7;

P2DIR &=~ BIT0;//Declaras las entradas en el puerto 1
P2DIR &=~ BIT1;
P2DIR &=~ BIT2;
P2DIR &=~ BIT3;

P1REN |= BIT4;//Declaras resistencias
P2REN |= BIT5;
P2REN |= BIT6;
P2REN |= BIT7;

P2OUT |= BIT0;//Declaras resistencias de pull_up
P2OUT |= BIT1;
P2OUT |= BIT2;
P2OUT |= BIT3;

P1SEL = 0;
P2SEL = 0;

while(1){
P1OUT = 0X08;
for(columna=0;columna<4;columna++){
    mascara=0x01;
    for(renglon=0;renglon<4;renglon++){
      if((P2IN&mascara)==mascara){
        __delay__cycles(120000);
        teclas=columna*4+renglon;
        __delay__cycles(120000);
      }
      mascara=mascara<<1;
    }
    P1OUT=P1OUT<<1;
}
}

}
