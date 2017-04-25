#include <iostream>
#include <iomanip>

#include "simClock.h"
#include "random.h"
#include "burgerjoint.h"
#include "eventNotice.h"
#include "simulator.h"

using namespace std;

// static class variable must be initialized once globally

// initialize the simClock to some intialize value
double simClock::now = 0.0;

// initialize the five streams of random numbers
unsigned int randomVariable::seed = 463782;

void main()
{
	// demonstrate the simClock

	// create a simClock
	simClock c1;

	// update the clock
	c1.time( 10.0 );

	// get current time
	cout << "c1 time: " << c1.time() << endl;

	// create another clock
	simClock c2;

	// get current time
	cout << "c2 time: " << c2.time() << endl;

	// reset (all) clocks to a new start time
	simClock::intializeClock( 0.0 );

	// get current time
	cout << "c1 time: " << c1.time() << endl;

	// get current time
	cout << "c2 time: " << c2.time() << endl;



	// demonstrate randomStream

	randomVariable rng;

	cout << "Generate unsigned integer values: " << endl;
	for ( int i = 0; i < 5; i++ )
	{
		cout << setw(3) << i << ":  " << rng.random() << endl;
	}
	cout << endl;

	cout << "Generate discreteUniform values in [1,10]: " << endl;
	for ( int i = 0; i < 5; i++ )
	{
		cout << setw(3) << i << ":  " << rng.discreteUniform(1,10) << endl;
	}
	cout << endl;

	
	cout << "Generate uniform values in [5.0,15.0]: " << endl;
	for ( int i = 0; i < 5; i++ )
	{
		cout << setw(3) << i << ":  " << rng.uniform(5.0,15.0) << endl;
	}
	cout << endl;

	cout << "Generate exponentially distributed values with mean of 3.0: " << endl;
	for ( int i = 0; i < 5; i++ )
	{
		cout << setw(3) << i << ":  " << rng.exponential(3.0) << endl;
	}
	cout << endl;

		cout << "Generate poisson distributed values with mean of 15: " << endl;
	for ( int i = 0; i < 5; i++ )
	{
		cout << setw(3) << i << ":  " << rng.poisson(15) << endl;
	}
	cout << endl;
	cout << "---------------------------------------------------" << endl;

	
	simClock::intializeClock( 0.0 );
//NOTE: assuming whole numbers are seconds because it's ridiculous to do it any other way
	restaurant mcd(60,5,10,30,15);
	simulator::schedule(eventNotice(0.0, ARRIVAL_EVENT));
	



}