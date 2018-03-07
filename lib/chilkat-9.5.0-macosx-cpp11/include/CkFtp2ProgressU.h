// CkFtpProgressU.h: interface for the CkFtpProgress class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKFTP2PROGRESSU_H
#define _CKFTP2PROGRESSU_H


#include "CkBaseProgressU.h"

/*

  To receive progress events (callbacks), create a C++ class that 
  inherits this one and provides one or more overriding implementations 
  for the events you wish to receive.

  */

// When creating an application class that inherits the CkFtp2ProgressU base class, use the CK_FTP2PROGRESSU_API 
// definition to declare the overrides in the class header.  This has the effect that if for
// some unforeseen and unlikely reason the Chilkat event callback API changes, or if new
// callback methods are added in a future version, then you'll discover them at compile time
// after updating to the new Chilkat version.  
// For example:
/*
    class MyProgress : public CkFtp2ProgressU
    {
	public:
	    CK_FTP2PROGRESSU_API

	...
    };
*/
#define CK_FTP2PROGRESSU_API \
	void BeginDownloadFile(const uint16_t *pathUtf8, bool *skip);\
	void EndDownloadFile(const uint16_t *pathUtf8, __int64 numBytes);\
	void VerifyDownloadDir(const uint16_t *pathUtf8, bool *skip);\
	void BeginUploadFile(const uint16_t *pathUtf8, bool *skip);\
	void EndUploadFile(const uint16_t *pathUtf8, __int64 numBytes);\
	void VerifyUploadDir(const uint16_t *pathUtf8, bool *skip);\
	void VerifyDeleteDir(const uint16_t *pathUtf8, bool *skip);\
	void VerifyDeleteFile(const uint16_t *pathUtf8, bool *skip);\
	void UploadRate(__int64 byteCount, unsigned long bytesPerSec);\
	void DownloadRate(__int64 byteCount, unsigned long bytesPerSec);


#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif

class CkFtp2ProgressU : public CkBaseProgressU
{
    public:

	CkFtp2ProgressU() { }
	virtual ~CkFtp2ProgressU() { }

	virtual void BeginDownloadFile(const uint16_t *pathUtf8, bool *skip) { }
	virtual void EndDownloadFile(const uint16_t *pathUtf8, __int64 numBytes) { }
	virtual void VerifyDownloadDir(const uint16_t *pathUtf8, bool *skip) { }

	virtual void BeginUploadFile(const uint16_t *pathUtf8, bool *skip) { }
	virtual void EndUploadFile(const uint16_t *pathUtf8, __int64 numBytes) { }
	virtual void VerifyUploadDir(const uint16_t *pathUtf8, bool *skip) { }

	virtual void VerifyDeleteDir(const uint16_t *pathUtf8, bool *skip) { }
	virtual void VerifyDeleteFile(const uint16_t *pathUtf8, bool *skip) { }

	virtual void UploadRate(__int64 byteCount, unsigned long bytesPerSec) { }
	virtual void DownloadRate(__int64 byteCount, unsigned long bytesPerSec) { }



};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
