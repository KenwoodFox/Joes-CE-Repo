//This function by Joe

void starboardDriveTrain(float speed) //function to drive each of the starboard wheels using value speed,
{
	int tune = 0; //tune adjust for the variablity of the wheels

	startMotor(starboardFore, speed * tune); //start both motors on this side running
	startMotor(starboardAft, speed * tune);
}

void portDriveTrain(float speed) //function to drive each of the port wheels using value speed,
{
	int tune = 0; //tune adjust for the variablity of the wheels

	startMotor(portFore, speed * tune); //start both motors on this side running
	startMotor(portAft, speed * tune);
}
