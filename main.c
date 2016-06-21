#include "LCD_HD44780.h"





int main()
{
	LCD_init();

	for(;;)
	{
	clean_display();
	line_wrapping(1);

	LCD_write_str("PRIVET ARTEM!");

	line_wrapping(2);//переключение на нижнюю строку

	LCD_write_str("KAK DELA?");

	_delay_ms(10000);
	clean_display();
	line_wrapping(1);
	LCD_write_str("KAK SLYZHBA?");

	line_wrapping(2);//переключение на нижнюю строку

	LCD_write_str("Good luck!");

	_delay_ms(10000);

	}
}
