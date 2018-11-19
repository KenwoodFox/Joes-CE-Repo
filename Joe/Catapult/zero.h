/* This function will bring the shooting bar
 * all the way to the top, ready to fire
 */

void zero()
{
	while(SensorValue[maxUp] == 0)
	{
		motor[servo] = 70;
		delay(10);
	}
}