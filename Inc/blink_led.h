/*
 * err_log.h
 *
 *  Created on: 29Jul.,2018
 *      Author: gruss
 */

#ifndef BLINK_LED_H_
#define BLINK_LED_H_

void blink_led(GPIO_TypeDef* GPIOx,	\
			   uint16_t GPIO_Pin,	\
			   uint32_t on_time,	\
			   uint32_t off_time,	\
			   uint32_t repeats);

#endif /* BLINK_LED_H_ */
