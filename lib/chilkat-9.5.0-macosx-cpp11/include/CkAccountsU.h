// CkAccountsU.h: interface for the CkAccountsU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkAccountsU_H
#define _CkAccountsU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkPublicKeyU;
class CkPrivateKeyU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAccountsU
class CK_VISIBLE_PUBLIC CkAccountsU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkAccountsU(const CkAccountsU &);
	CkAccountsU &operator=(const CkAccountsU &);

    public:
	CkAccountsU(void);
	virtual ~CkAccountsU(void);

	static CkAccountsU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------


	// ----------------------
	// Methods
	// ----------------------
	// Deletes a named account.
	bool DeleteAccount(const uint16_t *accountName);

	// Returns the account data encrypted using rsaKey and encoded according to the
	// specified encoding (using any of the encoding modes listed at the link below). The
	// underlying algorithm used for encryption is 256-bit AES.
	bool GetEncrypted(const uint16_t *encoding, CkPublicKeyU &rsaKey, CkString &outStr);
	// Returns the account data encrypted using rsaKey and encoded according to the
	// specified encoding (using any of the encoding modes listed at the link below). The
	// underlying algorithm used for encryption is 256-bit AES.
	const uint16_t *getEncrypted(const uint16_t *encoding, CkPublicKeyU &rsaKey);
	// Returns the account data encrypted using rsaKey and encoded according to the
	// specified encoding (using any of the encoding modes listed at the link below). The
	// underlying algorithm used for encryption is 256-bit AES.
	const uint16_t *encrypted(const uint16_t *encoding, CkPublicKeyU &rsaKey);

	// Returns the account data in its unencrypted JSON format.
	bool GetJson(CkString &outStr);
	// Returns the account data in its unencrypted JSON format.
	const uint16_t *getJson(void);
	// Returns the account data in its unencrypted JSON format.
	const uint16_t *json(void);

	// Loads the account settings passed in accountData by decoding according to encoding, and
	// decrypting (using the rsaKey) . The encoding can be base64, hex, base64url, or any of
	// the binary encodings listed at the link below. The underlying algorithm used for
	// encryption is 256-bit AES.
	bool LoadEncrypted(const uint16_t *accountData, const uint16_t *encoding, CkPrivateKeyU &rsaKey);

	// Loads the account data from unencrypted JSON.
	bool LoadJson(const uint16_t *accountData);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
