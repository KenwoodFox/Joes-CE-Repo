//This function by Joe

void starboardDriveTrain(float speed) //function to drive each of the starboard wheels using value speed,
{
	int tune = 1.0000; //tune adjust for the variablity of the wheels

	motor[starboardFore] = (speed * tune); //Set both motors to the speed given and multiply them by thr tune value
	motor[starboardAft] = (speed * tune);
}

void portDriveTrain(float speed) //function to drive each of the port wheels using value speed,
{
	int tune = 1.0050; //tune adjust for the variablity of the wheels

	motor[portFore] = (speed * tune); //Set both motors to the speed given and multiply them by thr tune value
	motor[portAft] = (speed * tune);
}
