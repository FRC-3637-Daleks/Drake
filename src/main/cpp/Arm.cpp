#include <Arm.h>
#include <math.h>

using namespace frc;

void
Arm::ArmAngles(float x, float y)
{
	float r      = sqrt(x*x + y*y);
	float ang2   = acos((40*40+32*32-r*r)/(2*40*32));
	float ang1   = acos((32*32+r*r-40*40)/(2*32*r)) + atan(y/x);
    float angle1 = ang1*180/M_PI;
    float angle2 = ang2*180/M_PI;
}

	
}