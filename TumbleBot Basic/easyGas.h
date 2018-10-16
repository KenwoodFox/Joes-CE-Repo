//this function by Joe, remeber to include my drivetrain.c before including this file

void easyGas(int targetSpeed, int accelValue, int accelDirection)
{
	int speed = 0; //arb value for the current speed

	while(speed < targetSpeed) //While the speed you are going is less than the speed you want to be going
	{
		speed = speed + accelDirection; //add 0.5 to the speed value
		delay(accelValue); //delay for this long
		starboardDriveTrain(speed); //set the speed
		portDriveTrain(speed);
	}
}
