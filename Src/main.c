/**
  ******************************************************************************
  * @file    Templates/Src/main.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    26-June-2014
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
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
#include "stm32f4xx_hal.h"

#include "stm324xg_eval_io.h"
#include "stm324xg_eval_lcd.h"

#include "main.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define REFRESH_RATE 30

#define MARGIN_TOP 50
#define MARGIN_BOTTOM 10
#define MARGIN_LEFT 10
#define MARGIN_RIGHT 10

#define BACK_COLOR LCD_COLOR_BLACK
#define TEXT_COLOR LCD_COLOR_LIGHTGREEN
#define BLOCK_COLOR LCD_COLOR_LIGHTRED
#define BLOCK_SIZE 10
#define BLOCK_SPEED 2


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

uint16_t x, y, xsize, ysize;
uint8_t joyStatus = 0;
JOYState_TypeDef direction = JOY_NONE;


/* Private function prototypes -----------------------------------------------*/

static void SystemClock_Config(void);
static void Error_Handler(void);


/* Private functions ---------------------------------------------------------*/

void drawBlock(uint16_t x, uint16_t y, uint16_t colour)
{
  for (uint16_t xx = x; xx < x + BLOCK_SIZE; xx++)
  {
    for (uint16_t yy = y; yy < y + BLOCK_SIZE; yy++)
    {
      BSP_LCD_DrawPixel(xx % xsize + MARGIN_LEFT, yy % ysize + MARGIN_TOP, colour);
    }
  }
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  HAL_Init();

  /* Configure the System clock to have a frequency of 168 MHz */
  SystemClock_Config();

  // set the HAL systick rate
  HAL_SYSTICK_Config(SystemCoreClock / REFRESH_RATE);


  // initialize screen
  BSP_LCD_Init();
  BSP_LCD_SetBackColor(BACK_COLOR);
  BSP_LCD_SetTextColor(TEXT_COLOR);
  BSP_LCD_SetFont(&NesFont8);

  BSP_LCD_Clear(BACK_COLOR);
  BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)"Testing!", CENTER_MODE);

  // initialize joystick and display message
  if (BSP_JOY_Init(JOY_MODE_GPIO) != IO_OK)
  {
    BSP_LCD_DisplayStringAt(0, LINE(2), (uint8_t *)(joyStatus == IO_ERROR ? "ERROR" : "TIMEOUT"), CENTER_MODE);
    BSP_LCD_DisplayStringAt(0, LINE(3), (uint8_t *)"Joystick cannot be initialized", CENTER_MODE);
  }
  else joyStatus = 1;

  // initialize block drawing
  xsize = BSP_LCD_GetXSize() - MARGIN_LEFT - MARGIN_RIGHT;
  ysize = BSP_LCD_GetYSize() - MARGIN_TOP - MARGIN_BOTTOM;
  x = (xsize - BLOCK_SIZE) / 2;
  y = (ysize - BLOCK_SIZE) / 2;
  drawBlock(x, y, BLOCK_COLOR);

  while (1)
  {
    if (joyStatus)
    {
      uint8_t *dirString = 0;

      // get and store joystick state
      JOYState_TypeDef JoyState = BSP_JOY_GetState();
      if (JoyState != JOY_NONE && JoyState != direction)
      {
        direction = JoyState;

        // display message
        switch(direction)
        {
        case JOY_UP:
          dirString = (uint8_t *)"UP";
          break;
        case JOY_DOWN:
          dirString = (uint8_t *)"DOWN";
          break;
        case JOY_LEFT:
          dirString = (uint8_t *)"LEFT";
          break;
        case JOY_RIGHT:
          dirString = (uint8_t *)"RIGHT";
          break;
        case JOY_SEL:
          dirString = (uint8_t *)"STOP";
          break;
        default:
          break;
        }
        BSP_LCD_ClearStringLine(3);
        BSP_LCD_DisplayStringAt(0, LINE(3), dirString, CENTER_MODE);
      }
    }
  }
}

void HAL_SYSTICK_Callback()
{
  if (direction != JOY_NONE && direction != JOY_SEL)
  {
    // erase block, update direction, redraw block
    drawBlock(x, y, LCD_COLOR_BLACK);
    switch(direction)
    {
    case JOY_UP:
      y = (y - BLOCK_SPEED + ysize) % ysize;
      break;
    case JOY_DOWN:
      y = (y + BLOCK_SPEED) % ysize;
      break;
    case JOY_LEFT:
      x = (x - BLOCK_SPEED + xsize) % xsize;
      break;
    case JOY_RIGHT:
      x = (x + BLOCK_SPEED) % xsize;
      break;
    default:
      break;
    }
    drawBlock(x, y, BLOCK_COLOR);
  }
}

static void Error_Handler(void)
{
  while(1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
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

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
