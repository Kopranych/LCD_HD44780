// Библиотека для работы с LCD HD44780 диспоеем
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

////////////////////////переопределения////////////////////////////////////////
#define PORT_SIG  PORTB//порт управления
#define DDR_SIG   DDRB//
#define PIN_SIG   PINB//
#define E         PB0//строб
#define RW        PB1//направление:1 чтение дисплея, 0 запись в дисплей
#define RS        PB2//1 передаем данные, 0 передаем команду
#define PORT_DATA PORTA//порт данных
#define DDR_DATA  DDRA//
#define PIN_DATA  PINA//
#define BF        PA7//флаг занятости если 1 то занят дисплей если 0 то свободен
#define RS_COM    0//передаем команду
#define RS_DATA   1//передаем данные
#define ON		  1//включение 
#define OFF		  0//выключение
#define BUS_LINE  0x28//2 линии данных, 4 бита шина
#define SEC_LINE  0xA8//


//////////////////////////////////////функции///////////////////////////////
void LCD_init();//функция инициализации дисплея 
void LCD_write(uint8_t data, uint8_t BIT_RS);//функция записи в дисплей
void LCD_read_BF();//функция чтения флага BF готовности из дисплея на данном железе НЕ РАБОТАЕТ!!!делаем через delay)))
void LCD_write_adress(uint8_t data, uint8_t adress);//функция записи в дисплей по конкретному адресу
void LCD_write_str(int8_t *string);//вывод строки на дисплей
