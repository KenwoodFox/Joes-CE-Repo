void findLine()
{
	int lowerThreshold = 1200; //thresholdbetween light and dark

	while(SensorValue[masterReflector] < lowerThreshold)
	{
		standard(27); //go forward at 40
		delay(10); //wait 10ms before checking again
	} //this loop will exit once the robot finds the line!
	halt(); //stop motors
}

void linePID() //serious maths
{
//	int Kp; //proportional
//	int Ki; //integral
//	int Kd; //derivative

//	int speed = 25;

	//as the error increases, that is, our target, masterReflector goes down, we want to increase the speed of a corrosponding motor, lets start with something basic

	portDriveTrain(20);
	starboardDriveTrain(20);

	while (true)
	{
		if(SensorValue[starboardReflector] > SensorValue[masterReflector]) //in general if the starboard size is on the black, run this
		{
			portDriveTrain(20);
			starboardDriveTrain(30);
		}
		if(SensorValue[portReflector] > SensorValue[masterReflector])
		{
			portDriveTrain(30);
			starboardDriveTrain(20);
		}
		delay(10);
	}
}
