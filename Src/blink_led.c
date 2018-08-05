/*
 * err_log.c
 *
 *  Created on: 29Jul.,2018
 *      Author: gruss
 */

#include "stm32f4xx_hal.h"
#include "blink_led.h"

void blink_led(GPIO_TypeDef *GPIOx,
               uint16_t GPIO_Pin,
               uint32_t on_time,
               uint32_t off_time,
               uint32_t repeats)
{
        uint32_t start_tick;
        uint32_t i;

        for (i = 0; i < repeats; i++)
        {
                HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);

                start_tick = HAL_GetTick();
                while (HAL_GetTick() < (start_tick + on_time))
                        ;

                HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);

                start_tick = HAL_GetTick();
                while (HAL_GetTick() < (start_tick + off_time))
                        ;
        }
}
