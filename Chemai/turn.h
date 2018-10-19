void turnleft()
{
wait(1);
	startMotor(Backleft, 44);
	startMotor(Backright, -44);
	startMotor(Frontleft, 44);
	startMotor(Frontright, -44);
	wait(3);
}




void turnright()
{
	wait(1);
	startMotor(Backleft, -44);
	startMotor(Backright, 44);
	startMotor(Frontleft, -44);
	startMotor(Frontright, 44);
	wait(3);
}




void tankDrive(int driveTime)
{
	wait(1);
	startMotor(Backleft, 44);
	startMotor(Backright, -44);
	startMotor(Frontleft, 44);
	startMotor(Frontright, -44);
	wait(driveTime);

	stopMotor(Backleft);
	stopMotor(Backright);
	stopMotor(Frontleft);
	stopMotor(Frontright);
}

