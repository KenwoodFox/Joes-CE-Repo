int initComplete = false;

task drive()
{
	int rev = 1000;

	if(initComplete == false)
	{
		//init
		startMotor(starboardMotor, 80);
		startMotor(portMotor, 80);
		delay(rev); //adjust me! 1 rev
		startMotor(starboardMotor, 0);
		startMotor(portMotor, 0);
		initComplete = true;
	}

	while(SensorValue(limitSwitch) == false)
	{
		startMotor(starboardMotor, -80);
		startMotor(portMotor, -80);
	}
}
