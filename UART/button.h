#ifndef button
#define button

#define KEY_TIME_READ           100

enum KEY_1
{
  BT_UNDETERM,
  BT_NO_PRESSED,
  BT_PRESSED
};

enum KEY_1 read_button0 (void);
enum KEY_1 read_button1 (void);
enum KEY_1 read_button2 (void);

#endif