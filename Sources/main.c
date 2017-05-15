#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "SCI.h"
#include "StringUtils.h"

#define KP  10000   //KP*100000 KP=0.115 11500
#define KI  41000 //*1000	KI=49.1 49100
#define KD  1  //*100000	KD=.00001 1
#define RPM_IN	100

u16 dutyCycle;
u16 RPM;
u32 t0;
u16 t1;
u16 t2;
u32 T;
char string[6];
char string2[6];
u8 counts;
u16 pos;
bool mode;
u8 countsSCI;

i16    error_anterior;
i16    error_actual;
i32   acumulador;//efecto integral
i16    derivativo;
u32 Q;

interrupt VectorNumber_Vtpmch0 void CH0_ISR(void)
{
	(void) TPMC0SC;
	 TPMC0SC_CH0F=0;	 
	 t2=t1;
	 t1=TPMCNT;
	 t0=t1-t2;
	 counts=++counts%17;

	 
}

interrupt VectorNumber_Vtpmch1 void CH1_ISR(void)
{
   (void) TPMC1SC;
   TPMC1SC_CH1F=0;
   
   if(TPMC1SC_ELS1A==1)
   {
      TPMC1V+=((unsigned int)dutyCycle);
      T+=(1000-(unsigned int)dutyCycle);
      TPMC1SC=0b01011000; //CLEAR
   }
   else
   {
      TPMC1V+=(1000-(unsigned int)dutyCycle);
      T+=((unsigned int)dutyCycle);
      TPMC1SC=0b01011100; //SET
   }
}




void main(void) {
  EnableInterrupts;
  /* include your code here */
  SCI_InitTx();

  t0=0;
  t1=0;
  t2=0;
  T=0;
  error_actual=0;
  error_anterior=0;
  acumulador=0;
  derivativo=0;
  Q=0;
  countsSCI=0;
  
  PTBDD_PTBDD5=1; //configurar el pin como salida, inicia en 0
  dutyCycle=100;
  
  TPMSC=0b00001010;  //configurar clock
  TPMC1SC=0b01011100;
  TPMC1V=(1000-(unsigned int)dutyCycle);
  
  TPMC0SC=0x44;
  

  
  
  for(;;) {
    __RESET_WATCHDOG();	/* feeds the dog */
    
    
    if(T>=10000)
	{	
    	countsSCI++;
    	error_actual=(i8)(RPM_IN-RPM);
		acumulador+=error_actual;//*100
		derivativo=error_actual-error_anterior;
		Q=KP*(i16)error_actual;
		Q+=KI*acumulador;
		Q+=KD*(i16)derivativo;
		//Q/=1000000;
		Q>>=22;
		if(Q<100)
		{
			Q=100;
		}
		else if(Q>900)
		{
			Q=900;
		}
		dutyCycle=(u16)Q;
		error_anterior=error_actual;
    	if(!SCI_TxIsBusy() && (countsSCI>25))
    	{
    		countsSCI=0;
    		if(mode){
				mode=0;
				string2[0]='0';
				string2[1]='0';
				string2[2]='0';
				string2[3]='g';
				string2[4]='\r';
				string2[5]='\n';
				StringUtils_Num2Str(pos,3,string2);
				SCI_SendMessage(string2,6);
			}
			else{
				mode=1;
				string[0]='0';
				string[1]='0';
				string[2]='0';
				string[3]='0';
				string[4]=' ';
				string[5]=' ';
				StringUtils_Num2Str(RPM,4,string);
				SCI_SendMessage(string,6); 
			}
    	}
    	
		T=0;
		
	}
    RPM=(u16)(75000/t0);
    pos=(225*counts)/10;
    
  } /* loop forever */
  /* please make sure that you never leave main */
}
