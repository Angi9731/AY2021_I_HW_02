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
/* Ho supposto che il primo pattern 
sia un'onda quadra di periodo 4s 
e che un fronte di salita 
corrisponda all'accensione del led, 
non allo stato logico presente sul pin.*/
#include "project.h"
#include "GlobalVariables.h"
#include "InterruptRoutine.h"

#define HIGH 1
#define LOW 0
#define LED_OFF LOW
#define LED_ON HIGH

int main(void)
{
    CyGlobalIntEnable; 
    pattern = 0; //inizializzo a zero all'accensione
    Clock_DEB_Start();
    ISR_DEB_StartEx(BUTTON_ISR);
    
    PWM_GREEN_SetCompareMode(2); //setto come primo fronte un fronte di salita
    PWM_RED_SetCompareMode(2);
    
    Clock_PWM_Start();
    
    PWM_GREEN_Start();
    PWM_RED_Start();

    for(;;)
    {
        
        if(pattern == 1) //primo pattern
        {
           CyDelay(50);
           PWM_GREEN_SetCompareMode(2);
           PWM_RED_SetCompareMode(2);
           PWM_GREEN_WritePeriod(255); //periodo dell'onda quadra di 4s
           PWM_GREEN_WriteCompare(127);//Duty Cycle dell'onda quadra 50%
           PWM_RED_WritePeriod(255);
           PWM_RED_WriteCompare(127); 
        }
        if(pattern == 2) //secondo pattern
        {
           CyDelay(50);
           PWM_GREEN_SetCompareMode(2);
           PWM_RED_SetCompareMode(2);
           PWM_GREEN_WritePeriod(127); //periodo dell'onda quadra di 2s
           PWM_GREEN_WriteCompare(63); //Duty Cycle dell'onda quadra 50%
            
        }
        
        else if(pattern == 3) //terzo pattern
        {
            CyDelay(50);
            PWM_GREEN_SetCompareMode(2);
            PWM_RED_SetCompareMode(4); //setto come primo fronte un fronte di discesa
            PWM_GREEN_WritePeriod(255);
            PWM_GREEN_WriteCompare(127);
            PWM_RED_WritePeriod(127);
            PWM_RED_WriteCompare(63);
            
        }
        
        else if(pattern == 4) //quarto pattern
        {
            CyDelay(50);
            PWM_GREEN_SetCompareMode(4);
            PWM_RED_SetCompareMode(2);
            PWM_GREEN_WritePeriod(63); //periodo dell'onda quadra di 1s
            PWM_GREEN_WriteCompare(31); //Duty Cycle dell'onda quadra 50%
            PWM_RED_WritePeriod(63);
            PWM_RED_WriteCompare(31);
            
        }
        
        else if(pattern == 5) //quinto pattern
        {
            CyDelay(50);
            PWM_GREEN_SetCompareMode(2);
            PWM_RED_SetCompareMode(4);
            PWM_GREEN_WritePeriod(31); //periodo dell'onda quadra 500ms
            PWM_GREEN_WriteCompare(15); //Duty Cycle dell'onda quadra 50%
            PWM_RED_WritePeriod(31);
            PWM_RED_WriteCompare(15);
            
        }
        
        else if(pattern == 6) //sesto pattern
        {
            CyDelay(50);
            PWM_GREEN_SetCompareMode(2);
            PWM_RED_SetCompareMode(2);
            PWM_GREEN_WritePeriod(127);
            PWM_GREEN_WriteCompare(63);
            PWM_RED_WritePeriod(127);
            PWM_RED_WriteCompare(31); //Duty Cycle dell'onda quadra 75%
            
        }
        
        else if(pattern == 7) //settimo pattern
        {
           CyDelay(50);
            PWM_GREEN_SetCompareMode(2);
            PWM_RED_SetCompareMode(4);
            PWM_GREEN_WritePeriod(63);
            PWM_GREEN_WriteCompare(31);
            PWM_RED_WritePeriod(127);
            PWM_RED_WriteCompare(63);
            
        }
    }
}

/* [] END OF FILE */
