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
	float Kp = 0.005; //proportional
	//float Ki = 0.05; //integral
	//float Kd = 0.05; //derivative

	float error = SensorValue[starboardReflector] - SensorValue[portReflector];
	// In a PID loop, the goal is to aproach the target, but not overshoot it, a good PID loop can swoosh right to the target, while many others simply just, rush past it and come back right after, this mathamtical form of position control has been around since the first basic electronic navigation systems

	if((abs(error)) <= 10) //deadzone
	{
		//nothing
	}
	else
	{
		portDriveTrain(speed + (Kp * error)); //Subtract or add to the value speed, the error multplied by its weight (Kp)
		starboardDriveTrain(speed + (Kp * (error * -1))); //Subtract or add to the value speed, the error multplied by its weight (Kp)
	}
}
