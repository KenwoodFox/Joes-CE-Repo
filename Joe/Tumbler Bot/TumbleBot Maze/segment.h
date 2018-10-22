void segment(int driveTime) //to use segment, give a drivetime, a time in seconds to run the motor for
{
	easyGas(0, 40, 4, 1); //speed up
	delay(driveTime); //Drive for
	easyGas(40, 0, 4, -1); //come to a stop
	delay(500);
}

void backup()
{
	easyGas(0, -40, 4, -1);
	delay(300);
	easyGas(-40, 0, 4, 1);
}
