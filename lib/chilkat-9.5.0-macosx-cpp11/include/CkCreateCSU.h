// CkCreateCSU.h: interface for the CkCreateCSU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCreateCSU_H
#define _CkCreateCSU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkCertStoreU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCreateCSU
class CK_VISIBLE_PUBLIC CkCreateCSU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCreateCSU(const CkCreateCSU &);
	CkCreateCSU &operator=(const CkCreateCSU &);

    public:
	CkCreateCSU(void);
	virtual ~CkCreateCSU(void);

	static CkCreateCSU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// Determines whether certificate stores are opened with read-only or read/write
	// permissions. Only applies to methods such as OpenCurrentUserStore, where the a
	// readOnly parameter is not present.
	bool get_ReadOnly(void);
	// Determines whether certificate stores are opened with read-only or read/write
	// permissions. Only applies to methods such as OpenCurrentUserStore, where the a
	// readOnly parameter is not present.
	void put_ReadOnly(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Creates a file-based certificate store. If 'filename' already exists, the method
	// will fail.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *CreateFileStore(const uint16_t *path);

	// Creates a temporary certificate store in memory that is initially empty.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *CreateMemoryStore(void);

	// Creates a registry-based certificate store. The 'hiveName' can either be
	// "CurrentUser" or "LocalMachine". The 'regPath' argument should be specified
	// without a leading slash, such as "Software/Chilkat/MyCertStore".
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *CreateRegistryStore(const uint16_t *regRoot, const uint16_t *regPath);

	// Opens the certificate store used by Chilkat Mail and returns the object
	// representing that store.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenChilkatStore(void);

	// Opens the local system's Current User Certificate Store and returns the object
	// representing that store.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenCurrentUserStore(void);

	// Opens an existing file certificate store. To open it read-only, readOnly should
	// be non-zero.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenFileStore(const uint16_t *path);

	// Opens the local system's Local Machine Certificate Store and returns the object
	// representing that store.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenLocalSystemStore(void);

	// Opens the certificate store used by Microsoft Outlook (and Office) and returns
	// the object representing that store.
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenOutlookStore(void);

	// Opens an existing registry-based certificate store. 'hiveName' should be either
	// "CurrentUser" or "LocalMachine". The 'regPath' argument should be specified
	// without a leading slash, such as "Software/Chilkat/MyCertStore".
	// The caller is responsible for deleting the object returned by this method.
	CkCertStoreU *OpenRegistryStore(const uint16_t *regRoot, const uint16_t *regPath);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
