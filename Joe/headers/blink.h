/* This function by joe, to use simply call this in your code:
 * blink(NUMBER_OF_BLINKS, LED);
 * where the variable names are the names of your own variables
 * remember that this header must be included using the pragma command:
 * #include "blink.h"
 * and remember of course that you must place this file in the same directory (folder) as your source.c file,
 * good luck!
 */

void blink(int numberOfBlinks, char statusLight) //We take the user imput from calling this function so we know where the light is, as well as the number of binks
{
	while(numberOfBlinks > 0) //for as long as we have blinks to go
	{
		delay(100); //wait 100ms
		SensorValue[statusLight] = true; //slow Blink
		delay(100);
		SensorValue[statusLight] = false;
		numberOfBlinks--; //subtract one to the blink value 
	}
}
