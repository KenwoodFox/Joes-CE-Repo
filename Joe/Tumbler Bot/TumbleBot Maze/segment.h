void segment(int driveTime) //to use segment, give a drivetime, a time in seconds to run the motor for
{
	easyGas(0, 90, 5, 1); //speed up
	delay(driveTime); //Drive for
	easyGas(90, 0, 5, -1); //come to a stop
}
