/* This function by joe, to use simply call this in your code:
 * startup(BUMPER, LED);
 * where the variable names are the names of your own variables
 * remember that this header must be included using the pragma command:
 * #include "init.h"
 * and remember of course that you must place this file in the same directory (folder) as your source.c file,
 * good luck!
 */

void startup(char bumper, char statusLight) //We take userimput to specify the bumper location, and the status light!
{
	int i = 0; //this int i, will allow us to do some basic math

	//Startup notifier
	while(SensorValue[bumper] != true) //while bumpswitch is not pressed
	{
		delay(50); //wait 50ms
		SensorValue[statusLight] = true; //Blink LED
		delay(50);
		SensorValue[statusLight] = false;
	}

	while( i < 6) //runs after bump switch is pressed
	{
		delay(100); //wait 100ms
		SensorValue[statusLight] = true; //slow Blink
		delay(100);
		SensorValue[statusLight] = false;
		i++;
	}
}
