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
// File header Blinking Setting contiene le dichiarazioni delle funzioni create per settare i paramentri dei PWM

#ifndef __BLINKING_SETTING_H
    #define __BLINKING_SETTING_H
    
        #include "project.h"
        
        //Per le seguenti 3 funzioni value1 = valore GREEN, value2 = valore RED
    
        void Set_Compare_Mode(unsigned int value1, unsigned int value2); //setta il primo fronte dell'onda quadra come fronte di salita o discesa
        
        void Write_Period(unsigned int value1,unsigned int value2); //setta il periodo dell'onda quadra 
       
        void Write_Compare(unsigned int value1, unsigned int value2); //setta il Duty Cycle dell'onda quadra
           
        void Write_Counter(void); //resetta i counters dei PWM
           
#endif
/* [] END OF FILE */
