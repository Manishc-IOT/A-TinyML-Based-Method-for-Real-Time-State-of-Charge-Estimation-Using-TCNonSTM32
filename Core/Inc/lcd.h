/*
 * lcd.h
 *
 *  Created on: Apr 7, 2026
 *      Author: Manish C
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#ifndef LCD_H
#define LCD_H

#include "main.h"

void LCD_Init(void);
void LCD_Send_String(char *str);
void LCD_Set_Cursor(uint8_t row, uint8_t col);
void LCD_Clear(void);

#endif

#endif /* INC_LCD_H_ */
