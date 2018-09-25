void runMotors()
{
	int runSpeed = 88; //the speed the motors will run
		setMultipleMotors(runSpeed, portMotor, starboardMotor);
		delay(2000);
		if(limitSwitch != true)
	{
		setMultipleMotors(-runSpeed, portMotor, starboardMotor);
}
