void turnleft()
{
wait(1);
	startMotor(Backleft, 44);
	startMotor(Backright, -44);
	startMotor(Frontleft, 44);
	startMotor(Frontright, -44);
	wait(3);
}


void turnright(int turnDeg)
{
	wait(1);
	startMotor(Backleft, 44);
	startMotor(Backright, -44);
	startMotor(Frontleft, 44);
	startMotor(Frontright, -44);
	wait(3);
}
