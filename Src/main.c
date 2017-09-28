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
#include "main.h"
#include "s4321966_hal admux_select.h"
#include "string.h"
#include "stdlib.h"
#include "stm32f3xx_hal_adc.h"
#include "stm32f3xx_hal_adc_ex.h"

/** @addtogroup STM32F3xx_HAL_Examples
 * @{
 */

/** @addtogroup UART_TwoBoards_ComPolling
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
//#define TRANSMITTER_BOARD
/* Definition of ADCx conversions data table size */
#define ADC_CONVERTED_DATA_BUFFER_SIZE   ((uint32_t)  32)   /* Size of array */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* ADC handle declaration */
ADC_HandleTypeDef AdcHandle;

/* ADC channel configuration structure declaration */
ADC_ChannelConfTypeDef sConfig_l;
ADC_ChannelConfTypeDef sConfig_r;

/* Variable containing ADC conversions data */
static uint16_t aADCx_leftConvertedData[ADC_CONVERTED_DATA_BUFFER_SIZE];
static uint16_t aADCx_rightConvertedData[ADC_CONVERTED_DATA_BUFFER_SIZE];
uint32_t moving_average_X( uint32_t*, int);
/* UART handler declaration */
UART_HandleTypeDef UartHandle;
__IO uint32_t VirtualUserButtonStatus = 0; /* set to 1 after User set a button  */

/* Buffer used for transmission */
uint8_t aTxBuffer[] = "                                                  \n\r";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void Error_Handler(void);
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2,
		uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {

	uint8_t* confirmBuffer = (uint8_t*) malloc (sizeof(uint8_t)*100);
	memset(confirmBuffer, 0, 100);
	int flicker = 0;
	int i = 0;
#ifdef TRANSMITTER_BOARD
	GPIO_InitTypeDef GPIO_InitStruct;
#endif
	/* STM32F3xx HAL library initialization:
	 - Configure the Flash prefetch
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the system clock to 64 MHz */
	SystemClock_Config();

	/* Configure LED3 */
	BSP_LED_Init(LED3);

	/*##-1- Configure the UART peripheral ######################################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART configured as follows:
	 - Word Length = 8 Bits
	 - Stop Bit = One Stop bit
	 - Parity = None
	 - BaudRate = 9600 baud
	 - Hardware flow control disabled (RTS and CTS signals) */
	UartHandle.Instance = USARTx;

	UartHandle.Init.BaudRate = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	if (HAL_UART_DeInit(&UartHandle) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_UART_Init(&UartHandle) != HAL_OK) {
		Error_Handler();
	}

	/* ### - 1 - Initialize ADC peripheral #################################### */
	AdcHandle.Instance = ADCx;
	if (HAL_ADC_DeInit(&AdcHandle) != HAL_OK) {
		/* ADC de-initialization Error */
		Error_Handler();
	}

	AdcHandle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2; /* Synchronous clock mode, input ADC clock divided by 2*/
	AdcHandle.Init.Resolution = ADC_RESOLUTION_12B; /* 12-bit resolution for converted data */
	AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT; /* Right-alignment for converted data */
	AdcHandle.Init.ScanConvMode = DISABLE; /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
	AdcHandle.Init.EOCSelection = ADC_EOC_SINGLE_CONV; /* EOC flag picked-up to indicate conversion end */
	AdcHandle.Init.LowPowerAutoWait = DISABLE; /* Auto-delayed conversion feature disabled */
	AdcHandle.Init.ContinuousConvMode = ENABLE; /* Continuous mode enabled (automatic conversion restart after each conversion) */
	AdcHandle.Init.NbrOfConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandle.Init.DiscontinuousConvMode = DISABLE; /* Parameter discarded because sequencer is disabled */
	AdcHandle.Init.NbrOfDiscConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandle.Init.ExternalTrigConv = ADC_SOFTWARE_START; /* Software start to trig the 1st conversion manually, without external event */
	AdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because software trigger chosen */
	AdcHandle.Init.DMAContinuousRequests = ENABLE; /* ADC DMA continuous request to match with DMA circular mode */
	AdcHandle.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN; /* DR register is overwritten with the last conversion result in case of overrun */
	/* Initialize ADC peripheral according to the passed parameters */
	if (HAL_ADC_Init(&AdcHandle) != HAL_OK) {
		Error_Handler();
	}

	/* ### - 2 - Start calibration ############################################ */
	if (HAL_ADCEx_Calibration_Start(&AdcHandle, ADC_SINGLE_ENDED) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - Left Channel configuration ######################################## */
	sConfig_l.Channel = ADC_CHANNEL_2; /* Sampled channel number */
	sConfig_l.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_l.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_l.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_l.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_l.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig_l) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - Right Channel configuration ######################################## */
	sConfig_r.Channel = ADC_CHANNEL_1; /* Sampled channel number */
	sConfig_r.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_r.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_r.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_r.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_r.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig_r) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 4 - Start conversion in DMA mode ################################# */
	if (HAL_ADC_Start(&AdcHandle) != HAL_OK) {
		Error_Handler();
	}

	uint32_t ADCValue = 0;
	uint32_t last_ADCValue;
	uint32_t diff_ADCValue;

	uint32_t moving_average_val;
	uint32_t* moving_average = (uint32_t*)malloc(sizeof(uint32_t) * 10);
	int number_measure = 0;
	int index_measure = 0;

	memset(confirmBuffer, 0, 100);

	sprintf( confirmBuffer, "********* BOOT COMPLETED *********\n\r");

	flicker = 0;
	while (1) {
		/*##-3- Start the transmission process #####################################*/
		/* While the UART in reception process, user can transmit data through
		 "aTxBuffer" buffer */
		BSP_LED_Toggle(LED3);
		HAL_Delay(100);
		if (HAL_UART_Transmit(&UartHandle, (uint8_t*) confirmBuffer, TXBUFFERSIZE,
				1000) != HAL_OK) {
			Error_Handler();
		}

		if (index_measure == 0) {
			memset(confirmBuffer, 0, 100);
			number_measure = 0;

			for(i = 0; i < 10; i++) {
				moving_average[i] = 0;
			}

			if (flicker == 0) {
				flicker = 1;
				sprintf( confirmBuffer, ">>>LEFT\n\r");

				if (HAL_ADC_Stop(&AdcHandle) != HAL_OK) {
					Error_Handler();
				}
				if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig_l) != HAL_OK) {
					Error_Handler();
				}
				if (HAL_ADC_Start(&AdcHandle) != HAL_OK) {
					Error_Handler();
				}

			} else {
				flicker = 0;
				sprintf( confirmBuffer, ">>>RIGHT\n\r");

				if (HAL_ADC_Stop(&AdcHandle) != HAL_OK) {
					Error_Handler();
				}
				if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig_r) != HAL_OK) {
					Error_Handler();
				}
				if (HAL_ADC_Start(&AdcHandle) != HAL_OK) {
					Error_Handler();
				}
			}

			if (HAL_UART_Transmit(&UartHandle, (uint8_t*) confirmBuffer, TXBUFFERSIZE,
					1000) != HAL_OK) {
				Error_Handler();
			}
		}

		if (HAL_ADC_PollForConversion(&AdcHandle, 1000000) == HAL_OK) {
			last_ADCValue = ADCValue;
			ADCValue = HAL_ADC_GetValue(&AdcHandle);

			moving_average[index_measure] = ADCValue;

			number_measure = number_measure + 1;
			index_measure = index_measure + 1;
			index_measure = index_measure % 10;
			if (number_measure > 10) {
				number_measure = 10;
			}

			if (last_ADCValue > ADCValue) {
				diff_ADCValue = last_ADCValue - ADCValue;
			} else {
				diff_ADCValue = ADCValue - last_ADCValue;
			}

			moving_average_val = moving_average_X(moving_average, number_measure);
			memset(confirmBuffer, 0, 100);

			sprintf( confirmBuffer, "V:%u\tA:%u\tD:%u\n\r", ADCValue, moving_average_val, diff_ADCValue);


		}

	}
}

