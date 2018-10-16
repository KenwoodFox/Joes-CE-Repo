void motorInit()
{
	int rev = 1000; //this is the revolution duration variable, it exists only inside motorInit,

	//motor init
	startMotor(starboardMotor, 80); //start both motors going forward at power 80 out of 127 pwm
	startMotor(portMotor, 80);
	delay(rev); //adjust me! 1 rev
	stopMotor(starboardMotor); //stop both motors and wait two seconds
	stopMotor(portMotor);
	delay(2000); //delay for 2 seconds
}
