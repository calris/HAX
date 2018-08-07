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

void wait_ms(uint32_t wait_time)
{
        uint32_t start_tick;

        start_tick = HAL_GetTick();
        while (HAL_GetTick() < (start_tick + wait_time))
                ;
}
