/* ###################################################################
**     Filename    : main.c
**     Project     : TWR-KV58F220M
**     Processor   : MKV58F1M0VLQ24
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-06-21, 15:40, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "FRTOS1.h"
#include "KSDK1.h"
#include "UTIL1.h"
#include "WAIT1.h"
#include "gpio1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
static void blinky_task(void *param) {
  (void)param;
  for(;;) {
    GPIO_DRV_TogglePinOutput(LED_RED);
    vTaskDelay(50/portTICK_RATE_MS);
    GPIO_DRV_TogglePinOutput(LED_RED);

    GPIO_DRV_TogglePinOutput(LED_GREEN);
    vTaskDelay(50/portTICK_RATE_MS);
    GPIO_DRV_TogglePinOutput(LED_RED);

    GPIO_DRV_TogglePinOutput(LED_ORANGE);
    vTaskDelay(50/portTICK_RATE_MS);
    GPIO_DRV_TogglePinOutput(LED_ORANGE);

    GPIO_DRV_TogglePinOutput(LED_BLUE);
    vTaskDelay(50/portTICK_RATE_MS);
    GPIO_DRV_TogglePinOutput(LED_BLUE);
  } /* for */
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  if (xTaskCreate(
      blinky_task,  /* task function */
      "Blinky", /* task name for kernel awareness */
      configMINIMAL_STACK_SIZE, /* task stack size */
      (void*)NULL, /* optional task startup argument */
      tskIDLE_PRIORITY,  /* initial priority */
      NULL /* task handle */
    ) != pdPASS) {
    for(;;){} /* error! probably out of memory */
  }
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/