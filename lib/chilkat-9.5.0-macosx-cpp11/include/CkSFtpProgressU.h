// CkSFtpProgress.h: interface for the CkSFtpProgress class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKSFTPPROGRESSU_H
#define _CKSFTPPROGRESSU_H

#include "CkBaseProgressU.h"

// When creating an application class that inherits the CkSFtpProgressU base class, use the CK_SFTPPROGRESSU_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkSFtpProgressU
    {
	public:
	    CK_SFTPPROGRESSU_API

	...
    };
*/
#define CK_SFTPPROGRESSU_API \
	void UploadRate(__int64 byteCount, unsigned long bytesPerSec);\
	void DownloadRate(__int64 byteCount, unsigned long bytesPerSec);


#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif

class CkSFtpProgressU : public CkBaseProgressU 
{
    public:
	CkSFtpProgressU() { }
	virtual ~CkSFtpProgressU() { }

	// These event callbacks are now defined in CkBaseProgressU.
	//virtual void PercentDone(int pctDone, bool *abort) { }
	//virtual void AbortCheck(bool *abort) { }
	//virtual void ProgressInfo(const uint16_t *name, const uint16_t *value) { }

	virtual void UploadRate(__int64 byteCount, unsigned long bytesPerSec) { }
	virtual void DownloadRate(__int64 byteCount, unsigned long bytesPerSec) { }


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
