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

void blink_led(struct led_data *ld,
               uint32_t on_time,
               uint32_t off_time,
               uint32_t repeats)
{
        for (uint16_t i = 0; i < repeats; i++)
        {
                led_on(ld, on_time);
                led_off(ld, off_time);
        }
}

void led_on(struct led_data *ld, uint32_t on_time)
{
        HAL_GPIO_WritePin(ld->GPIOx, ld->GPIO_Pin, GPIO_PIN_SET);
        HAL_Delay(on_time);
}

void led_off(struct led_data *ld, uint32_t off_time)
{
        HAL_GPIO_WritePin(ld->GPIOx, ld->GPIO_Pin, GPIO_PIN_RESET);
        HAL_Delay(off_time);
}
