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

void linePID(int speed) //serious maths
{
	//int Kp = ; //proportional
	//int Ki = ; //integral
	//int Kd = ; //derivative
	int error;

	error = SensorValue[starboardReflector] - SensorValue[portReflector];
	// In a PID loop, the goal is to aproach the target, but not overshoot it, a good PID loop can swoosh right to the target, while many others simply just, rush past it and come back right after, this mathamtical form of position control has been around since the first basic electronic navigation systems

	starboardDriveTrain(speed + (error / 10)); //put loop in here?
	portDriveTrain(speed - (error / 10));

	/* Kp * x + (Ki * x)?? Kd * x
	* x where you are now
	*/
}
