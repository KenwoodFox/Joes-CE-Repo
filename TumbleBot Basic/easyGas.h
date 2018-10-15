//this function by joe, remeber to include my drivetrain.c before including this file

void easyGas(int targetSpeed /*arbatrairy value for speed*/, int accelValue /*arbatrairy value for speed //arb value to tune the time it takes for an acceleration*/, int accelDirection)
{
	int speed = 0; //arb value for the current speed

	while(speed < targetSpeed) //while you are not at target speed
	{
		speed = speed + accelDirection; //add 0.5 to the speed value
		delay(accelValue); //delay for this long
		starboardDriveTrain(speed); //set the speed
		portDriveTrain(speed);
	}
}
