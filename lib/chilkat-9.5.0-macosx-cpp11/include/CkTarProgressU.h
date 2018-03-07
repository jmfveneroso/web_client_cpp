// CkTarProgress.h: interface for the CkTarProgress class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKTARPROGRESSU_H
#define _CKTARPROGRESSU_H

#include "CkBaseProgressU.h"

#include "ck_inttypes.h"

// When creating an application class that inherits the CkTarProgressU base class, use the CK_TARPROGRESSU_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkTarProgressU
    {
	public:
	    CK_TARPROGRESSU_API

	...
    };
*/
#define CK_TARPROGRESSU_API \
	void NextTarFile(const uint16_t *path, __int64 fileSize,bool bIsDirectory, bool *skip);


#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


class CkTarProgressU : public CkBaseProgressU 
{
    public:
	CkTarProgressU() { }
	virtual ~CkTarProgressU() { }


	// These event callbacks are now defined in CkBaseProgressU.
	//virtual void PercentDone(int pctDone, bool *abort) { }
	//virtual void AbortCheck(bool *abort) { }
	//virtual void ProgressInfo(const uint16_t *name, const uint16_t *value) { }

	// Called just before appending to TAR when writing a .tar, and just before
	// extracting during untar.
	virtual void NextTarFile(const uint16_t *path, 
	    __int64 fileSize,
	    bool bIsDirectory, 
	    bool *skip) { }

};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
