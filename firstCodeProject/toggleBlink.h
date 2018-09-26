void toggleBlink() //This function will toggle the flashing of an LED
{
	/*delete me!!*/int blinkState = true;

	if(SensorValue(bumpSwitch) == true) //if you push the bump switch..
	{
		if(blinkState == false) //..and the toggle is off...
		{
			blinkState = true; //turn the toggle on.
			delay(30);
		}
		else //..and the toggle is on...
		{
			blinkState = false; //turn the toggle off.
			delay(30);
		}
	}
}
