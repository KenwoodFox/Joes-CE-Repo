#include "main.h"

#define OPERATION true

task main()
{
	
	
	while(OPERATION == true)
	{
		motor[portMotor] = 127;
		motor[starboardMotor] = 127;
	}
}