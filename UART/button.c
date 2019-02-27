#include "iostm8l152c6.h"
#include "counter.h"
#include "button.h"

extern int cr;

enum KEY_1 read_button0 (void)
{
  static enum KEY_1     key_1_pred  =       BT_NO_PRESSED;
  static enum KEY_1     key_1_now   =       BT_NO_PRESSED; 
  if(cr > KEY_TIME_READ)
  {
    if(PB_IDR_bit.IDR0)
      {
      key_1_now=BT_NO_PRESSED;                  //�� ������
      }
    else
      {
      key_1_now=BT_PRESSED;                     //������
      }
    if(key_1_now == key_1_pred)                 //�������� 1
      {
       cr =110;
       key_1_pred=key_1_now;                 //���� � ����� - �� ������
       return BT_NO_PRESSED;                 //��� ������� 
      }
    else
      {
      cr=0;                           //key1_state_pred==BT_NO_PRESSED
      key_1_now=key_1_pred;       //key1_state_now=BT1_PRESSED
      return BT_PRESSED;
      }
  }
  return BT_UNDETERM;
}

enum KEY_1 read_button1 (void)
{
  static enum KEY_1     key_1_pred  =       BT_NO_PRESSED;
  static enum KEY_1     key_1_now   =       BT_NO_PRESSED; 
  if(cr > KEY_TIME_READ)
  {
    if(PB_IDR_bit.IDR1)
      {
      key_1_now=BT_NO_PRESSED;                  //�� ������
      }
    else
      {
      key_1_now=BT_PRESSED;                     //������
      }
    if(key_1_now == key_1_pred)                 //�������� 1
      {
       cr =110;
       key_1_pred=key_1_now;                 //���� � ����� - �� ������
       return BT_NO_PRESSED;                 //��� ������� 
      }
    else
      {
      cr=0;                           //key1_state_pred==BT_NO_PRESSED
      key_1_now=key_1_pred;       //key1_state_now=BT1_PRESSED
      return BT_PRESSED;
      }
  }
  return BT_UNDETERM;
}

enum KEY_1 read_button2 (void)
{
  static enum KEY_1     key_1_pred  =       BT_NO_PRESSED;
  static enum KEY_1     key_1_now   =       BT_NO_PRESSED; 
  if(cr > KEY_TIME_READ)
  {
    if(PB_IDR_bit.IDR2)
      {
      key_1_now=BT_NO_PRESSED;                  //�� ������
      }
    else
      {
      key_1_now=BT_PRESSED;                     //������
      }
    if(key_1_now == key_1_pred)                 //�������� 1
      {
       cr =110;
       key_1_pred=key_1_now;                 //���� � ����� - �� ������
       return BT_NO_PRESSED;                 //��� ������� 
      }
    else
      {
      cr=0;                           //key1_state_pred==BT_NO_PRESSED
      key_1_now=key_1_pred;       //key1_state_now=BT1_PRESSED
      return BT_PRESSED;
      }
  }
  return BT_UNDETERM;
}