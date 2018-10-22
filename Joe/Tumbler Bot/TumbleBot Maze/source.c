#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, bumpSwitch,     sensorTouch)
#pragma config(Motor,  port1,           starboardAft,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port9,           portAft,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           starboardFore, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          portFore,      tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivetrain.h" //include the drivetrain header
#include "easyGas.h" //include the easygas header
#include "init.h" //Include init.h, init.h also includes void startup();
#include "tankSpin.h" //include chemai's turn header
#include "segment.h" //include the segment command

void debug()
{
	tankSpin(90);
	delay(600);
	tankSpin(-90);
}

void unamedMaze()
{
	segment(1250); //Segment forward
	tankSpin(90); //make a left turn
	backup();

	segment(680); //Segment forward
	tankSpin(90); //make a right turn
	backup();

	segment(1200); //Segment forward
	tankSpin(-90); //make a right turn
	segment(680); //Segment forward
	tankSpin(-90); //make a right turn
	backup();

	segment(150); //Segment forward
}


task main()
{

	while(true)
	{
		startup();
		unamedMaze();
		//debug();
	}
}