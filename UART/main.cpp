#include "iostm8l152c6.h"
#include "intrinsics.h"
#include "config.h"
#include "uard.h"
#include "button.h"
#include "string.h"
int a=0;
extern int uard_end;
int main()
{
  CLK_CKDIVR=0x00; //делитель частоты 16 МГЦ
  asm("rim");             //Разрешаю прерывания
  set_tim_4();
  set_pin();
  start();              //Включение модема.
  InitialiseUART();
  atok();

  while (1)
  {
    if(uard_end > 100)
    {
      parsing_str();
    }
  if(read_button0()==BT_PRESSED)
    {
      at();
      PE_ODR_bit.ODR7^=1;
      a++;
    }
  if(read_button1()==BT_PRESSED)
    {
      ath();
      PC_ODR_bit.ODR7^=1;
      a--;
    }
  if(read_button2()==BT_PRESSED)
    {
      atz_ipr();
      PC_ODR_bit.ODR7^=1;
      a--;
    }
  }
}
