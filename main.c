#include "LCD_HD44780.h"





int main()
{
	LCD_init();

	for(;;)
	{
	clean_display();
	line_wrapping(1);

	LCD_write_str("Hi Dimon!");

	line_wrapping(2);//переключение на нижнюю строку

	LCD_write_str("How are you?");

	_delay_ms(10000);
	clean_display();
	line_wrapping(1);
	LCD_write_str("I am glad to see you!");

	line_wrapping(2);//переключение на нижнюю строку

	LCD_write_str("Good luck!");

	_delay_ms(10000);

	}
}
