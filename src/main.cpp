#include "mbed.h"

DigitalIn BUTTON1(D4);
DigitalOut red(D1);
DigitalOut blue(D2);
DigitalOut green(D3);
/*
purpose of this prototype 
to turn leds on based on the time the button was held down for 

held down for less then 1 seccon turn on red 
1->2 = blue 
2->3 = green 
*/

/*
displayes light based on characcter input 
r = red
b = blue
g = green
*/
void displayLight(char Lightcol)
{
  if (Lightcol == 'r')
  {
    red = true;
  }
  if (Lightcol == 'b')
  {
    blue = true;
  }
  if (Lightcol == 'g')
  {
    green = true;
  }
  thread_sleep_for(1000);
  red = false;
  blue = false;
  green = false;
 
}

/*
when button is pressed down the timer starts and when button is relesed timer ends 
time is then compared to time intervals as specified 
then light display is called 
*/

int main() 
{
  Timer buttontimer;
  float time1 = 0;
  while(true)
  {
    
    if(BUTTON1 == true) // if button is pressed this will be true 
    {
      buttontimer.start();
    }
    else // when button is not pressed (only realy matters when button is relesed)
    {
      buttontimer.stop();
      time1 = buttontimer.read();
      buttontimer.reset();
      

    }
    if(time1 != 0 )
    {
      if(time1 <=1)
      {
        displayLight('r');
      }
      if(time1 > 1 && time1 <= 2)
      {
        displayLight('b');
      }
      if(time1 > 2 && time1 <= 3)
      {
        displayLight('g');
      }
      time1 = 0;
    }

  }
  
    
}