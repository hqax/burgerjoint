/*
Spencer Bryant
CS 242
Dr Rizki
TA - Brian Jackson
*/
#ifndef _EVENT

#define _EVENT

#include <string>

using namespace std;

class eventNotice
{
public:
	enum eventCat {ARRIVAL_EVENT, FINISH_ORDER, FINISH_PAYMENT, FINISH_PICKUP};

	// construct the base event object
	eventNotice( double time, eventCat type)
	{
		m_time = time;
		m_type = type;
	}

	// get the time of the event
	double eventTime() const
	{
		return m_time;
	}

	// get the name (type) of the event
	virtual eventCat eventType()
	{
		return m_type;
	}
	
	// compare to events based on event time
	bool operator>( const eventNotice& evt ) const
	{
		return (eventTime() > evt.eventTime());
	}

	friend class event_compare;

private:
	double	m_time;
	eventCat m_type;
};

// define a compare class for use in the priority queue (see class simulator in simulator.h)
class event_compare
{
public:
	// overload operator() to perform the comparison
	bool operator() ( eventNotice*& first, eventNotice*& second ) const
	{
		// call operator> in class event
		return (*first) > (*second);
	}
};

#endif

