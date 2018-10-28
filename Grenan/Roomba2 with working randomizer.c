#pragma config(Sensor, dgtl12,  bowBump,     sensorTouch)
#pragma config(Sensor, dgtl3,  ledINIT,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  led2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl9, led3,           sensorLEDtoVCC)
#pragma config(Motor,  port6,           starboardFWD,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           starboardBACK, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           portFWD,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           portBACK,      tmotorServoContinuousRotation, openLoop)
/*
Project Title: Roomba
Team Members: Grennon, Kyle, Pat, Buddy
Date: 10/22/2018
Section: Block C

Task Description: Make a roomba that turns when it hits stuff

Pseudocode:
Make the robot move forward until bowBump is pressed
Then have the code move robot backwards and spin for an amt of time that is determined by a wait comand with a random Int inside of it
We might put it in a while loop this way it runs contunuiously
*/

void motorStop(){
	stopMotor(portBACK);
	stopMotor(starboardBACK);
	stopMotor(starboardFWD);
	stopMotor(portFWD);
}
void backOff(){
	int left_or_right;
	left_or_right = rand() % 2;
	motorStop();
	wait(0.5);
	startMotor(portFWD, 43);
	startMotor(portBACK, 43);
	startMotor(starboardFWD, -42);
	startMotor(starboardFWD, -42);
	wait(1);
	motorStop();
	if(left_or_right == 0){
		startMotor(portFWD, -43);
		startMotor(portBACK, -43);
		startMotor(starboardFWD, -42);
		startMotor(starboardFWD, -42);
		wait(2);
		motorStop();

	}
	if(left_or_right == 1){
		startMotor(portFWD, 43);
		startMotor(portBACK, 43);
		startMotor(starboardFWD, 42);
		startMotor(starboardFWD, 42);
		wait(2);
		motorStop();
	}

}

task main(){
	wait(5);
	while(1 == 1){
		startMotor(portFWD, -43);
		startMotor(portBACK, -43);
		startMotor(starboardFWD, 42);
		startMotor(starboardFWD, 42);

		if(SensorValue[bowBump] == 1){
			backOff();

		}
	}
}
