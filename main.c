#include "LCD_HD44780.h"





int main()
{
	LCD_init();

	LCD_write_str("Hi DIMON!");

	line_wrapping();//������������ �� ������ ������

	LCD_write_str("How are you?");
}
