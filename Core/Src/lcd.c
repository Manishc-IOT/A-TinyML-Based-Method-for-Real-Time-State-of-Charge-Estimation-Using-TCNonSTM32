/*
 * lcd.c
 *
 *  Created on: Apr 7, 2026
 *      Author: Manish C
 */

#include "lcd.h"

// PB mapping
#define RS_PIN GPIO_PIN_0
#define EN_PIN GPIO_PIN_1
#define D4_PIN GPIO_PIN_10
#define D5_PIN GPIO_PIN_11
#define D6_PIN GPIO_PIN_12
#define D7_PIN GPIO_PIN_13

#define LCD_PORT GPIOB

void LCD_Enable()
{
    HAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_RESET);
    HAL_Delay(1);
}

void LCD_Send4Bits(uint8_t data)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);

	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
	    HAL_Delay(2);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	    HAL_Delay(2);
}

void LCD_Send_Command(uint8_t cmd)
{
    HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);

    LCD_Send4Bits(cmd >> 4);
    LCD_Send4Bits(cmd & 0x0F);
}

void LCD_Send_Data(uint8_t data)
{
    HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_SET);

    LCD_Send4Bits(data >> 4);
    LCD_Send4Bits(data & 0x0F);
}

void LCD_Init(void)
{
//    HAL_Delay(50);
//
//    LCD_Send4Bits(0x03);
//    HAL_Delay(5);
//    LCD_Send4Bits(0x03);
//    HAL_Delay(5);
//    LCD_Send4Bits(0x03);
//    HAL_Delay(5);
//    LCD_Send4Bits(0x02);
//
//    LCD_Send_Command(0x28); // 4-bit, 2-line
//    LCD_Send_Command(0x0C); // display ON
//    LCD_Send_Command(0x06); // cursor increment
//    LCD_Send_Command(0x01); // clear
//    HAL_Delay(2);


	HAL_Delay(50);

	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

	    LCD_Send4Bits(0x03);
	    HAL_Delay(5);
	    LCD_Send4Bits(0x03);
	    HAL_Delay(5);
	    LCD_Send4Bits(0x03);
	    HAL_Delay(5);
	    LCD_Send4Bits(0x02);

	    LCD_Send_Command(0x28);
	    LCD_Send_Command(0x0C);
	    LCD_Send_Command(0x06);
	    LCD_Send_Command(0x01);

	    HAL_Delay(5);
}

void LCD_Send_String(char *str)
{
    while(*str) LCD_Send_Data(*str++);
}

void LCD_Set_Cursor(uint8_t row, uint8_t col)
{
    uint8_t addr = (row == 0) ? 0x80 : 0xC0;
    addr += col;
    LCD_Send_Command(addr);
}

void LCD_Clear(void)
{
    LCD_Send_Command(0x01);
    HAL_Delay(2);
}
