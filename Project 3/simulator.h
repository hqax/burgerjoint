/*
Spencer Bryant
CS 242
Dr Rizki
TA - Brian Jackson
*/
#ifndef _SIMULATOR

#define _SIMULATOR

#include <queue>
#include <string>

#include "simClock.h"
#include "eventNotice.h"
#include "burgerjoint.h"
#include "random.h"

using namespace std;

class simulator
{
public:
	restaurant mcd;
	const int closingTime = 14400;
	void arrival()
	{
		mcd.orderStation.busy = true;
		//create customer
		customer a(randomVariable::poisson(5));
		//add to queue
		mcd.orderStation.line.push(a);
		//if at front, create new FinishOrder event
		if (mcd.orderStation.line.front() == a){
			schedule(eventNotice(a.getOrderSize() * mcd.meanOrderTime, FINISH_ORDER);
		}
		//if store not closed, make new arrival
		if (clock.time() < closingTime)
		{
			schedule(eventNotice(clock.time() + mcd.arrivalInterval, ARRIVAL_EVENT);
		}
		
	}
	void finishOrder()
	{
		//implement
		//move from one line to the next
		&customer a;
		if (!mcd.orderStation.line.empty() && mcd.paymentStation.line.size() < 3)
		{
			a = mcd.orderStation.line.front();
			mcd.paymentStation.line.push(mcd.orderStation.line.front());			
			mcd.orderStation.line.pop();
		}
			//if at front, create new finishPayment event
			if (mcd.paymentStation.line.front() == a)
			{
				schedule(eventNotice(clock.time() + (a.getOrderSize() * mcd.meanPayTime), FINISH_PAYMENT);
			}
			schedule(eventNotice(mcd.orderStation.line.front().getOrderSize() * mcd.meanOrderTime, FINISH_ORDER);
		mcd.orderStation.busy = false;
	}
	void finishPayment()
	{
		//implement
	}
	void finishPickup()
	{
		//implement
	}

	decideProcess(eventNotice* evt)
	{
		if (evt->eventType() == ARRIVAL_EVENT)
		{
			arrival();
		}
		else if (evt->eventType() == FINISH_ORDER)
		{
			finishOrder();
		}
		else if (evt->eventType() == FINISH_PAYMENT)
		{
			finishPayment();
		}
		else if (evt->eventType() == FINISH_PICKUP)
		{
			finishPickup();
		}

	}
	// add a new eventNotice to the next eventNotice list (i.e. priority_queue )
	void schedule( eventNotice* evt )
	{
		eventQueue.push(evt);
	}

	// start processing eventNotices and keep going until the next eventNotice list is empty
	void simulate()
	{
		
		while (!eventQueue.empty()){
		clock.time(eventQueue.top()->eventTime());
		//process queue item
		decideProcess(eventQueue.top());
		
		//cout << "time: " << setw(10) << setprecision(2) << right << eventQueue.top()->eventTime() << setw(5) << 
		//	"  eventNotice type: " << setw(5) << eventQueue.top()->eventType() << endl;
		delete eventQueue.top();
		eventQueue.pop();
		}
	}
protected:
	 priority_queue<eventNotice*, deque<eventNotice*>, event_compare> eventQueue;
	 simClock clock;
};

#endif
