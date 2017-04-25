#include <exception>
#include <queue>
using namespace std;


class restaurant{
public:
	restaurant(double arrival, int size, double orderTime, double payTime, double deliverTime){
		arrivalInterval = arrival;
		meanOrderSize = size;
		meanOrderTime = orderTime;
		meanPayTime = payTime;
		processTime = deliverTime;
	}
	station orderStation;
	station paymentStation;
	station pickupStation;
private:
	double arrivalInterval;
	int meanOrderSize;
	double meanOrderTime;
	double meanPayTime;
	double processTime;

	{
public:
	
	//
	// add a new eventNotice to the next eventNotice list (i.e. priority_queue )
	//
	void schedule( eventNotice* evt )
	{
		// implement
		eventQueue.push(evt);
	}

	//
	// start processing eventNotices and keep going until the next eventNotice list is empty
	//
	void simulate()
	{
		// implement
		while (!eventQueue.empty()){
		clock.time(eventQueue.top()->eventTime());
		cout << "time: " << setw(10) << setprecision(2) << right << eventQueue.top()->eventTime() << setw(5) << 
			"  eventNotice type: " << setw(5) << eventQueue.top()->eventType() << endl;
		delete eventQueue.top();
		eventQueue.pop();
		}
	}
protected:
	 priority_queue<eventNotice*, deque<eventNotice*>, event_compare> eventQueue;
	 simClock clock;
};
};