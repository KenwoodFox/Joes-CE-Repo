void lockNload(char bolt, char ul, char fireMotor, int ballDia)
{
		motor[bolt] = -60;
		delay(ballDia);
		motor[bolt] = 0;
		motor[fireMotor] = 127;
		delay(5000); //Fire duration
		motor[fireMotor] = 0;
}
