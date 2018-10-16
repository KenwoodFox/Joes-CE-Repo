task blink()
{
	int blinkState = true;
	while(true)
	{
		if(blinkState == true) //If you are toggled on...
		{
			turnLEDOn(LEDOne);
			delay(1000); //...do the code
			turnLEDOff(LEDOne);
			delay(1000); //more code
		}
		else
		{
			delay(300); //sets the rescan rate
		}

		//delay(50);

		//toggle
		if(SensorValue(limitSwitch) == true) //If the switch is pressed
		{
			if(blinkState == true) //and you are blinking
			{
				blinkState = false; //disable the blink
			}
			else //if you press the switch and you are not blinking
			{
				blinkState = true;
			}
		}
	}
}
