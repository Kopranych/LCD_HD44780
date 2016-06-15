#include "LCD_HD44780.h"





int main()
{
	LCD_init();

	LCD_write_str("Ho are you?");

	LCD_write(SEC_LINE,RS_COM);//переключение на нижнюю строку

	LCD_write_str("I am Ilya!");
}
