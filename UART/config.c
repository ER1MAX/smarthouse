#include "iostm8l152c6.h"
#include "config.h"
#include "uard.h"

unsigned long dummy;
volatile int start_on=3000;
unsigned char rx_old;

void start (void)
{
  PC_ODR_bit.ODR6=1;
  while (start_on)
  {
  for (dummy =0; dummy <500; dummy ++);
  start_on--;
  }
  PC_ODR_bit.ODR6=0;
}

void InitialiseUART(void)
{     
    CLK_PCKENR1_bit.PCKEN15 = 1; //Подаём тактирование на UASART1  
//    unsigned char tmp = USART1_SR;
//    tmp = USART1_DR;
    //  Reset the UART registers to the reset values.
    USART1_CR1 = 0;
    USART1_CR2 = 0;
    USART1_CR4 = 0;
    USART1_CR3 = 0;
    USART1_CR5 = 0;
    USART1_GTR = 0;
    USART1_PSCR = 0;
    //  Set up the port to 14400,n,8,2.
    USART1_CR1_M    = 0;         //  8 Data bits.
    USART1_CR1_PCEN = 0;         //  Disable parity.
    USART1_CR3      = 0x00;      //  1 stop bits     
    USART1_BRR2     = 0x03;      //  Set the baud rate registers to 115200
    USART1_BRR1     = 0x68;      //  based upon a 16 MHz system clock.
    //  Disable the transmitter and receiver.
    USART1_CR2_TEN   = 0;        //  Disable transmit.
    USART1_CR2_REN   = 0;        //  Disable receive.
    //  Set the clock polarity, clock phase and last bit clock pulse.
    USART1_CR3_CPOL  = 0;
    USART1_CR3_CPHA  = 0;
    USART1_CR3_LBCL  = 0;
    //  Set the Receive Interrupt RM0016 p358,362
    USART1_CR2_TIEN  = 0;     // Transmitter interrupt enable
    USART1_CR2_TCIEN = 0;     // Transmission complete interrupt enable
    USART1_CR2_RIEN  = 1;     //  Receiver interrupt enable
    USART1_CR2_ILIEN = 0;     //  IDLE Line interrupt enable

    //  Turn on the UART transmit, receive and the UART clock.
    USART1_CR2_TEN    = 1;
    USART1_CR2_REN    = 0;
    USART1_CR1_PIEN   = 0;
    //USART1_CR4_LBDIEN = 0;
}

//==================================================
//Начало блока прерваний============================
#pragma vector = USART_R_RXNE_vector
    __interrupt void UART1_IRQHandler(void)
    {
     save_str();
    }
//=Конец блока прерваний============================
//==================================================


void set_pin (void)
{
  PB_DDR_bit.DDR0=0;    //Настройка порта на вход
  PB_CR1_bit.C10=1;     //Подтянут к +питанию
  PB_CR2_bit.C20=0;     //Прерывания отключены
  
  PB_DDR_bit.DDR1=0;    //Настройка порта на вход
  PB_CR1_bit.C11=1;     //Подтянут к +питанию
  PB_CR2_bit.C21=0;     //Прерывания отключены
  
  PB_DDR_bit.DDR2=0;    //Настройка порта на вход
  PB_CR1_bit.C12=1;     //Подтянут к +питанию
  PB_CR2_bit.C22=0;     //Прерывания отключены
  
  PE_DDR_bit.DDR7=1;    //Настройка порта на выход
  PE_CR1_bit.C17=1;     //Подтянут к +питанию
  PE_CR2_bit.C27=1;     //скорость >10
  
  PC_DDR_bit.DDR7=1;    //Настройка порта на выход
  PC_CR1_bit.C17=1;     //Подтянут к +питанию
  PC_CR2_bit.C27=1;     //скорость >10
  
  PC_DDR_bit.DDR6=1;    //Настройка порта на выход
  PC_CR1_bit.C16=1;     //Подтянут к +питанию
  PC_CR2_bit.C26=1;     //скорость >10
}

void set_uard (void)
{
  CLK_CKDIVR=0x00;                      //делитель частоты 1
  CLK_PCKENR1_bit.PCKEN15 = 1;          //Подаём тактирование на UASART1 
  PC_DDR_bit.DDR2=0;
  PC_DDR_bit.DDR3=1;
  USART1_CR1_bit.M=0;
  USART1_BRR2 = 0xB;
  USART1_BRR1 = 0x8;
  USART1_CR2_bit.REN=1;                 //прием
  for (dummy =0; dummy <500; dummy ++);
  USART1_CR2_bit.TEN=1;                 //передача
  USART1_CR2_RIEN=1;                    //Прерывание по приему
}

void set_tim_4 (void)
{
  CLK_PCKENR1   = 0x04;  //Подаём тактирование на TIM4
  TIM4_PSCR     = 0x09;  //Предделитель = 7A
  TIM4_ARR      = 0x7F;  //Регистр предзагрузки = 255
  TIM4_CR1      = 0x01;  //Активируем таймер
  TIM4_IER      = 0x01;  //Разрешаем прерывание по переполнению
}