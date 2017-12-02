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
#include "math.h"
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


#define BRD_D6_PIN						GPIO_PIN_15
#define BRD_D7_PIN						GPIO_PIN_2
#define BRD_D8_PIN						GPIO_PIN_3
#define BRD_D9_PIN						GPIO_PIN_18


#define D6_GPIO_PORT                     GPIOB
#define D7_GPIO_PORT                     GPIOF
#define D8_GPIO_PORT                     GPIOF
#define D9_GPIO_PORT                     GPIOA


#define D6_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOB_CLK_ENABLE()
#define D7_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOF_CLK_ENABLE()
#define D8_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOF_CLK_ENABLE()
#define D9_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOA_CLK_ENABLE()


#define D6_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOB_CLK_DISABLE()
#define D7_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOF_CLK_DISABLE()
#define D8_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOF_CLK_DISABLE()
#define D9_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOA_CLK_DISABLE()


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* ADC handle declaration */
ADC_HandleTypeDef AdcHandlex;
ADC_HandleTypeDef AdcHandley;
ADC_HandleTypeDef AdcHandle;

/* ADC channel configuration structure declaration */
ADC_ChannelConfTypeDef sConfig_a;
ADC_ChannelConfTypeDef sConfig_b;
ADC_ChannelConfTypeDef sConfig_c;
ADC_ChannelConfTypeDef sConfig_d;
ADC_ChannelConfTypeDef sConfig_e;
ADC_ChannelConfTypeDef sConfig_f;

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
	GPIO_InitTypeDef GPIO_InitStruct;
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


	/* Enable the GPIO clocks */

		/* GPIO pins as outputs */
		GPIO_InitStruct.Pin = BRD_D6_PIN;				//Pin
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;		//Output Mode
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;;			//Pin latency
		HAL_GPIO_Init(D6_GPIO_PORT, &GPIO_InitStruct);

		HAL_GPIO_WritePin(D6_GPIO_PORT, BRD_D6_PIN, 0x00);

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

	/* ### - 1a - Initialize ADC peripheral #################################### */
	AdcHandlex.Instance = ADCx;
	if (HAL_ADC_DeInit(&AdcHandlex) != HAL_OK) {
		/* ADC de-initialization Error */
		Error_Handler();
	}

	AdcHandlex.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2; /* Synchronous clock mode, input ADC clock divided by 2*/
	AdcHandlex.Init.Resolution = ADC_RESOLUTION_12B; /* 12-bit resolution for converted data */
	AdcHandlex.Init.DataAlign = ADC_DATAALIGN_RIGHT; /* Right-alignment for converted data */
	AdcHandlex.Init.ScanConvMode = DISABLE; /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
	AdcHandlex.Init.EOCSelection = ADC_EOC_SINGLE_CONV; /* EOC flag picked-up to indicate conversion end */
	AdcHandlex.Init.LowPowerAutoWait = DISABLE; /* Auto-delayed conversion feature disabled */
	AdcHandlex.Init.ContinuousConvMode = ENABLE; /* Continuous mode enabled (automatic conversion restart after each conversion) */
	AdcHandlex.Init.NbrOfConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandlex.Init.DiscontinuousConvMode = DISABLE; /* Parameter discarded because sequencer is disabled */
	AdcHandlex.Init.NbrOfDiscConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandlex.Init.ExternalTrigConv = ADC_SOFTWARE_START; /* Software start to trig the 1st conversion manually, without external event */
	AdcHandlex.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because software trigger chosen */
	AdcHandlex.Init.DMAContinuousRequests = ENABLE; /* ADC DMA continuous request to match with DMA circular mode */
	AdcHandlex.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN; /* DR register is overwritten with the last conversion result in case of overrun */
	/* Initialize ADC peripheral according to the passed parameters */
	if (HAL_ADC_Init(&AdcHandlex) != HAL_OK) {
		Error_Handler();
	}

	/* ### - 1b - Initialize ADC peripheral #################################### */
	AdcHandley.Instance = ADCx;
	if (HAL_ADC_DeInit(&AdcHandley) != HAL_OK) {
		/* ADC de-initialization Error */
		Error_Handler();
	}

	AdcHandley.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2; /* Synchronous clock mode, input ADC clock divided by 2*/
	AdcHandley.Init.Resolution = ADC_RESOLUTION_12B; /* 12-bit resolution for converted data */
	AdcHandley.Init.DataAlign = ADC_DATAALIGN_RIGHT; /* Right-alignment for converted data */
	AdcHandley.Init.ScanConvMode = DISABLE; /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
	AdcHandley.Init.EOCSelection = ADC_EOC_SINGLE_CONV; /* EOC flag picked-up to indicate conversion end */
	AdcHandley.Init.LowPowerAutoWait = DISABLE; /* Auto-delayed conversion feature disabled */
	AdcHandley.Init.ContinuousConvMode = ENABLE; /* Continuous mode enabled (automatic conversion restart after each conversion) */
	AdcHandley.Init.NbrOfConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandley.Init.DiscontinuousConvMode = DISABLE; /* Parameter discarded because sequencer is disabled */
	AdcHandley.Init.NbrOfDiscConversion = 1; /* Parameter discarded because sequencer is disabled */
	AdcHandley.Init.ExternalTrigConv = ADC_SOFTWARE_START; /* Software start to trig the 1st conversion manually, without external event */
	AdcHandley.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because software trigger chosen */
	AdcHandley.Init.DMAContinuousRequests = ENABLE; /* ADC DMA continuous request to match with DMA circular mode */
	AdcHandley.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN; /* DR register is overwritten with the last conversion result in case of overrun */
	/* Initialize ADC peripheral according to the passed parameters */
	if (HAL_ADC_Init(&AdcHandley) != HAL_OK) {
		Error_Handler();
	}

	/* ### - 2a - Start calibration ############################################ */
	if (HAL_ADCEx_Calibration_Start(&AdcHandlex, ADC_SINGLE_ENDED) != HAL_OK) {
		Error_Handler();
	}

	/* ### - 2b - Start calibration ############################################ */
	if (HAL_ADCEx_Calibration_Start(&AdcHandley, ADC_SINGLE_ENDED) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - a Channel configuration ######################################## */
	sConfig_a.Channel = ADC_CHANNEL_1; /* Sampled channel number */
	sConfig_a.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_a.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_a.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_a.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_a.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_a) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - b Channel configuration ######################################## */
	sConfig_b.Channel = ADC_CHANNEL_2; /* Sampled channel number */
	sConfig_b.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_b.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_b.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_b.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_b.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_b) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - c Channel configuration ######################################## */
	sConfig_c.Channel = ADC_CHANNEL_3; /* Sampled channel number */
	sConfig_c.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_c.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_c.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_c.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_c.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_c) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - d Channel configuration ######################################## */
	sConfig_d.Channel = ADC_CHANNEL_4; /* Sampled channel number */
	sConfig_d.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_d.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_d.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_d.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_d.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_d) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - e Channel configuration ######################################## */
	sConfig_e.Channel = ADC_CHANNEL_3; /* Sampled channel number */
	sConfig_e.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_e.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_e.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_e.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_e.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_e) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 3 - f Channel configuration ######################################## */
	sConfig_f.Channel = ADC_CHANNEL_4; /* Sampled channel number */
	sConfig_f.Rank = ADC_REGULAR_RANK_1; /* Rank of sampled channel number ADCx_left_CHANNEL */
	sConfig_f.SamplingTime = ADC_SAMPLETIME_61CYCLES_5; /* Sampling time (number of clock cycles unit) */
	sConfig_f.SingleDiff = ADC_SINGLE_ENDED; /* Single-ended input channel */
	sConfig_f.OffsetNumber = ADC_OFFSET_NONE; /* No offset subtraction */
	sConfig_f.Offset = 0; /* Parameter discarded because offset correction is disabled */
	if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_f) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 4 - Start conversion in DMA mode ################################# */
	if (HAL_ADC_Start(&AdcHandlex) != HAL_OK) {
		Error_Handler();
	}


	/* ### - 4 - Start conversion in DMA mode ################################# */
	//if (HAL_ADC_Start(&AdcHandlex) != HAL_OK) {
	//	Error_Handler();
	//}

	uint32_t ADCValue = 0;
	uint32_t last_ADCValue;
	uint32_t diff_ADCValue;
	uint32_t X_v;

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
			if (HAL_ADC_Stop(&AdcHandlex) != HAL_OK) {
				Error_Handler();
			}
			switch (flicker) {
			case 0:
				sprintf( confirmBuffer, ">>>A\n\r");
				flicker = 1;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_a) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			case 1:
				sprintf( confirmBuffer, ">>>B\n\r");
				flicker = 2;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_b) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			case 2:
				sprintf( confirmBuffer, ">>>C\n\r");
				flicker = 3;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_c) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			case 3:
				sprintf( confirmBuffer, ">>>D\n\r");
				flicker = 0;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_d) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			case 4:
				sprintf( confirmBuffer, ">>>E\n\r");
				flicker = 5;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_e) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			case 5:
				sprintf( confirmBuffer, ">>>F\n\r");
				flicker = 0;
				if (HAL_ADC_ConfigChannel(&AdcHandlex, &sConfig_f) != HAL_OK) {
					Error_Handler();
				}
				AdcHandle = AdcHandlex;
				break;
			}

			if (HAL_ADC_Start(&AdcHandlex) != HAL_OK) {
				Error_Handler();
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

			X_v = (1/ADCValue)*1732.1 - 22.448;
			X_v = ((1*1000000)/(sqrt(1000000*ADCValue))*1732.1 - 22.448*1000)/1000;

			sprintf( confirmBuffer, "Distance : %u mm\t\t(V:%u\tA:%u\tD:%u)\n\r", X_v, ADCValue, moving_average_val, diff_ADCValue);
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
