// CkMailManProgress.h: interface for the CkMailManProgress class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CkMailManProgressU_H
#define _CkMailManProgressU_H


#include "CkBaseProgressU.h"

/*

  To receive progress events (callbacks), create a C++ class that 
  inherits this one and provides one or more overriding implementations 
  for the events you wish to receive.  

  */

// When creating an application class that inherits the CkMailManProgressU base class, use the CK_MAILPROGRESSU_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkMailManProgressU
    {
	public:
	    CK_MAILPROGRESSU_API

	...
    };
*/
#define CK_MAILPROGRESSU_API \
	void EmailReceived(const uint16_t *subject, \
			    const uint16_t *fromAddr, const uint16_t *fromName, \
			    const uint16_t *returnPath, \
			    const uint16_t *date, \
			    const uint16_t *uidl, \
			    int sizeInBytes);

#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 
class CkMailManProgressU  : public CkBaseProgressU
{
    public:
	CkMailManProgressU() { }
	virtual ~CkMailManProgressU() { }

	// These event callbacks are now defined in CkBaseProgressU.
	//virtual void PercentDone(int pctDone, bool *abort) { }
	//virtual void AbortCheck(bool *abort) { }
	//virtual void ProgressInfo(const uint16_t *name, const uint16_t *value) { }

	virtual void EmailReceived(const uint16_t *subject, 
			    const uint16_t *fromAddr, const uint16_t *fromName, 
			    const uint16_t *returnPath, 
			    const uint16_t *date, 
			    const uint16_t *uidl, 
			    int sizeInBytes) { }


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
