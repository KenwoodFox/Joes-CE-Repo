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

void linePID(int speed, char statusLight) //serious maths
{
	float Kp = 0.005; //proportional
	//float Ki = 0.05; //integral
	//float Kd = 0.05; //derivative

	float error = SensorValue[starboardReflector] - SensorValue[portReflector]; //rescan the error
	
	/* In a PID loop, the goal is to aproach the target, but not overshoot it, a good PID loop can swoosh right to the target, 
	 * while many others simply just, rush past it and come back right after, this mathamtical form of position control has been
	 * around since the first basic electronic navigation systems
	 */

if((abs(error)) <= 100) //While the absolute value of the error (pos || neg) is less than the deadzone, do nothing, just drive ahead
	{
		SensorValue[statusLight] = true; //Turn on the LED while tracking center
		portDriveTrain(speed); //drive at speed
		starboardDriveTrain(speed); //drive at speed
		/* It is well understood that the motors very often do not drive at the same rate, so its likely we'll wobble or hug one side of 
		 * line, this is not all that bad tbh
		 */
	}
	else //In the case of being in error (Never gonna happen ik), do the following
	{
		SensorValue[statusLight] = false; //turn off the light
		portDriveTrain(speed + (Kp * error)); //Subtract or add to the value speed, the error multplied by its weight (Kp)
		starboardDriveTrain(speed + (Kp * (error * -1))); //Subtract or add to the value speed, the error multplied by its weight (Kp)
	}
}
