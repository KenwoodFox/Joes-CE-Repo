task blink()
{
	//int blinkState = true;
	while(true)
	{
		while(SensorValue(bumpSwitch) == true) //If you are holding the bump switch
		{
			turnLEDOn(LEDOne);
			delay(1000); //...do the code
			turnLEDOff(LEDOne);
			delay(1000); //more code
		}
	}
}
