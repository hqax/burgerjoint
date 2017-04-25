#ifndef _RANDOM_

#define _RANDOM_

#include <cstdlib>
#include <cmath>
#include <cassert>

class randomVariable
{
	public:

		// constructor -- set the value of the generator's seed > 0
		randomVariable()
		{
			// noop
		}

		// constructor -- set the value of the generator's seed > 0
		randomVariable( unsigned int initSeed )
		{
			seed = initSeed;
		}

		// reset the value of the generator's seeds > 0
		static void setSeed( unsigned int initSeed )
		{
			seed = initSeed;
		}

		// return a positive random integer 0...RAND_MAX
		int random()
		{
			srand( seed );
			seed = rand();
			return seed;
		}

		// return a random integer number in the interval {min, ... max}
		int discreteUniform( int min = 0, int max = 1 )
		{
			assert( min <= max );
			return min + (random() % (max - min + 1));
		}

		// return a random real number in the interval [min,max)
		double uniform( double min = 0.0, double max = 1.0 )
		{
			assert( min <= max );
			return min + (max - min) * (static_cast<double>(random()) / static_cast<double>( RAND_MAX ));
		}

		// return a Possion distrubted random variable with the given mean
		// WARNING this distribution can return a zero value
		long poisson( unsigned int mean = 1 )
		{
			double	a, b;
			int	i;

			a = exp( -static_cast<double>(mean) );
			b = 1.0;
			i = 0;

			do
			{
				b *= uniform( 0.0, 1.0 );
				i++;
			} while ( a <= b );

			return (i-1);
		}

		// return an exponentially distrubted random variable with the given mean
		double exponential( double mean )
		{
			double x;

			while ( (x = uniform( 0.0, 1.0 )) == 0 );
			return -mean * log(x);
		}


	protected:
		static unsigned int seed;
};

#endif

