task starboardOperation()
{
	int MAGICREVO = 1200;

	while(true)
	{
		delay(10); //allotocate CPU time to other tasks
		if(SensorValue(limitSwitch) == true) //while the limit switch is pressed
		{
			startMotor(starboardMotor, 80); //start the motor moving forward
			delay(MAGICREVO); //delay for one rotation
			startMotor(starboardMotor, -80); //and backwards
			delay(MAGICREVO); //delay for one rotation
		}
		else //if the switch is pressed
		{
			stopMotor(starboardMotor);
		}
	}
}
