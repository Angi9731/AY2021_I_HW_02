/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include "InterruptRoutine.h"
#include "BlinkingSetting.h"


int main(void)
{
    CyGlobalIntEnable; 
    
    ISR_DEB_StartEx(BUTTON_ISR);
    Clock_DEB_Start(); //avvia il clock del debouncer (settato a 200Hz)
    Clock_PWM_Start(); //avvia il clock comune ai due PWM (settato a 128Hz per avere un periodo dell'onda quadra iniziale di 2s)
    pattern = 0; //inizializzo a zero all'accensione
    PWM_GREEN_Start(); //avvia PWM Green
    PWM_RED_Start(); //avvia PWM Red
    
    for(;;)
    {
        
        if(pattern == 1) //primo pattern
        {
           Set_Compare_Mode(1,1); // fronti di salita
           Write_Period(255,255); // periodo di 2s
           Write_Compare(0,0); // Duty Cycle 100%
           Write_Counter(); // resetto il counter 
        
           while(pattern == 1); // aspetto finchè non viene premuto nuovamente il pulsante
        }
        
        else if(pattern == 2) // secondo pattern
        {
           Write_Compare(127,0); // Duty Cycle del Green 50%, del Red 100%
           Write_Counter();
        
           while(pattern == 2); 
        }
        
        else if(pattern == 3) //terzo pattern
        {
           Set_Compare_Mode(1,3); // fronte di salita per il Green, discesa per il Red
           Write_Compare(0,127); // Duty Cycle del Green 100%, del Red 50%
           Write_Counter();
        
           while(pattern == 3);
        }
        
        else if(pattern == 4) //quarto pattern
        {
           Set_Compare_Mode(3,1); // fronte di discesa per il Green, di salita per il Red
           Write_Period(128,128); // periodo di 1s
           Write_Compare(64,64); // Duty Cycle del 50%
           Write_Counter();
        
           while(pattern == 4);
        }
        
        else if(pattern == 5) //quinto pattern
        {
           Set_Compare_Mode(1,3); // fronte di salita per il Green, discesa per il Red
           Write_Period(64,64); // periodo di 500 ms
           Write_Compare(32,32); //Duty Cycle del 50%
           Write_Counter();
        
           while(pattern == 5);   
        }
        
        else if(pattern == 6) //sesto pattern
        {
           Set_Compare_Mode(1,1); //fronti di salita
           Write_Period(255,255); //periodo di 2s
           Write_Compare(127,64); // Duty Cycle del Green 50%, del Red 75%
           Write_Counter();
        
           while(pattern == 6);   
        }
        
        else if(pattern == 7) //settimo pattern
        { 
           Set_Compare_Mode(1,3); // fronte di salita per il Green, discesa per il Red
           Write_Period(127,255); // periodo di 1s per il Green, 2s per il Red
           Write_Compare(64,127); // Duty Cycle del 50% per entrambi
           Write_Counter();
        
           while(pattern == 7);    
        }
        
        else if(pattern == 8) //se ho premuto ulteriormente il pulsante torno al primo pattern
        {
            pattern = 1;
            
        }
    }
}

/* [] END OF FILE */
