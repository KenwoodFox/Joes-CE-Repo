/* This function will bring the shooting bar
 * all the way to the top, ready to fire
 */

void zero(char limitMax, char servoMotor)
{
	while(SensorValue[limitMax] == 0)
	{
		motor[servoMotor] = 70;
		delay(10);
	}
}
