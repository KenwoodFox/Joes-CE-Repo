//this function by joe, remeber to include my drivetrain.c before including this file

void easyGas(int targetSpeed, int accelValue, float accelDirection)
{
	float speed = 0; //arb value for the current speed

	while(speed != targetSpeed || speed > 127) //while you are not at target speed OR the speed value is bigger than the max output, THIS WILL TRIGGER IN CASE OF AN ERROR
	{
		speed = speed + accelDirection; //add accelDirection to the speed value
		delay(accelValue); //delay for this long
		starboardDriveTrain(speed); //set the speed
		portDriveTrain(speed);
	}
}
