#ifndef _BURGERJOINT
#define _BURGERJOINT

#include <exception>
#include <queue>
using namespace std;


class customer{
public:
	customer(int foodSize)
	{
		orderSize = foodSize;
		totalTime = 0.0;
		custNum++;
	}
	int getOrderSize(){
		return orderSize;
	}
	void increaseTime(double time){
		if (time < 0.0)
		{
			throw exception("ERROR: Delorean not found, Marty.  We can't go back in time.");
		}
		totalTime += time;
	}
	double getTotalTime(){
		return totalTime;
	}
	static int custNum;
private:
	int orderSize;
	double totalTime;
};
class station{
public:
	queue<customer> line;
	bool busy = false;
};
class restaurant{
public:
	restaurant()
	{
	}
	station orderStation;
	station paymentStation;
	station pickupStation;
private:
	const double arrivalInterval = 60;
	const int meanOrderSize = 5;
	const double meanOrderTime = 10;
	const double meanPayTime = 30;
	const double processTime = 15;

};
#endif