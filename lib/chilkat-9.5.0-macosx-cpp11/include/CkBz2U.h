// CkBz2U.h: interface for the CkBz2U class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkBz2U_H
#define _CkBz2U_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkTaskU;
class CkByteData;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkBz2U
class CK_VISIBLE_PUBLIC CkBz2U  : public CkClassWithCallbacksU
{
    private:
	bool m_cbOwned;

	// Don't allow assignment or copying these objects.
	CkBz2U(const CkBz2U &);
	CkBz2U &operator=(const CkBz2U &);

    public:
	CkBz2U(void);
	virtual ~CkBz2U(void);

	static CkBz2U *createNew(void);
	

	CkBz2U(bool bCallbackOwned);
	static CkBz2U *createNew(bool bCallbackOwned);

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	CkBaseProgressU *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgressU *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	bool get_AbortCurrent(void);
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	void put_AbortCurrent(bool newVal);


	int get_HeartbeatMs(void);

	void put_HeartbeatMs(int newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Compresses a file to create a BZip2 compressed file (.bz2).
	bool CompressFile(const uint16_t *inFilename, const uint16_t *toPath);

	// Creates an asynchronous task to call the CompressFile method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *CompressFileAsync(const uint16_t *inFilename, const uint16_t *toPath);

	// BZip2 compresses a file to an in-memory image of a .bz2 file.
	bool CompressFileToMem(const uint16_t *inFilename, CkByteData &outBytes);

	// Creates an asynchronous task to call the CompressFileToMem method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *CompressFileToMemAsync(const uint16_t *inFilename);

	// Compresses in-memory data to an in-memory image of a .bz2 file.
	bool CompressMemory(CkByteData &inData, CkByteData &outBytes);

	// Creates an asynchronous task to call the CompressMemory method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *CompressMemoryAsync(CkByteData &inData);

	// BZip2 compresses and creates a .bz2 file from in-memory data.
	bool CompressMemToFile(CkByteData &inData, const uint16_t *toPath);

	// Creates an asynchronous task to call the CompressMemToFile method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *CompressMemToFileAsync(CkByteData &inData, const uint16_t *toPath);

	// Unzips a .bz2 file.
	bool UncompressFile(const uint16_t *inFilename, const uint16_t *toPath);

	// Creates an asynchronous task to call the UncompressFile method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UncompressFileAsync(const uint16_t *inFilename, const uint16_t *toPath);

	// Unzips a .bz2 file directly to memory.
	bool UncompressFileToMem(const uint16_t *inFilename, CkByteData &outBytes);

	// Creates an asynchronous task to call the UncompressFileToMem method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UncompressFileToMemAsync(const uint16_t *inFilename);

	// Unzips from an in-memory image of a .bz2 file directly into memory.
	bool UncompressMemory(CkByteData &inData, CkByteData &outBytes);

	// Creates an asynchronous task to call the UncompressMemory method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UncompressMemoryAsync(CkByteData &inData);

	// Unzips from an in-memory image of a .bz2 file to a file.
	bool UncompressMemToFile(CkByteData &inData, const uint16_t *toPath);

	// Creates an asynchronous task to call the UncompressMemToFile method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UncompressMemToFileAsync(CkByteData &inData, const uint16_t *toPath);

	// Unlocks the component allowing for the full functionality to be used. If a
	// purchased unlock code is passed, there is no expiration. Any other string
	// automatically begins a fully-functional 30-day trial the first time
	// UnlockComponent is called.
	bool UnlockComponent(const uint16_t *regCode);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
