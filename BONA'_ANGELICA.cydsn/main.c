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
    Clock_DEB_Start();
    Clock_PWM_Start();
    pattern = 0; //inizializzo a zero all'accensione
    PWM_GREEN_Start();
    PWM_RED_Start();
    
    for(;;)
    {
        
        if(pattern == 1) //primo pattern
        {
          
           Set_Compare_Mode(1,1);
           Write_Period(255,255);
           Write_Compare(0,0);
           Write_Counter();
           while(pattern == 1);
        }
        else if(pattern == 2) //secondo pattern
        {
           
           Write_Compare(127,0);
           Write_Counter();
           while(pattern == 2); 
        }
        
        else if(pattern == 3) //terzo pattern
        {
            
            
            Set_Compare_Mode(1,3);
            Write_Compare(0,127);
            Write_Counter();
            while(pattern == 3);
        }
        
        else if(pattern == 4) //quarto pattern
        {
           
            
            
            Set_Compare_Mode(3,1);
            Write_Period(128,128);
            Write_Compare(64,64);
            Write_Counter();
            while(pattern == 4);
        }
        
        else if(pattern == 5) //quinto pattern
        {
            
            
            
            Set_Compare_Mode(1,3);
            Write_Period(64,64);
            Write_Compare(32,32);
            Write_Counter();
            while(pattern == 5);
            
        }
        
        else if(pattern == 6) //sesto pattern
        {
            
            
            Set_Compare_Mode(1,1);
            Write_Period(255,255);
            Write_Compare(127,64);
            Write_Counter();
            while(pattern == 6);
            
        }
        
        else if(pattern == 7) //settimo pattern
        {
            
            
            Set_Compare_Mode(1,3);
            Write_Period(127,255);
            Write_Compare(64,127);
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
