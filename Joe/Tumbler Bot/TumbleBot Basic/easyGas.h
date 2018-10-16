//this function by joe, remeber to include my drivetrain.c before including this file

void easyGas(int robotSpeed, int targetSpeed, int accelValue, float accelDirection)
{ //The speed the robot is going, the speed you want it to go, the value of deacceleration, the direction and magnitude

	while(robotSpeed != targetSpeed && robotSpeed < 127 && robotSpeed > -127) //while you are not at target speed OR the speed value is bigger than the max output, THIS WILL TRIGGER IN CASE OF AN ERROR
	{
		robotSpeed = robotSpeed + accelDirection; //add accelDirection to the speed value
		delay(accelValue); //delay for this long
		starboardDriveTrain(robotSpeed); //set the speed
		portDriveTrain(robotSpeed);
	}
}
