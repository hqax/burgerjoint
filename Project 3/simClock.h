#ifndef _SIMCLOCK

#define _SIMCLOCK

class simClock
{

public:

	static void intializeClock( double tm = 0.0 )
	{
		now = tm;
	}

	double time()
	{
		return now;
	}

	void time( double tm )
	{
		now = tm;
	}

protected:

	static double now;
};

#endif
