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
           PWM_GREEN_SetCompareMode(1);
           PWM_RED_SetCompareMode(1);
           PWM_GREEN_WritePeriod(255); //periodo dell'onda quadra di 4s
           PWM_GREEN_WriteCompare(0);//Duty Cycle dell'onda quadra 50%
           PWM_RED_WritePeriod(255);
           PWM_RED_WriteCompare(0);
           PWM_RED_WriteCounter(0);
           PWM_GREEN_WriteCounter(0);
           while(pattern == 1);
        }
        else if(pattern == 2) //secondo pattern
        {
           PWM_RED_WriteCompare(0);
           PWM_GREEN_WriteCompare(127); 
           PWM_RED_WriteCounter(0);
           PWM_GREEN_WriteCounter(0);
           while(pattern == 2); 
        }
        
        else if(pattern == 3) //terzo pattern
        {
            
            PWM_RED_SetCompareMode(3); //setto come primo fronte un fronte di discesa
            PWM_GREEN_WriteCompare(0);
            PWM_RED_WriteCompare(127);
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
            while(pattern == 3);
        }
        
        else if(pattern == 4) //quarto pattern
        {
           
            
            PWM_GREEN_SetCompareMode(3);
            PWM_RED_SetCompareMode(1);
            PWM_GREEN_WritePeriod(128); //periodo dell'onda quadra di 1s
            PWM_GREEN_WriteCompare(64); //Duty Cycle dell'onda quadra 50%
            PWM_RED_WritePeriod(128);
            PWM_RED_WriteCompare(64);
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
            while(pattern == 4);
        }
        
        else if(pattern == 5) //quinto pattern
        {
            //CyDelay(50);
            
            PWM_GREEN_SetCompareMode(1);
            PWM_RED_SetCompareMode(3);
            PWM_GREEN_WritePeriod(64); //periodo dell'onda quadra 500ms
            PWM_GREEN_WriteCompare(32); //Duty Cycle dell'onda quadra 50%
            PWM_RED_WritePeriod(64);
            PWM_RED_WriteCompare(32);
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
            while(pattern == 5);
            
        }
        
        else if(pattern == 6) //sesto pattern
        {
            
            PWM_GREEN_SetCompareMode(1);
            PWM_RED_SetCompareMode(1);
            PWM_GREEN_WritePeriod(255);
            PWM_GREEN_WriteCompare(127);
            PWM_RED_WritePeriod(255);
            PWM_RED_WriteCompare(64); 
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
            while(pattern == 6);
            
        }
        
        else if(pattern == 7) //settimo pattern
        {
            //CyDelay(50);
            PWM_GREEN_SetCompareMode(1);
            PWM_RED_SetCompareMode(3);
            PWM_GREEN_WritePeriod(127);
            PWM_GREEN_WriteCompare(64);
            PWM_RED_WritePeriod(255);
            PWM_RED_WriteCompare(127);
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
            while(pattern == 7);
            
        }
        else if(pattern == 8) //se ho premuto ulteriormente il pulsante torno al primo pattern
        {
            pattern = 1;
            
        }
    }
}

/* [] END OF FILE */
