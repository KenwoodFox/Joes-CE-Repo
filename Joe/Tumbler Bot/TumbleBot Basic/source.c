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

task main()
{
	while(true) //forever
	{

		startup(); //run the startup void

		easyGas(0, 100, 10, 1); //Accelerate from 0, to 100, in time increments of 10ms, forward.
		delay(1228); //magic delay for the leangth of the
		easyGas(100, 0, 15, -1);	//Accelerate from 100, to 0, in time increments of 15ms, backward.
	}
}