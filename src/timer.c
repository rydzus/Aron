#include "aron.h"
#include "timer.h"

void p1_speed_func()
{
	p1_speed=1;
}

void p2_speed_func()
{
	p2_speed=1;
}

void speed_func()
{
	if(speed-1 > minspeed)
	{
		speed--;
		install_int_ex(p1_speed_func, MSEC_TO_TIMER(speed));
		install_int_ex(p2_speed_func, MSEC_TO_TIMER(speed));
	}
}
LOCK_VARIABLE(p1_speed);
LOCK_FUNCTION(p1_speed_func);
LOCK_VARIABLE(p2_speed);
LOCK_FUNCTION(p2_speed_func);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(speed_func);
