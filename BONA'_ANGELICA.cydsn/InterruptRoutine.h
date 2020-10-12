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
// File header dell'interrupt in uscita al debouncer

#ifndef __INTERRUPT_ROUTINES_H
    
    #define __INTERRUPT_ROUTINES_H
    
    #include "project.h"
    
    CY_ISR_PROTO(BUTTON_ISR);
    
#endif

unsigned int pattern; //variabile globale che identifica i pattern luminosi

/* [] END OF FILE */
