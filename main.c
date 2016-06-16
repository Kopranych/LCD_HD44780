#include "LCD_HD44780.h"





int main()
{
	LCD_init();
//	_delay_ms(40);
//	LCD_read_BF();
	char *p = "Hello!\r\n Max!";
	while(*p)
	{
		LCD_write(*p,RS_DATA);
		p++;
	}
//	LCD_write_adress('O', 0x81);

}
