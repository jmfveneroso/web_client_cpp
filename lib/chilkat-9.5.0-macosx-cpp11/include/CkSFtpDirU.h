// CkSFtpDirU.h: interface for the CkSFtpDirU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkSFtpDirU_H
#define _CkSFtpDirU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkSFtpFileU;
class CkTaskU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkSFtpDirU
class CK_VISIBLE_PUBLIC CkSFtpDirU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkSFtpDirU(const CkSFtpDirU &);
	CkSFtpDirU &operator=(const CkSFtpDirU &);

    public:
	CkSFtpDirU(void);
	virtual ~CkSFtpDirU(void);

	static CkSFtpDirU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of entries in this directory listing.
	int get_NumFilesAndDirs(void);

	// The original path used to fetch this directory listing. This is the string that
	// was originally passed to the OpenDir method when the directory was read.
	void get_OriginalPath(CkString &str);
	// The original path used to fetch this directory listing. This is the string that
	// was originally passed to the OpenDir method when the directory was read.
	const uint16_t *originalPath(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the Nth filename in the directory (indexing begins at 0).
	bool GetFilename(int index, CkString &outStr);
	// Returns the Nth filename in the directory (indexing begins at 0).
	const uint16_t *getFilename(int index);
	// Returns the Nth filename in the directory (indexing begins at 0).
	const uint16_t *filename(int index);

	// Returns the Nth entry in the directory. Indexing begins at 0.
	// The caller is responsible for deleting the object returned by this method.
	CkSFtpFileU *GetFileObject(int index);

	// Loads the SFTP directory object from a completed asynchronous task.
	bool LoadTaskResult(CkTaskU &task);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
