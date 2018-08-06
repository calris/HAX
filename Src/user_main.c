/*
 * HAX - Home Automation eXpansion
 * Copyright (C) 2018  Graeme Russ <gdr@goatjam.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stm32f4xx_hal.h"
#include "user_main.h"
#include "blink_led.h"
#include "visEffect.h"

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart6;
extern DMA_HandleTypeDef hdma_usart6_rx;
extern DMA_HandleTypeDef hdma_usart6_tx;

uint8_t dma_buffer[20] = {0};
uint8_t dma_buffer_ptr = 0;
volatile uint8_t toggle = 0;


void user_main(void)
{
        uint8_t in_usart6[10];
        uint8_t in_usart1[10];

        HAL_StatusTypeDef usart6_status;
        HAL_StatusTypeDef usart1_status;

        visHandle();

        usart1_status = HAL_UART_Receive(&huart1, in_usart1, 1, 100);
        usart6_status = HAL_UART_Receive(&huart6, in_usart6, 1, 100);

        if (usart1_status != HAL_TIMEOUT)
        {
                HAL_UART_Transmit(&huart6, in_usart1, 1, 100);
        }

        if (usart6_status != HAL_TIMEOUT)
        {
                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_SET);
                HAL_UART_Transmit(&huart1, in_usart6, 1, 100);
                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_RESET);
        }
}

void HAX_USART1_IRQHandler(UART_HandleTypeDef *huart)
{

}
