void findLine()
{
	int lowerThreshold = 1200; //thresholdbetween light and dark

	while(sensorValue[masterReflector] < lowerThreshold)
	{
		standard(27); //go forward at 40
		delay(10); //wait 10ms before checking again
	} //this loop will exit once the robot finds the line!
	halt(); //stop motors
}

void linePID() //serious maths
{
	int Kp; //proportional
	int Ki; //integral
	int Kd; //derivative

	int speed = 25;

	int starboardComp;
	int portComp;

	//as the error increases, that is, our target, masterReflector goes down, we want to increase the speed of a corrosponding motor, lets start with something basic

	while (true)
	{
		if(sensorValue[starboardReflector] > sensorValue[masterReflector])
		{
			portComp++;
		}
		if(sensorValue[portReflector] > sensorValue[masterReflector])
		{
			starboardComp++;
		}
		starboardDriveTrain(speed + starboardComp);
		portDriveTrain(speed + portComp);
	}
}
