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
	float Kp = 0.012; //proportional
	//float Ki = 0.05; //integral
	//float Kd = 0.05; //derivative
	int threshold = 400; //The value at witch we can differ a black line from a white table, we could make this a self calibrating value!!

	float error = SensorValue[starboardReflector] - SensorValue[portReflector]; //rescan the error

	/* In a PID loop, the goal is to aproach the target, but not overshoot it, a good PID loop can swoosh right to the target,
	* while many others simply just, rush past it and come back right after, this mathamtical form of position control has been
	* around since the first basic electronic navigation systems
	*/

	if((abs(error)) <= 10) //While the absolute value of the error (pos || neg) is less than the deadzone, do nothing, just drive ahead
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
		starboardDriveTrain(speed + (Kp * error)); //Subtract or add to the value speed, the error multplied by its weight (Kp)
		portDriveTrain(speed + (Kp * (error * -1))); //Subtract or add to the value speed, the error multplied by its weight (Kp)
		/* we've multiplied the weight(kp) by error, but the error number is negative in the starboard side so that we can stray backwards
		 * and away from the line when we impact it on the corrosponding side
		 */

		if(SensorValue[masterReflector] >= threshold && error <= 100)
		{
			SensorValue[LED] = true; //LED on
			/* Just a test, if the value of master reflector is greater than the threshold AND the error is less than a number
			 * to code, this would mean that we are on white, it knows this beacuse A; the error is very low, witch means both 
			 * sensors port and starboard are displaying very similar values AND B; we know we're not just on the line by reading 
			 * that the value of the master sensor is not black, so we can determine that we are not on the line. Could this code
			 * be simplified? maybe if we look for a total error between all three, being on white would display a net error of a
			 * low number.
			 */
		}
	}
}
