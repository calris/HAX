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

#ifndef BLINK_LED_H_
#define BLINK_LED_H_

void blink_led(GPIO_TypeDef* GPIOx,	\
			   uint16_t GPIO_Pin,	\
			   uint32_t on_time,	\
			   uint32_t off_time,	\
			   uint32_t repeats);

#endif /* BLINK_LED_H_ */
