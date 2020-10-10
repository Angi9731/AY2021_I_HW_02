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
#include "InterruptRoutine.h"
#include "GlobalVariables.h"

CY_ISR(BUTTON_ISR)
{ 
    pattern ++; //incremento il pattern
    if(pattern == 8) //se ho premuto ulteriormente il pulsante torno al primo pattern
    {
        pattern = 1;
    }
}
/* [] END OF FILE */
