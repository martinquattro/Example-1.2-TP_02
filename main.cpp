/*!****************************************************************************
 * @file main.cpp
 * @brief Activate the alarm when gas or overTemperature is detected
 * This program was built and tested on the NUCLEO F429ZI ARMC6,
 * connected to a Dip Switch and it takes care of turning on and off
 * the LED1 based on the selected state of the dip switch. Additionally,
 * it prints in the terminal the states of the pins
 * The pins is set into a PullDown mode so the dip switch should be connected 
 * to 3.3V pin
 * @author Quattrone Martin
 * @author Vazquez Rodrigo
 *******************************************************************************/

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
   DigitalIn gasDetector(D2);               //! An object of the DigitalIn class is create via the constructor of it DigitalIn(PinName pin) : gpio()
                                            // It create a DigitalIn connected to the specified pin
                                            // This constructor is overriden and has another implementation that receives a second argument
                                            // in it DigitalIn(PinName pin, PinMode mode) : gpio() to define, when the object is created, its mode too.
                                            // It inherits the methods from the gpio object
   DigitalIn overTempDetector(D3);
   
   DigitalOut alarmLed(LED1);               //! An object of the DigitalOut class is create via the constructor of it DigitalOut(PinName pin) : gpio()
                                            // It Creates a DigitalOut connected to the specified pin
                                            // This constructor is overriden and has another implementation that receives a second argument
                                            // in it DigitalOut(PinName pin, int value) : gpio() to define, when the object is created, its value too.
                                            // It inherits the methods from the gpio object       
   
   gasDetector.mode(PullDown);   
   overTempDetector.mode(PullDown);

    while (true) 
    {   
      printf("%s : %d\n", "gasDetectorState", gasDetector.read());       //!< The state of the pin is printed
      printf("%s : %d\n", "overTempState", overTempDetector.read());      //!< The state of the pin is printed

      if ( gasDetector || overTempDetector ) 
      {
        alarmLed = ON;
      } 
      else 
      {
        alarmLed = OFF;
      }
    }
}