void blink(int numberOfBlinks, char statusLight)
{
	while(numberOfBlinks > 0)
	{
		delay(100); //wait 100ms
		SensorValue[statusLight] = true; //slow Blink
		delay(100);
		SensorValue[statusLight] = false;
		numberOfBlinks++;
	}
}
