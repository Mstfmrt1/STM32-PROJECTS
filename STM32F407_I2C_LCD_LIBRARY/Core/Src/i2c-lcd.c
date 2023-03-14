
#include "i2c-lcd.h"
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup

void lcd_send_cmd (char cmd)
{
	//Firstly for send command RS=0 VE E=1
	//THEN 4 HIGH VALUE BITS ARE SENT
	//AFTER FOUR HIGH VALUE BITS ARE SENT, E=0.
	//HIGH-VALUE 4 BITS SENT ARE CLEARED
	//E=1 AND THE FIRST 4 BITS ARE SENT
	//AND THE LAST 4 BITS SENT FROM THE PORT BY SETTING E=0

  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd & 0xf0);// cmd & 0x11110000 -> 0xabcdefgh & 0x11110000 = 0xabcd0000	    	( MSB high-value 4 bits)
	data_l = ((cmd<<4)&0xf0);// (cmd << 4) & 0x11110000 -> 0xefgh & 0x11110000 = 0xefgh0000  	( LSB low-value 4 bits)

	data_t[0] = data_u|0x0C;  //[en = 1 & rs = 0] 0xabcd0000 | 0x00001100 -> 0xabcd1100   	SEND DATA
	data_t[1] = data_u|0x08;  //[en = 0 & rs = 0] 0xabcd0000 | 0x00001000 -> 0xabcd1000   	CLEAR PORT
	data_t[2] = data_l|0x0C;  //[en = 1 & rs = 0] 0xefgh0000 | 0x00001100 ->	0xefgh1100  SEND DATA LSB
	data_t[3] = data_l|0x08;  //[en = 0 & rs = 0] 0xefgh0000	| 0x00001000 -> 0xefgh1000  CLEAR PORT
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0); // data & 0x11110000 -> 0xabcdefgh & 0x11110000 = 0xabcd0000
	data_l = ((data<<4)&0xf0); //(data << 4) & 0x11110000 -> 0xefgh & 0x11110000 = 0xefgh0000
	data_t[0] = data_u|0x0D;  // [en = 1 & rs = 1] 0xabcd0000 | 0x00001101 -> 0xabcd1101
	data_t[1] = data_u|0x09;  //[en = 0 & rs = 1] 0xabcd0000 | 0x00001001 -> 0xabcd1001
	data_t[2] = data_l|0x0D;  //[en = 1 & rs = 1] 0xefgh0000 | 0x00001100 ->	0xefgh1101
	data_t[3] = data_l|0x09;  //[en = 0 & rs = 1] 0xefgh0000	| 0x00001000 -> 0xefgh1001
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_init (void)
{
	//4 BIT PROCESS
	lcd_send_cmd (0x02);//return home
	lcd_send_cmd (0x28);
	lcd_send_cmd(0X06);
	lcd_send_cmd (0x0F);// display on,cursor on, cursor blink on
	lcd_send_cmd (0x80);// 0,0 Location
}

void lcd_send_string (char *str)
{
	while (*str)
		lcd_send_data (*str++);
}
