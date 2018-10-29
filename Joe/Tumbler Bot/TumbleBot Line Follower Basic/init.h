void startup(char bumper, char statusLight)
{
	int i = 0;

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
