// Ѕиблиотека дл€ работы с LCD HD44780 диспоеем


#include "LCD_HD44780.h"



/////////////////////////////////////////

void LCD_init()
{	
	_delay_ms(40);
	DDR_DATA |= 0xF0;
	PORT_DATA |= 0xF0;
	DDR_SIG |= (ON<<E)|(ON<<RW)|(ON<<RS);
	PORT_SIG |= (ON<<E)|(ON<<RW)|(ON<<RS);
	_delay_ms(40);
	LCD_write(0x28,RS_COM);
	LCD_write(0x01,RS_COM);
	LCD_write(0x06,RS_COM);
	LCD_write(0x06,RS_COM);
	LCD_write(0x0C,RS_COM);
//	LCD_write(0x14,RS_COM);
//	LCD_write(0x39,RS_DATA);
}

void LCD_write(uint8_t data, uint8_t BIT_RS)
{
	_delay_ms(40);
//	LCD_read_BF();
	DDR_DATA |= 0xF0;
	PORT_DATA |= 0xF0;
	PORT_SIG &= ~(ON<<RW);
	if(BIT_RS == RS_COM)// если 0 то  оманда 
	{
		PORT_SIG &= ~(ON<<RS);
	} 
	else PORT_SIG|= (ON<<RS);// иначе 1 то данные 
	uint8_t tmp = data;
	uint8_t temp = PORT_DATA & 0x0F;
	temp |= (data &0xF0);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(10);
	PORT_SIG &= ~(ON<<E);
	temp = PORT_DATA & 0x0F;
	temp|= (tmp<<4);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(10);
	PORT_SIG &= ~(ON<<E);
	_delay_ms(100);	

}

void LCD_write_adress(uint8_t data, uint8_t adress)
{
	_delay_ms(40);
//	LCD_read_BF();
	LCD_write(adress, RS_COM);
	DDR_DATA |= 0xF0;
	PORT_DATA |= 0xF0;
	PORT_SIG &= ~(ON<<RW);
	PORT_SIG|= (ON<<RS);// иначе 1 то данные 
	uint8_t tmp = data;
	uint8_t temp = PORT_DATA & 0x0F;
	temp |= (data &0xF0);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(10);
	PORT_SIG &= ~(ON<<E);
	temp = PORT_DATA & 0x0F;
	temp|= (tmp<<4);
	PORT_DATA = temp;
	PORT_SIG|= (ON<<E);
	_delay_ms(10);
	PORT_SIG &= ~(ON<<E);
	_delay_ms(100);	

}

void LCD_read_BF()
{
	DDR_DATA &= 0x0F;
	PORT_DATA |= 0xF0;
	PORT_SIG |= (ON<<RW);
	PORT_SIG &= ~(ON<<RS);
	uint8_t tmp = 0;
	do{
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	PORT_SIG &= ~(ON<<E);
	uint8_t data = PIN_DATA & 0xF0;
	tmp = data;
	PORT_SIG|= (ON<<E);
	_delay_ms(2);
	PORT_SIG &= ~(ON<<E);
	data = PIN_DATA & 0xF0;
	data = data>>4;
	tmp|=data;
	}while((tmp &(1<<BF))!=0);		
}






/*void CLEAR_BIT(uint8_t PORTX, uint8_t PX)
{
	PORTX|= 0<<PX;
}

void SET_BIT(uint8_t PORTX, uint8_t PX)
{
	PORTX|= 1<<PX;
}*/
