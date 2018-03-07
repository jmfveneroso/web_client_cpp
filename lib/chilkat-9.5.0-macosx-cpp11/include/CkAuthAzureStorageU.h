// CkAuthAzureStorageU.h: interface for the CkAuthAzureStorageU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkAuthAzureStorageU_H
#define _CkAuthAzureStorageU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAuthAzureStorageU
class CK_VISIBLE_PUBLIC CkAuthAzureStorageU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkAuthAzureStorageU(const CkAuthAzureStorageU &);
	CkAuthAzureStorageU &operator=(const CkAuthAzureStorageU &);

    public:
	CkAuthAzureStorageU(void);
	virtual ~CkAuthAzureStorageU(void);

	static CkAuthAzureStorageU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// A valid base64 access key for the Azure storage account.
	void get_AccessKey(CkString &str);
	// A valid base64 access key for the Azure storage account.
	const uint16_t *accessKey(void);
	// A valid base64 access key for the Azure storage account.
	void put_AccessKey(const uint16_t *newVal);

	// The Azure storage account name. (A storage account can contain zero or more
	// containers. A container contains properties, metadata, and zero or more blobs. A
	// blob is any single entity comprised of binary data, properties, and metadata. )
	void get_Account(CkString &str);
	// The Azure storage account name. (A storage account can contain zero or more
	// containers. A container contains properties, metadata, and zero or more blobs. A
	// blob is any single entity comprised of binary data, properties, and metadata. )
	const uint16_t *account(void);
	// The Azure storage account name. (A storage account can contain zero or more
	// containers. A container contains properties, metadata, and zero or more blobs. A
	// blob is any single entity comprised of binary data, properties, and metadata. )
	void put_Account(const uint16_t *newVal);

	// Can be "SharedKey" or "SharedKeyLite". The default value is "SharedKey".
	void get_Scheme(CkString &str);
	// Can be "SharedKey" or "SharedKeyLite". The default value is "SharedKey".
	const uint16_t *scheme(void);
	// Can be "SharedKey" or "SharedKeyLite". The default value is "SharedKey".
	void put_Scheme(const uint16_t *newVal);

	// Can be "Blob", "Queue", "File", or "Table". The default is "Blob".
	void get_Service(CkString &str);
	// Can be "Blob", "Queue", "File", or "Table". The default is "Blob".
	const uint16_t *service(void);
	// Can be "Blob", "Queue", "File", or "Table". The default is "Blob".
	void put_Service(const uint16_t *newVal);

	// If set, automatically adds the "x-ms-version" HTTP request header to Azure
	// Storage requests. The default value is "2014-02-14".
	void get_XMsVersion(CkString &str);
	// If set, automatically adds the "x-ms-version" HTTP request header to Azure
	// Storage requests. The default value is "2014-02-14".
	const uint16_t *xMsVersion(void);
	// If set, automatically adds the "x-ms-version" HTTP request header to Azure
	// Storage requests. The default value is "2014-02-14".
	void put_XMsVersion(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------




	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
