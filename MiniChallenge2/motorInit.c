void motorInit()
{
	int rev = 1000;
//motor init
	startMotor(starboardMotor, 80);
	startMotor(portMotor, 80);
	delay(rev); //adjust me! 1 rev
	stopMotor(starboardMotor);
	stopMotor(portMotor);
	delay(2000); //delay for 2 seconds
}
