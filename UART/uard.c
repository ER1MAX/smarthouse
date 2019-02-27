#include "iostm8l152c6.h"
#include "button.h"

int n=0;
int i=1;
int w=0;
extern int uard_end;
extern int de_pause;
char str;
unsigned char rx_str[80];
int count_mass=0;
unsigned char rx_data[10][20];
int stroka=0;
int line=0;

void atz_ipr (void)
{
  
  char strlen1[]={"AT+CMSS=6\r"};
    for(n=0;n<=9;n++)
      {
      str=strlen1[n];
      while(!(USART1_SR_bit.TXE)); //Ожидаем освобождения буферного регистра TDR  
      USART1_DR=str; // Отправляем символ
      }
    
    
}

void atok (void)
{
  int h=10;
  while(h)
  {
    if(de_pause>=100)
      {
        char strlen1[]={"ATZ\r"};
        for(n=0;n<=3;n++)
          {
            str=strlen1[n];
            while(!(USART1_SR_bit.TXE)); //Ожидаем освобождения буферного регистра TDR  
            USART1_DR=str; // Отправляем символ
          }
        de_pause=1;
        h--;
      }     
  }
  USART1_CR2_REN    = 1;
}
void at (void)
{
    char strlen1[]={"ATD068573974\r"};
    for(n=0;n<=12;n++)
      {
      str=strlen1[n];
      while(!(USART1_SR_bit.TXE)); //Ожидаем освобождения буферного регистра TDR  
      USART1_DR=str; // Отправляем символ
      }
}

void ath (void)
{
    char strlen1[]={"ATH\r"}; 
    for(n=0;n<=3;n++)
      {
      str=strlen1[n];
      while(!(USART1_SR_bit.TXE)); //Ожидаем освобождения буферного регистра TDR  
      USART1_DR=str; // Отправляем символ
      }
}

void save_str (void)
{
  if(count_mass<=79)
  {
   rx_str[count_mass] = USART1_DR;
   count_mass++;
   uard_end=0;
  }
  else
  {
   count_mass=0;
  }
}
void parsing_str (void)
{
    uard_end=0;
    count_mass=0;
    w=0;
    for (w = 0;w <= 79;w++)
    {
    
      if((rx_str[count_mass]=='\r')&&(rx_str[count_mass+1]=='\r'))
      {
        if(stroka==10)stroka=0;
        stroka++;
        line=0;
        count_mass=count_mass+2;
        rx_data[stroka][line] = rx_str[count_mass];
        if(line >= 20)
        {line=0;
        }else{line++;}
      }
      if((rx_str[count_mass]=='\r')&&(rx_str[count_mass+1]!='\r'))
      {
      count_mass++;
      rx_data[stroka][line] = rx_str[count_mass];
        if(line >= 20)
        {line=0;
        }else{line++;}
      }
      if((rx_str[count_mass]!='\r')&&(rx_str[count_mass+1]=='\r'))
      {
      count_mass++;
      rx_data[stroka][line] = rx_str[count_mass];
        if(line >= 20)
        {line=0;
        }else{line++;}
      }
      if((rx_str[count_mass]!='\r')&&(rx_str[count_mass+1]!='\r'))
      {
      count_mass++;
      rx_data[stroka][line] = rx_str[count_mass];
        if(line >= 20)
        {line=0;
        }else{line++;}
      }
    }
}