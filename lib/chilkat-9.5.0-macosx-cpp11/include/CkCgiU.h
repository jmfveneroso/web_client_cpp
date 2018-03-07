// CkCgiU.h: interface for the CkCgiU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCgiU_H
#define _CkCgiU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCgiU
class CK_VISIBLE_PUBLIC CkCgiU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCgiU(const CkCgiU &);
	CkCgiU &operator=(const CkCgiU &);

    public:
	CkCgiU(void);
	virtual ~CkCgiU(void);

	static CkCgiU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------

	int get_AsyncBytesRead(void);


	bool get_AsyncInProgress(void);


	int get_AsyncPostSize(void);


	bool get_AsyncSuccess(void);


	int get_HeartbeatMs(void);

	void put_HeartbeatMs(int newVal);


	int get_IdleTimeoutMs(void);

	void put_IdleTimeoutMs(int newVal);


	int get_NumParams(void);


	int get_NumUploadFiles(void);


	int get_ReadChunkSize(void);

	void put_ReadChunkSize(int newVal);


	int get_SizeLimitKB(void);

	void put_SizeLimitKB(int newVal);


	bool get_StreamToUploadDir(void);

	void put_StreamToUploadDir(bool newVal);


	void get_UploadDir(CkString &str);

	const uint16_t *uploadDir(void);

	void put_UploadDir(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------

	void AbortAsync(void);

#if defined(WIN32) && !defined(SINGLE_THREADED)

	bool AsyncReadRequest(void);
#endif


	bool GetEnv(const uint16_t *varName, CkString &outStr);

	const uint16_t *getEnv(const uint16_t *varName);

	const uint16_t *env(const uint16_t *varName);


	bool GetParam(const uint16_t *paramName, CkString &outStr);

	const uint16_t *getParam(const uint16_t *paramName);

	const uint16_t *param(const uint16_t *paramName);


	bool GetParamName(int index, CkString &outStr);

	const uint16_t *getParamName(int index);

	const uint16_t *paramName(int index);


	bool GetParamValue(int index, CkString &outStr);

	const uint16_t *getParamValue(int index);

	const uint16_t *paramValue(int index);


	bool GetRawPostData(CkByteData &outData);


	bool GetUploadData(int index, CkByteData &outData);


	bool GetUploadFilename(int index, CkString &outStr);

	const uint16_t *getUploadFilename(int index);

	const uint16_t *uploadFilename(int index);


	int GetUploadSize(int index);


	bool IsGet(void);


	bool IsHead(void);


	bool IsPost(void);


	bool IsUpload(void);


	bool ReadRequest(void);


	bool SaveNthToUploadDir(int index);


	void SleepMs(int millisec);


	bool TestConsumeAspUpload(const uint16_t *path);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
