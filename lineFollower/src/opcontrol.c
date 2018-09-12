#include "main.h"

//2000 arbitrarily set as cutoff between light and dark
while(analogReadCalibrated(LINE_TRACKER_PORT) < 2000)
{
  // drive forward until a line is hit
  motorSet(DRIVE_MOTOR_LEFT,127);
  motorSet(DRIVE_MOTOR_RIGHT,127);
}
