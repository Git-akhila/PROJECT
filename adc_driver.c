#include<stdio.h>
#include<lpc21xx.h>
#include"header.h"
#define DONE ((ADDR>>31)&1) 
void adc_init(void)
{
PINSEL1|=015400000;
ADCR=0X00200400;
}
unsigned int adc_read(unsigned int ch_num)
{
unsigned int result=0;
ADCR|=(1<<ch_num);
ADCR|=1<<24;
while(DONE==0);
ADCR^=1<<24;
ADCR^=(1<<ch_num);
result=(ADDR>>6)&0X3FF;
return result;
}
void adc_integer(int num)
{
char buf[10];
sprintf(buf,"%d",num);
uart0_string(buf);
}
/*void uart0_tx_integer(int n)
{
	if(n==0)
		uart0_tx('0');
	if(n<0)
	{	
	uart0_tx('-');
	n=-n;
	}
	if(n>0)
	uart0_tx(n+48);
}*/

void adc_float(float num)
{
char buf[10];
sprintf(buf,"%f",num);
uart0_string(buf);
}
