task portOperation()
{
	while(true)
	{
		delay(10); //allotocate CPU time to other tasks
		if(SensorValue(bumpSwitch) == true) //while the bump switch is  pressed
		{
			startMotor(portMotor, 127/2); //start the motor
		}
		else //if the switch is not pressed
		{
			stopMotor(portMotor);
		}
	}
}
