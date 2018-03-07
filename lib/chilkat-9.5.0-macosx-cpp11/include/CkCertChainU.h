// CkCertChainU.h: interface for the CkCertChainU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCertChainU_H
#define _CkCertChainU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkCertU;
class CkTrustedRootsU;
class CkJsonObjectU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCertChainU
class CK_VISIBLE_PUBLIC CkCertChainU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCertChainU(const CkCertChainU &);
	CkCertChainU &operator=(const CkCertChainU &);

    public:
	CkCertChainU(void);
	virtual ~CkCertChainU(void);

	static CkCertChainU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of certificates in the chain. The end-user subscriber certificate is
	// at index 0. This is the certificate most removed from the trusted root.
	// Intermediate certificates are at indices 1 to NumCerts - 2. The trusted root (or
	// self-signed certificate) is at index NumCerts - 1.
	int get_NumCerts(void);

	// Returns the number of certificates in the chain that have expired.
	int get_NumExpiredCerts(void);

	// true if this certificate chain extends all the way to the root certificate.
	// The root certificate is either a trusted CA root or a self-signed certificate.
	// In both cases, the issuer of a root certificate is itself.
	bool get_ReachesRoot(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the Nth certificate in the chain.
	// The caller is responsible for deleting the object returned by this method.
	CkCertU *GetCert(int index);

	// Returns true if the root of the certificate chain is a certificate found in
	// trustedRoots.
	bool IsRootTrusted(CkTrustedRootsU &trustedRoots);

	// Loads a certificate chain from the "x5c" parameter of a JWK (JSON Web Key).
	bool LoadX5C(CkJsonObjectU &jwk);

	// Verifies the certificate signatures to the root. Returns true if all
	// certificate signatures are valid.
	bool VerifyCertSignatures(void);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
