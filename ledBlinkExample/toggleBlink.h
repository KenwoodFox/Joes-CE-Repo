
//This function will toggle the flashing of an LED
void toggleBlink()
{
	int toggleBlink = false;
	
	if(SensorValue(bumpSwitch) == true) //if you push the bump switch..
	{
		if(toggleBlink == false) //..and the toggle is off...
		{
			toggleBlink = true; //turn the toggle on.
		}
		else //..and the toggle is on...
		{
			toggleBlink = false; //turn the toggle off.
		}
	}
	
	if(toggleBlink == true) //If you are toggled on...
	{
		SensorValue(LEDOne) = true;
		delay(1000); //...do the code
		SensorValue(LEDOne) = false;
	}
}