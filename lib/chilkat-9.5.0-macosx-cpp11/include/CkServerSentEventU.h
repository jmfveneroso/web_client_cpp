// CkServerSentEventU.h: interface for the CkServerSentEventU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkServerSentEventU_H
#define _CkServerSentEventU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkServerSentEventU
class CK_VISIBLE_PUBLIC CkServerSentEventU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkServerSentEventU(const CkServerSentEventU &);
	CkServerSentEventU &operator=(const CkServerSentEventU &);

    public:
	CkServerSentEventU(void);
	virtual ~CkServerSentEventU(void);

	static CkServerSentEventU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The data for the server-side event. (If the "data" field was empty, then this
	// will be empty.)
	void get_Data(CkString &str);
	// The data for the server-side event. (If the "data" field was empty, then this
	// will be empty.)
	const uint16_t *data(void);

	// The name of the server-side event. (If the "event" field was not present, then
	// this will be empty.)
	void get_EventName(CkString &str);
	// The name of the server-side event. (If the "event" field was not present, then
	// this will be empty.)
	const uint16_t *eventName(void);

	// The content of the "id" field, if present.
	void get_LastEventId(CkString &str);
	// The content of the "id" field, if present.
	const uint16_t *lastEventId(void);

	// The integer value of the "retry" field, if present. Otherwise 0.
	int get_Retry(void);



	// ----------------------
	// Methods
	// ----------------------
	// Loads the multi-line event text into this object. For example, the eventText for a
	// Firebase event might look like this:
	// event: put
	// data: {"path": "/c", "data": {"foo": true, "bar": false}}
	bool LoadEvent(const uint16_t *eventText);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
