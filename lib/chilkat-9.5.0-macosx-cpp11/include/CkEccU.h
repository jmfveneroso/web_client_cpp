// CkEccU.h: interface for the CkEccU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkEccU_H
#define _CkEccU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkPrivateKeyU;
class CkPrngU;
class CkPublicKeyU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkEccU
class CK_VISIBLE_PUBLIC CkEccU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkEccU(const CkEccU &);
	CkEccU &operator=(const CkEccU &);

    public:
	CkEccU(void);
	virtual ~CkEccU(void);

	static CkEccU *createNew(void);
	

	
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
	// Generates an ECC private key. The curveName specifies the curve name which determines
	// the key size. The prng provides a source for generating the random private key.
	// 
	// The following curve names are accepted:
	//     secp256r1 (also known as P-256 and prime256v1)
	//     secp384r1 (also known as P-384)
	//     secp521r1 (also known as P-521)
	//     secp256k1 (This is the curve used for Bitcoin)
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkPrivateKeyU *GenEccKey(const uint16_t *curveName, CkPrngU &prng);

	// Generates an ECC private key using a specified value for K. The curveName specifies
	// the curve name which determines the key size. The encodedK is the encoded value of
	// the private key. The encoding is the encoding used for encodedK, which can be "hex",
	// "base64", "decimal", etc.
	// 
	// Note: This method is typically used for testing -- such as when the same private
	// key is desired to produce results identical from run to run.
	// 
	// The following curve names are accepted:
	//     secp256r1 (also known as P-256 and prime256v1)
	//     secp384r1 (also known as P-384)
	//     secp521r1 (also known as P-521)
	//     secp256k1 (This is the curve used for Bitcoin)
	// 
	// The caller is responsible for deleting the object returned by this method.
	CkPrivateKeyU *GenEccKey2(const uint16_t *curveName, const uint16_t *encodedK, const uint16_t *encoding);

	// Computes a shared secret given a private and public key. For example, Alice and
	// Bob can compute the identical shared secret by doing the following: Alice sends
	// Bob her public key, and Bob calls SharedSecretENC with his private key and
	// Alice's public key. Bob sends Alice his public key, and Alice calls
	// SharedSecretENC with her private key and Bob's public key. Both calls to
	// SharedSecretENC will produce the same result. The resulting bytes are returned
	// in encoded string form (hex, base64, etc) as specified by encoding.
	// 
	// Note: The private and public keys must both be keys on the same ECC curve.
	// 
	bool SharedSecretENC(CkPrivateKeyU &privKey, CkPublicKeyU &pubKey, const uint16_t *encoding, CkString &outStr);
	// Computes a shared secret given a private and public key. For example, Alice and
	// Bob can compute the identical shared secret by doing the following: Alice sends
	// Bob her public key, and Bob calls SharedSecretENC with his private key and
	// Alice's public key. Bob sends Alice his public key, and Alice calls
	// SharedSecretENC with her private key and Bob's public key. Both calls to
	// SharedSecretENC will produce the same result. The resulting bytes are returned
	// in encoded string form (hex, base64, etc) as specified by encoding.
	// 
	// Note: The private and public keys must both be keys on the same ECC curve.
	// 
	const uint16_t *sharedSecretENC(CkPrivateKeyU &privKey, CkPublicKeyU &pubKey, const uint16_t *encoding);

	// Computes an ECC signature on a hash. ECC signatures are computed and verified on
	// the hashes of data (such as SHA1, SHA256, etc.). The hash of the data is passed
	// in encodedHash. The encoding, such as "base64", "hex", etc. is passed in encoding. The ECC
	// private key is passed in the 3rd argument (privkey). Given that creating an ECC
	// signature involves the generation of random numbers, a PRNG is passed in the 4th
	// argument (prng). The signature is returned as an encoded string using the
	// encoding specified by the encoding argument.
	bool SignHashENC(const uint16_t *encodedHash, const uint16_t *encoding, CkPrivateKeyU &privkey, CkPrngU &prng, CkString &outStr);
	// Computes an ECC signature on a hash. ECC signatures are computed and verified on
	// the hashes of data (such as SHA1, SHA256, etc.). The hash of the data is passed
	// in encodedHash. The encoding, such as "base64", "hex", etc. is passed in encoding. The ECC
	// private key is passed in the 3rd argument (privkey). Given that creating an ECC
	// signature involves the generation of random numbers, a PRNG is passed in the 4th
	// argument (prng). The signature is returned as an encoded string using the
	// encoding specified by the encoding argument.
	const uint16_t *signHashENC(const uint16_t *encodedHash, const uint16_t *encoding, CkPrivateKeyU &privkey, CkPrngU &prng);

	// Verifies an ECC signature. ECC signatures are computed and verified on the
	// hashes of data (such as SHA1, SHA256, etc.). The hash of the data is passed in
	// encodedHash. The encoded signature is passed in encodedSig. The encoding of both the hash and
	// signature, such as "base64", "hex", etc. is passed in encoding. The ECC public key
	// is passed in the last argument (pubkey).
	// 
	// The method returns 1 for a valid signature, 0 for an invalid signature, and -1
	// for any other failure.
	// 
	int VerifyHashENC(const uint16_t *encodedHash, const uint16_t *encodedSig, const uint16_t *encoding, CkPublicKeyU &pubkey);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
