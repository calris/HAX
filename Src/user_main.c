/*
 * user_main.c
 *
 *  Created on: 29Jul.,2018
 *      Author: gruss
 */

#include "stm32f4xx_hal.h"
#include "user_main.h"
#include "blink_led.h"
#include "visEffect.h"

extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart1;

void user_main(void)
{
//        uint8_t in_usart6[10];
//        uint8_t in_usart1[10];

//        HAL_StatusTypeDef usart6_status;
//        HAL_StatusTypeDef usart1_status;

        visHandle();

//        usart1_status = HAL_UART_Receive(&huart1, in_usart1, 1, 100);
//        usart6_status = HAL_UART_Receive(&huart6, in_usart6, 1, 100);

//        if (usart1_status != HAL_TIMEOUT)
//        {
//                HAL_UART_Transmit(&huart6, in_usart1, 1, 100);
//        }

//        if (usart6_status != HAL_TIMEOUT)
//        {
//                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_SET);
//                HAL_UART_Transmit(&huart1, in_usart6, 1, 100);
//                HAL_GPIO_WritePin(TX_EN_485_GPIO_Port, TX_EN_485_Pin, GPIO_PIN_RESET);
//        }
}