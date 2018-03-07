// CkLogU.h: interface for the CkLogU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkLogU_H
#define _CkLogU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkLogU
class CK_VISIBLE_PUBLIC CkLogU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkLogU(const CkLogU &);
	CkLogU &operator=(const CkLogU &);

    public:
	CkLogU(void);
	virtual ~CkLogU(void);

	static CkLogU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------


	// ----------------------
	// Methods
	// ----------------------
	// Clears the log. The initialTag is the initial top-level context tag for the new log.
	void Clear(const uint16_t *initialTag);

	// Enters a new context labelled with the given tag. Must be paired with a matching
	// call to LeaveContext.
	void EnterContext(const uint16_t *tag);

	// Leaves the current context. A context that is entered and exited without any
	// logging within the context is automatically removed from the log. (To say it
	// another way: Empty contexts are automaticallly removed from the log upon leaving
	// the context.)
	void LeaveContext(void);

	// Adds a tagged message to the log (i.e. a name/value pair).
	void LogData(const uint16_t *tag, const uint16_t *message);

	// Logs binary data in base64 format.
	void LogDataBase64(const uint16_t *tag, CkByteData &data);

	// Logs binary data in hex format.
	void LogDataHex(const uint16_t *tag, CkByteData &data);

	// Logs a string, but only up to the 1st maxNumChars characters of the string.
	void LogDataMax(const uint16_t *tag, const uint16_t *message, int maxNumChars);

	// Logs the current date/time in RFC822 format. If gmt is true, then the GMT/UTC
	// time is logged. Otherwise it is the local time.
	void LogDateTime(const uint16_t *tag, bool gmt);

	// Logs an error within the current context.
	void LogError(const uint16_t *message);

	// Logs an informational message within the current context.
	void LogInfo(const uint16_t *message);

	// Logs an integer.
	void LogInt(const uint16_t *tag, int value);

	// Logs a 64-bit integer.
	void LogInt64(const uint16_t *tag, __int64 value);

	// Logs the current time in HH:MM:SS:mmm format.
	void LogTimestamp(const uint16_t *tag);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
