task blink()
{
	while(true) //forever...
	{
		while(SensorValue(bumpSwitch) == true) //If you are holding the bump switch
		{
			turnLEDOn(LEDOne); //turn on the LED
			delay(1000); //wait..
			turnLEDOff(LEDOne); //turn it off
			delay(1000); //this second wait is here, beacuse as it loops, there needs to be a delay between turning off and then turning back on
		}
	}
}
