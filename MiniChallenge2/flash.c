task blink()
{
	/*
		This task made by Joe
		To use: call this task with the command: startTask(blink, 5);
		This will start the task with a priority of 5, you do not and
		should not call this task more than once.
	 */

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
