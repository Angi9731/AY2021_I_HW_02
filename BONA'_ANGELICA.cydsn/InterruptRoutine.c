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
// File source dell'interrupt in uscita al debouncer

#include "InterruptRoutine.h"

CY_ISR(BUTTON_ISR)
{ 
    pattern ++; //incremento il pattern ogni volta che il pulsante viene rilasciato
}
/* [] END OF FILE */
