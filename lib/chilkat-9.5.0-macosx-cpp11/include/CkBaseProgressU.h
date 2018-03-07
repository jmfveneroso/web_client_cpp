// CkBaseProgressU.h: interface for the CkBaseProgressU class.
//
//////////////////////////////////////////////////////////////////////

// This is NOT a generated source..
// This is NOT a generated source..
// This is NOT a generated source..
// This is NOT a generated source..

#ifndef _CKBASEPROGRESSU_H
#define _CKBASEPROGRESSU_H

#include "CkObject.h"

#if !defined(BOOL_IS_TYPEDEF) && !defined(OBJC_BOOL_DEFINED)
#ifndef BOOL
#define BOOL int
#endif
#endif

#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 
class CkTaskU;

// When creating an application class that inherits the CkBaseProgressU base class, use the CK_BASEPROGRESSU_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkBaseProgressU
    {
	public:
	    CK_BASEPROGRESSU_API

	...
    };
*/
#define CK_BASEPROGRESSU_API \
    void AbortCheck(bool *abort);\
    void PercentDone(int pctDone, bool *abort);\
    void ProgressInfo(const uint16_t *name, const uint16_t *value);\
    void TextData(const uint16_t *data);\
    void BinaryData(const unsigned char *data, unsigned int numBytes);\
    void TaskIdCompleted(int taskId);\
    void TaskCompleted(CkTaskU &task);

class CkBaseProgressU : public CkObject 
{
    private:
	void *m_impl;

	// No copy constructor or assignment allowed..
	CkBaseProgressU(const CkBaseProgressU &);
	CkBaseProgressU &operator=(const CkBaseProgressU &);

    public:
	CkBaseProgressU();
	virtual ~CkBaseProgressU();

	// This method is for internal use only.
	void *getProgressImpl(void);

	// Called periodically to check to see if the method call should be aborted.
	// The HeartbeatMs property controls the frequency of AbortCheck callbacks.
	virtual void AbortCheck(bool *abort) { }

	// Called to indicate the current percentage completed for a method call.
	// PercentDone callbacks only happen where it makes sense and where it's possible.
	// Not all methods will have PercentDone callbacks.
	virtual void PercentDone(int pctDone, bool *abort) { }

	// Open-ended callback where the name indicates the type of information provided.
	// The ProgressInfo callbacks depend on the method. 
	// To see what information is provided in ProgressInfo callbacks for any particular method,
	// if any, create a callback handler to log the callbacks for testing purposes.
	// Virtually all ProgressInfo callbacks should be self-explanatory.
	virtual void ProgressInfo(const uint16_t *name, const uint16_t *value) { }


	// One of the following is fired depending on which is set.
	// One passes a reference to the CkTaskU object itself. 
	// The other passes just the unique task ID.

	// Called when an asynchronous task completes, is aborted, canceled, etc.
	virtual void TaskCompleted(CkTaskU &task);

	// Called when an asynchronous task completes, is aborted, canceled, etc.
	virtual void TaskIdCompleted(int taskId) { }
	
	
	virtual void TextData(const uint16_t *data) { }
	virtual void BinaryData(const unsigned char *data, unsigned int numBytes) { }
};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
