// ���������� ��� ������ � LCD HD44780 ��������
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

////////////////////////���������������////////////////////////////////////////
#define PORT_SIG  PORTB//���� ����������
#define DDR_SIG   DDRB//
#define PIN_SIG   PINB//
#define E         PB0//�����
#define RW        PB1//�����������:1 ������ �������, 0 ������ � �������
#define RS        PB2//1 �������� ������, 0 �������� �������
#define PORT_DATA PORTA//���� ������
#define DDR_DATA  DDRA//
#define PIN_DATA  PINA//
#define BF        PA7//���� ��������� ���� 1 �� ����� ������� ���� 0 �� ��������
#define RS_COM    0//�������� �������
#define RS_DATA   1//�������� ������
#define ON		  1//��������� 
#define OFF		  0//����������
#define BUS_LINE  0x28//2 ����� ������, 4 ���� ����
#define SEC_LINE  0xA8//


//////////////////////////////////////�������///////////////////////////////
void LCD_init();//������� ������������� ������� 
void LCD_write(uint8_t data, uint8_t BIT_RS);//������� ������ � �������
void LCD_read_BF();//������� ������ ����� BF ���������� �� ������� �� ������ ������ �� ��������!!!������ ����� delay)))
void LCD_write_adress(uint8_t data, uint8_t adress);//������� ������ � ������� �� ����������� ������
void LCD_write_str(int8_t *string);//����� ������ �� �������
