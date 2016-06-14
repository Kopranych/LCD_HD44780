// Библиотека для работы с LCD HD44780 диспоеем


#include "LCD_HD44780.h"



/////////////////////////////////////////

void LCD_init()
{	
	DDR_DATA |= 0xF0;
	PORT_DATA |= 0xF0;
	DDR_SIG |= (ON<<E)|(ON<<RW)|(ON<<RS);
	PORT_SIG |= (ON<<E)|(ON<<RW)|(ON<<RS);
	_delay_ms(40);
	LCD_write(0x28,RS_COM);
	LCD_write(0x01,RS_COM);
	LCD_write(0x06,RS_COM);
}

void LCD_write(uint8_t data, uint8_t BIT_RS)
{
	DDR_DATA |= 0xF0;
	PORT_DATA |= 0xF0;
	PORT_SIG &= ~(ON<<RW);
	if(BIT_RS == RS_COM)// если 0 то Команда 
	{
		PORT_SIG &= ~(ON<<RS);
	} 
	else PORT_SIG|= (ON<<RS);// иначе 1 то данные 
	uint8_t tmp = data;
	uint8_t temp = PORT_DATA & 0x0F;
	temp |= (data &0xF0);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	PORT_SIG &= ~(ON<<E);
	temp = PORT_DATA & 0x0F;
	temp|= (tmp<<4);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	PORT_SIG &= ~(ON<<E);
	_delay_ms(40);	

}

void LCD_read_BF()
{
	DDR_DATA &= 0x0F;
	PORT_DATA |= 0xF0;
	PORT_SIG |= (ON<<RW);
	PORT_SIG &= ~(ON<<RS);
	do
	{
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	uint8_t data = PIN_SIG & 0xF0;
	PORT_SIG &= ~(ON<<E);
	uint8_t tmp = data;
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	data = PIN_SIG & 0xF0;
	PORT_SIG &= ~(ON<<E);
	data = data>>4;
	tmp|=data;
	}
	while((data &(1<<BF))==0);
	
}

/*void CLEAR_BIT(uint8_t PORTX, uint8_t PX)
{
	PORTX|= 0<<PX;
}

void SET_BIT(uint8_t PORTX, uint8_t PX)
{
	PORTX|= 1<<PX;
}*/
