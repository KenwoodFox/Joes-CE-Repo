void startup()
{
	int i = 0;

	//Startup notifier
	while(SensorValue[bumpSwitch] != true) //while bumpswitch is not pressed
	{
		delay(50); //wait 50ms
		SensorValue[LED] = true; //Blink LED
		delay(50);
		SensorValue[LED] = false;
	}

	while( i < 6) //runs after bump switch is pressed
	{
		delay(100); //wait 100ms
		SensorValue[LED] = true; //slow Blink
		delay(100);
		SensorValue[LED] = false;
		i++;
	}
}
