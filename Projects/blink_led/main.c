/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    13-October-2021
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2014 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F0xx_StdPeriph_Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

GPIO_InitTypeDef GPIOA_Init;

void Delay(__IO uint32_t nTime)
{
  while (nTime--)
    ;
}

void delay_ms(uint32_t time_ms)
{
  Delay(time_ms * 1000);
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIOA_Init.GPIO_Pin = GPIO_Pin_4;
  GPIOA_Init.GPIO_Mode = GPIO_Mode_OUT;
  GPIOA_Init.GPIO_OType = GPIO_OType_PP;
  GPIOA_Init.GPIO_Speed = GPIO_Speed_50MHz;
  GPIOA_Init.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIOA_Init);
	
  /* Infinite loop */
  while (1)
  {
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, 1);
		delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, 0);
		delay_ms(500);
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
void assert_failed(uint8_t* file, uint32_t line)
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


