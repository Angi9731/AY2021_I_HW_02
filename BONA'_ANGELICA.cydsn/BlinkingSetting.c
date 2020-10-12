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
// File source Blinking Setting contiene il corpo delle funzioni create per settare i parametri dei PWM

#include "BlinkingSetting.h"
#include "project.h"

        void Set_Compare_Mode(unsigned int value1, unsigned int value2)
        {
            PWM_GREEN_SetCompareMode(value1);
            PWM_RED_SetCompareMode(value2);
        }
        
        void Write_Period(unsigned int value1,unsigned int value2) 
        {
            PWM_GREEN_WritePeriod(value1);
            PWM_RED_WritePeriod(value2);
        }
       
        void Write_Compare(unsigned int value1, unsigned int value2)
        {
            PWM_GREEN_WriteCompare(value1);
            PWM_RED_WriteCompare(value2);
        }
           
        void Write_Counter(void) 
        {
            PWM_RED_WriteCounter(0);
            PWM_GREEN_WriteCounter(0);
        }

/* [] END OF FILE */
