#ifndef EVENT_H
#define EVENT_H


class Event
{
public:
	virtual ~Event(){}

	enum EVENT_TYPE {
		None
	  , Collision
	  , Input
	};

public:
	EVENT_TYPE getEventType() { return mEventType; }

protected:
	EVENT_TYPE mEventType;
};

#endif