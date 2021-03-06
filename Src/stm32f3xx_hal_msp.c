/**
  ******************************************************************************
  * @file    UART/UART_TwoBoards_ComPolling/Src/stm32f3xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
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
#include "main.h"

#define USARTy_TX_PIN                    GPIO_PIN_2
#define USARTy_TX_GPIO_PORT              GPIOA
#define USARTy_TX_AF                     GPIO_AF7_USART2
#define USARTy_RX_PIN                    GPIO_PIN_3
#define USARTy_RX_GPIO_PORT              GPIOA
#define USARTy_RX_AF                     GPIO_AF7_USART2
#define USARTy_CLK_ENABLE()              __HAL_RCC_USART2_CLK_ENABLE()
#define USARTy_FORCE_RESET()             __HAL_RCC_USART2_FORCE_RESET()
#define USARTy_RELEASE_RESET()           __HAL_RCC_USART2_RELEASE_RESET()


/** @addtogroup STM32F3xx_HAL_Examples
  * @{
  */

/** @defgroup UART_TwoBoards_ComPolling
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	  GPIO_InitTypeDef  GPIO_InitStruct;
	  GPIO_InitTypeDef  GPIO_InitStructy;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO TX/RX clock */
  USARTx_TX_GPIO_CLK_ENABLE();
  USARTx_RX_GPIO_CLK_ENABLE();



  /* Enable USART clock */
  USARTx_CLK_ENABLE();
  USARTy_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = USARTx_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = USARTx_TX_AF;

  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Alternate = USARTx_RX_AF;

  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /*##-2- Configure peripheral GPIO y ##########################################*/
  /* UART TX GPIO pin configuration  */
  GPIO_InitStructy.Pin       = USARTy_TX_PIN;
  GPIO_InitStructy.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStructy.Pull      = GPIO_PULLUP;
  GPIO_InitStructy.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStructy.Alternate = USARTy_TX_AF;

  HAL_GPIO_Init(USARTy_TX_GPIO_PORT, &GPIO_InitStructy);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStructy.Pin = USARTy_RX_PIN;
  GPIO_InitStructy.Alternate = USARTy_RX_AF;

  HAL_GPIO_Init(USARTy_RX_GPIO_PORT, &GPIO_InitStructy);
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  /*##-1- Reset peripherals ##################################################*/
	  USARTx_FORCE_RESET();
	  USARTx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks #################################*/
  /* Configure USART1 Tx as alternate function  */
	  HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
	  HAL_GPIO_DeInit(USARTy_TX_GPIO_PORT, USARTy_TX_PIN);
  /* Configure USART1 Rx as alternate function  */
	  HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);
	  HAL_GPIO_DeInit(USARTy_RX_GPIO_PORT, USARTy_RX_PIN);
}


/**
* @brief  ADC MSP Init
* @param  hadc : ADC handle
* @retval None
*/
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
	GPIO_InitTypeDef          GPIO_InitStruct_l;
	GPIO_InitTypeDef          GPIO_InitStruct_r;


  static DMA_HandleTypeDef         DmaHandle;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO clock ****************************************/
  __HAL_RCC_GPIOA_CLK_ENABLE();
  /* ADC1 Periph clock enable */
  ADCx_CLK_ENABLE();
  /* Enable DMA1 clock */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /*##- 2- Configure peripheral GPIO #########################################*/
  /* ADC Channel GPIO pin configuration */
  GPIO_InitStruct_l.Pin = GPIO_PIN_5;
  GPIO_InitStruct_l.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct_l.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_l);

    GPIO_InitStruct_r.Pin = GPIO_PIN_4;
    GPIO_InitStruct_r.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct_r.Pull = GPIO_NOPULL;
      HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_r);
  /*##- 3- Configure DMA #####################################################*/

  /*********************** Configure DMA parameters ***************************/
  DmaHandle.Instance                 = DMA1_Channel2;
  DmaHandle.Init.Direction           = DMA_PERIPH_TO_MEMORY;
  DmaHandle.Init.PeriphInc           = DMA_PINC_DISABLE;
  DmaHandle.Init.MemInc              = DMA_MINC_ENABLE;
  DmaHandle.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  DmaHandle.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD;
  DmaHandle.Init.Mode                = DMA_CIRCULAR;
  DmaHandle.Init.Priority            = DMA_PRIORITY_MEDIUM;
  /* Deinitialize  & Initialize the DMA for new transfer */
  HAL_DMA_DeInit(&DmaHandle);
  HAL_DMA_Init(&DmaHandle);

  /* Associate the DMA handle */
  __HAL_LINKDMA(hadc, DMA_Handle, DmaHandle);

  /* NVIC configuration for DMA Input data interrupt */
  HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);
}

/**
  * @brief ADC MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{

  /*##-1- Reset peripherals ##################################################*/
  ADCx_FORCE_RESET();
  ADCx_RELEASE_RESET();
  /* ADC Periph clock disable
   (automatically reset all ADC instances of the ADC common group) */
  __HAL_RCC_ADC12_CLK_DISABLE();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the ADC Channel GPIO pin */
  HAL_GPIO_DeInit(ADCx_CHANNEL_GPIO_PORT, GPIO_PIN_5);
  HAL_GPIO_DeInit(ADCx_CHANNEL_GPIO_PORT, GPIO_PIN_4);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
