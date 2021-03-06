#pragma config(Sensor, in6,    portReflector,  sensorLineFollower)
#pragma config(Sensor, in7,    masterReflector, sensorLineFollower)
#pragma config(Sensor, in8,    starboardReflector, sensorLineFollower)
#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl11, sternSwitch,    sensorTouch)
#pragma config(Sensor, dgtl12, bumpSwitch,     sensorTouch)
#pragma config(Motor,  port1,           starboardAft,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port8,           starboardFore, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           portAft,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          portFore,      tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drivetrain.h" //include the drivetrain header
#include "../../../libraries/init.h" //Include init.h, init.h also includes void startup();
#include "../../../libraries/lineFollowing.h" //the line folowing library team 3 made!

int  threshold = 2400;
int var = 0;

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

task main()
{
	while(true)
	{
		startup(bumpSwitch, LED);
		findLine(); //our first task is to find where the line is, duh, so we can follow it!

		//while(SensorValue[masterReflector] >= threshold)

		while(true) //keep running this loop
		{
			if(SensorValue[sonar] >= 4 || SensorValue[sonar] == -1) //if we're not in sonar range, keep running the line PID
			{
				if(SensorValue[masterReflector] > threshold || SensorValue[starboardReflector] > threshold || SensorValue[portReflector] > threshold)
				{
					while(var < 100)
					{
						linePID(starboardReflector, masterReflector, portReflector, starboardAft, portAft, LED, 21, 0.0078); //run the PID loop with format (SPEED, STATUSLIGHT, P, I, D)
						var++;
					}
					var = 0;
				}
				else //otherwise
				{
					//starboardDriveTrain(SensorValue[sonar] * -12); //reverse using a magic P value
					//portDriveTrain(SensorValue[sonar] * -12);
					standard(-15);
					delay(150);
					SensorValue[LED] = true;
				}
			}
		}
	}
}
