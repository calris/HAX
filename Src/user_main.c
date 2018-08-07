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
#include <string.h>

#include "stm32f4xx_hal.h"
#include "user_main.h"
#include "blink_led.h"
#include "visEffect.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;

struct led_data led_2;
struct led_data led_3;
struct led_data led_4;

UART_HandleTypeDef *debug_uart(void)
{
        return &huart6;
}

UART_HandleTypeDef *rs485_uart(void)
{
        return &huart1;
}

#define BUFFER_SIZE     1

uint8_t debug_rx_buffer[BUFFER_SIZE];
uint8_t debug_tx_buffer[BUFFER_SIZE];

uint8_t rs485_rx_buffer[BUFFER_SIZE];
uint8_t rs485_tx_buffer[BUFFER_SIZE];

void user_code_1(void)
{
}

void user_code_init(void)
{
        led_2.GPIOx = LED2_GPIO_Port;
        led_2.GPIO_Pin = LED2_Pin;

        led_3.GPIOx = LED3_GPIO_Port;
        led_3.GPIO_Pin = LED3_Pin;

        led_4.GPIOx = LED4_GPIO_Port;
        led_4.GPIO_Pin = LED4_Pin;
}

void user_code_sysinit(void)
{
}

void user_code_2(void)
{
        HAL_UART_Receive_IT(debug_uart(), debug_rx_buffer, BUFFER_SIZE);

        HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_RESET);
        HAL_UART_Receive_DMA(rs485_uart(), rs485_rx_buffer, BUFFER_SIZE);
        visInit();
}

static void rs485_tx(uint8_t *tx_buffer, uint16_t len)
{
        HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_SET);
        HAL_UART_Transmit_DMA(rs485_uart(), tx_buffer, len);
}

static void debug_tx(uint8_t *tx_buffer, uint16_t len)
{
        HAL_UART_Transmit_IT(debug_uart(), tx_buffer, len);
}

void user_while(void)
{
        visHandle();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
        if (huart == debug_uart())
        {
                memcpy(rs485_tx_buffer, debug_rx_buffer, BUFFER_SIZE);
                rs485_tx(rs485_tx_buffer, BUFFER_SIZE);
                HAL_UART_Receive_IT(debug_uart(), debug_rx_buffer, BUFFER_SIZE);
        }
        else if (huart == rs485_uart())
        {
                memcpy(debug_tx_buffer, rs485_rx_buffer, BUFFER_SIZE);
                debug_tx(debug_tx_buffer, BUFFER_SIZE);

                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_RESET);
                HAL_UART_Receive_DMA(rs485_uart(), rs485_rx_buffer, BUFFER_SIZE);
        }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
        if (huart == debug_uart())
        {
        }
        else if (huart  == rs485_uart())
        {
                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_RESET);
        }
}

void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{
}