uint32_t moving_average_X( uint32_t* moving_average, int X) {
	uint32_t moving_average_val = 0;

	int i = 0;

	for (i = 0; i < X; i++) {
		moving_average_val = moving_average[i] + moving_average_val;
	}
	moving_average_val = moving_average_val / X;
	return moving_average_val;


}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSI)
 *            SYSCLK(Hz)                     = 64000000
 *            HCLK(Hz)                       = 64000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 2
 *            APB2 Prescaler                 = 1
 *            PLLMUL                         = RCC_PLL_MUL16 (16)
 *            Flash Latency(WS)              = 2
 * @param  None
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* HSI Oscillator already ON after system reset, activate PLL with HSI as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		/* Initialization Error */
		while (1)
			;
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		/* Initialization Error */
		while (1)
			;
	}
}
/**
 * @brief  UART error callbacks
 * @param  UartHandle: UART handle
 * @note   This example shows a simple way to report transfer error, and you can
 *         add your own implementation.
 * @retval None
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *UartHandle) {
	Error_Handler();
}

/**
 * @brief EXTI line detection callbacks
 * @param GPIO_Pin: Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == GPIO_PIN_12) {
		VirtualUserButtonStatus = 1;
	}
}
/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param  BufferLength: buffer's length
 * @retval 0  : pBuffer1 identical to pBuffer2
 *         >0 : pBuffer1 differs from pBuffer2
 */
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2,
		uint16_t BufferLength) {
	while (BufferLength--) {
		if ((*pBuffer1) != *pBuffer2) {
			return BufferLength;
		}
		pBuffer1++;
		pBuffer2++;
	}

	return 0;
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* Turn LED3 on */
	BSP_LED_On(LED3);
	while (1) {
		/* Error if LED3 is slowly blinking (1 sec. period) */
		BSP_LED_Toggle(LED3);
		HAL_Delay(1000);
	}
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(char* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
