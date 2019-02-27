#include "iostm8l152c6.h"
#include "button.h"
volatile int cr=0;
volatile int de_pause=1;
volatile int uard_end=0;

#pragma vector = TIM4_UIF_vector //Прерывание по переполнению TIM4
  __interrupt void TIM4_UIF(void)
{
  cr++;
  uard_end++;
  if(de_pause!=0)de_pause++;
  TIM4_SR1_bit.UIF = 0;
};
