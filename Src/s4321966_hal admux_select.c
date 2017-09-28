/**
 ******************************************************************************
 * @file    UART/UART_TwoBoards_ComPolling/Src/main.c
 * @author  MCD Application Team
 * @brief   This sample code shows how to use UART HAL API to transmit
 *          and receive a data buffer with a communication process based on
 *          polling transfer.
 *          The communication is done using 2 Boards.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "s4321966_hal admux_select.h"
#include "stm32f4xx_hal_conf.h"


/**
  * @brief  Initialise LEDBar.
  * @param  None
  * @retval None
  */
extern void s4322929_hal_ledbar_init(void) {
	GPIO_InitTypeDef  GPIO_InitStructure;
	BRD_LEDInit();		//Initialise Blue LED
	BRD_LEDOff();		//Turn off Blue LED

	/* Enable the GPIO clocks */
  	__BRD_D5_GPIO_CLK();
  	__BRD_D6_GPIO_CLK();
	__BRD_D7_GPIO_CLK();
	__BRD_D8_GPIO_CLK();

	/* GPIO pins as outputs */
	GPIO_InitStructure.Pin = BRD_D5_PIN;				//Pin
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;		//Output Mode
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;			//Pin latency
	HAL_GPIO_Init(BRD_D6_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = BRD_D6_PIN;				//Pin
	HAL_GPIO_Init(BRD_D7_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = BRD_D7_PIN;				//Pin
	HAL_GPIO_Init(BRD_D7_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = BRD_D8_PIN;				//Pin
	HAL_GPIO_Init(BRD_D5_GPIO_PORT, &GPIO_InitStructure);
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
