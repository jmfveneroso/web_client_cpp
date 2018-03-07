// CkPublicKeyU.h: interface for the CkPublicKeyU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkPublicKeyU_H
#define _CkPublicKeyU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkPublicKeyU
class CK_VISIBLE_PUBLIC CkPublicKeyU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkPublicKeyU(const CkPublicKeyU &);
	CkPublicKeyU &operator=(const CkPublicKeyU &);

    public:
	CkPublicKeyU(void);
	virtual ~CkPublicKeyU(void);

	static CkPublicKeyU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The type of public key. Can be "empty", "rsa", "dsa", or "ecc".
	void get_KeyType(CkString &str);
	// The type of public key. Can be "empty", "rsa", "dsa", or "ecc".
	const uint16_t *keyType(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the public key in binary DER format. If the key type (such as RSA)
	// supports both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is
	// returned.
	bool GetDer(bool preferPkcs1, CkByteData &outBytes);

	// Returns the public key in DER format as an encoded string (such as base64 or
	// hex). If the key type (such as RSA) supports both PKCS1 and PKCS8 formats, then
	// preferPkcs1 determine which format is returned. The encoding specifies the encoding, which
	// is typically "base64".
	bool GetEncoded(bool preferPkcs1, const uint16_t *encoding, CkString &outStr);
	// Returns the public key in DER format as an encoded string (such as base64 or
	// hex). If the key type (such as RSA) supports both PKCS1 and PKCS8 formats, then
	// preferPkcs1 determine which format is returned. The encoding specifies the encoding, which
	// is typically "base64".
	const uint16_t *getEncoded(bool preferPkcs1, const uint16_t *encoding);
	// Returns the public key in DER format as an encoded string (such as base64 or
	// hex). If the key type (such as RSA) supports both PKCS1 and PKCS8 formats, then
	// preferPkcs1 determine which format is returned. The encoding specifies the encoding, which
	// is typically "base64".
	const uint16_t *encoded(bool preferPkcs1, const uint16_t *encoding);

	// Gets the public key in JWK (JSON Web Key) format.
	// 
	// RSA public keys have this JWK format:
	//          {"kty":"RSA",
	//           "n": "0vx7agoebGcQSuuPiLJXZptN9 ... U8awapJzKnqDKgw",
	//           "e":"AQAB"}
	// 
	// ECC public keys have this JWK format:
	//          {"kty":"EC",
	//           "crv":"P-256",
	//           "x":"MKBCTNIcKUSDii11ySs3526iDZ8AiTo7Tu6KPAqv7D4",
	//           "y":"4Etl6SRW2YiLUrN5vfvVHuhp7x8PxltmWWlbbM4IFyM"}
	// 
	bool GetJwk(CkString &outStr);
	// Gets the public key in JWK (JSON Web Key) format.
	// 
	// RSA public keys have this JWK format:
	//          {"kty":"RSA",
	//           "n": "0vx7agoebGcQSuuPiLJXZptN9 ... U8awapJzKnqDKgw",
	//           "e":"AQAB"}
	// 
	// ECC public keys have this JWK format:
	//          {"kty":"EC",
	//           "crv":"P-256",
	//           "x":"MKBCTNIcKUSDii11ySs3526iDZ8AiTo7Tu6KPAqv7D4",
	//           "y":"4Etl6SRW2YiLUrN5vfvVHuhp7x8PxltmWWlbbM4IFyM"}
	// 
	const uint16_t *getJwk(void);
	// Gets the public key in JWK (JSON Web Key) format.
	// 
	// RSA public keys have this JWK format:
	//          {"kty":"RSA",
	//           "n": "0vx7agoebGcQSuuPiLJXZptN9 ... U8awapJzKnqDKgw",
	//           "e":"AQAB"}
	// 
	// ECC public keys have this JWK format:
	//          {"kty":"EC",
	//           "crv":"P-256",
	//           "x":"MKBCTNIcKUSDii11ySs3526iDZ8AiTo7Tu6KPAqv7D4",
	//           "y":"4Etl6SRW2YiLUrN5vfvVHuhp7x8PxltmWWlbbM4IFyM"}
	// 
	const uint16_t *jwk(void);

	// Returns the JWK thumbprint for the public key. This is the thumbprint of the
	// JSON Web Key (JWK) as per RFC 7638.
	bool GetJwkThumbprint(const uint16_t *hashAlg, CkString &outStr);
	// Returns the JWK thumbprint for the public key. This is the thumbprint of the
	// JSON Web Key (JWK) as per RFC 7638.
	const uint16_t *getJwkThumbprint(const uint16_t *hashAlg);
	// Returns the JWK thumbprint for the public key. This is the thumbprint of the
	// JSON Web Key (JWK) as per RFC 7638.
	const uint16_t *jwkThumbprint(const uint16_t *hashAlg);

	// This method is deprecated. Applications should call GetDer with preference for
	// PKCS8 instead.
	// 
	// Gets the public key in PKCS8 DER format.
	// 
	bool GetOpenSslDer(CkByteData &outData);

	// This method is deprecated. Applications should call GetPem with preference for
	// PKCS8 instead.
	// 
	// Gets the public key in PKCS8 PEM format.
	// 
	bool GetOpenSslPem(CkString &outStr);
	// This method is deprecated. Applications should call GetPem with preference for
	// PKCS8 instead.
	// 
	// Gets the public key in PKCS8 PEM format.
	// 
	const uint16_t *getOpenSslPem(void);
	// This method is deprecated. Applications should call GetPem with preference for
	// PKCS8 instead.
	// 
	// Gets the public key in PKCS8 PEM format.
	// 
	const uint16_t *openSslPem(void);

	// Returns the public key in PEM format. If the key type (such as RSA) supports
	// both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is returned.
	bool GetPem(bool preferPkcs1, CkString &outStr);
	// Returns the public key in PEM format. If the key type (such as RSA) supports
	// both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is returned.
	const uint16_t *getPem(bool preferPkcs1);
	// Returns the public key in PEM format. If the key type (such as RSA) supports
	// both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is returned.
	const uint16_t *pem(bool preferPkcs1);

	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS1 instead.
	// 
	// Gets the public key in PKCS1 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	bool GetPkcs1ENC(const uint16_t *encoding, CkString &outStr);
	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS1 instead.
	// 
	// Gets the public key in PKCS1 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	const uint16_t *getPkcs1ENC(const uint16_t *encoding);
	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS1 instead.
	// 
	// Gets the public key in PKCS1 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	const uint16_t *pkcs1ENC(const uint16_t *encoding);

	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS8 instead.
	// 
	// Gets the public key in PKCS8 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	bool GetPkcs8ENC(const uint16_t *encoding, CkString &outStr);
	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS8 instead.
	// 
	// Gets the public key in PKCS8 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	const uint16_t *getPkcs8ENC(const uint16_t *encoding);
	// This method is deprecated. Applications should call GetEncoded with preference
	// for PKCS8 instead.
	// 
	// Gets the public key in PKCS8 format and returns in an encoded string, as
	// specified by the encoding argument.
	// 
	const uint16_t *pkcs8ENC(const uint16_t *encoding);

	// This method is deprecated. Applications should call GetDer with preference for
	// PKCS1 instead.
	// 
	// Gets the public key in PKCS1 DER format.
	// 
	bool GetRsaDer(CkByteData &outData);

	// Gets the public key in XML format. The format depends on the key type. The key
	// parts indicated by "..." are base64 encoded.
	// 
	// RSA public keys have this XML format:
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	// 
	// DSA public keys have this XML format:
	// <DSAPublicKey>
	//     <P>...</P>
	//     <Q>...</Q>
	//     <G>...</G>
	//     <Y>...</Y>
	// </DSAPublicKey>
	// 
	// ECC public keys have this XML format:
	// <ECCPublicKey curve="CURVE_NAME" x="HEX_DATA" y="HEX_DATA">...</ECCPublicKey>
	// 
	bool GetXml(CkString &outStr);
	// Gets the public key in XML format. The format depends on the key type. The key
	// parts indicated by "..." are base64 encoded.
	// 
	// RSA public keys have this XML format:
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	// 
	// DSA public keys have this XML format:
	// <DSAPublicKey>
	//     <P>...</P>
	//     <Q>...</Q>
	//     <G>...</G>
	//     <Y>...</Y>
	// </DSAPublicKey>
	// 
	// ECC public keys have this XML format:
	// <ECCPublicKey curve="CURVE_NAME" x="HEX_DATA" y="HEX_DATA">...</ECCPublicKey>
	// 
	const uint16_t *getXml(void);
	// Gets the public key in XML format. The format depends on the key type. The key
	// parts indicated by "..." are base64 encoded.
	// 
	// RSA public keys have this XML format:
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	// 
	// DSA public keys have this XML format:
	// <DSAPublicKey>
	//     <P>...</P>
	//     <Q>...</Q>
	//     <G>...</G>
	//     <Y>...</Y>
	// </DSAPublicKey>
	// 
	// ECC public keys have this XML format:
	// <ECCPublicKey curve="CURVE_NAME" x="HEX_DATA" y="HEX_DATA">...</ECCPublicKey>
	// 
	const uint16_t *xml(void);

	// Loads a public key from base64-encoded DER (can be PKCS1 or PKCS8).
	bool LoadBase64(const uint16_t *keyStr);

	// Loads a public key from binary DER. Auto-recognizes both PKCS1 and PKCS8
	// formats.
	bool LoadFromBinary(CkByteData &keyBytes);

	// Loads a public key from a file. The file can be in any string or binary format
	// such as binary DER (PKCS1 or PKCS8), PEM, XML, or encoded binary DER (such as
	// base64 encoded binary DER). The format of the contents of the file is
	// auto-recognized.
	// 
	// Starting in version 9.5.0.66, this method also supports loading the JWK (JSON
	// Web Key) format.
	// 
	bool LoadFromFile(const uint16_t *path);

	// Loads a public key from any string format, such as PEM, XML, or encoded binary
	// DER (such as base64 encoded binary DER). The format of the keyString is
	// auto-recognized.
	// 
	// Starting in version 9.5.0.66, this method also supports loading the JWK (JSON
	// Web Key) format.
	// 
	bool LoadFromString(const uint16_t *keyString);

	// This method is deprecated. Applications should call LoadFromBinary instead.
	// 
	// Loads a public key from in-memory PKCS8 DER formatted byte data.
	// 
	bool LoadOpenSslDer(CkByteData &data);

	// This method is deprecated. Applications should call LoadFromFile instead.
	// 
	// Loads a public key from an PKCS8 DER format file.
	// 
	bool LoadOpenSslDerFile(const uint16_t *path);

	// This method is deprecated. Applications should call LoadFromString instead.
	// 
	// Loads a public key from an PKCS8 PEM string.
	// 
	bool LoadOpenSslPem(const uint16_t *str);

	// This method is deprecated. Applications should call LoadFromFile instead.
	// 
	// Loads a public key from an PKCS8 PEM file.
	// 
	bool LoadOpenSslPemFile(const uint16_t *path);

	// This method is deprecated. Applications should call LoadFromString instead.
	// 
	// Loads an RSA public key from PKCS#1 PEM format.
	// 
	bool LoadPkcs1Pem(const uint16_t *str);

	// This method is deprecated. Applications should call LoadFromBinary instead.
	// 
	// Loads a public key from in-memory PKCS1 DER formatted byte data.
	// 
	bool LoadRsaDer(CkByteData &data);

	// This method is deprecated. Applications should call LoadFromFile instead.
	// 
	// Loads a public key from an PKCS1 DER formatted file.
	// 
	bool LoadRsaDerFile(const uint16_t *path);

	// This method is deprecated. Applications should call LoadFromString instead.
	// 
	// Loads a public key from an XML string.
	// 
	bool LoadXml(const uint16_t *xml);

	// This method is deprecated. Applications should call LoadFromFile instead.
	// 
	// Loads a public key from an XML file.
	// 
	bool LoadXmlFile(const uint16_t *path);

	// Saves the public key to a file in binary DER format. If the key type (such as
	// RSA) supports both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is
	// returned.
	bool SaveDerFile(bool preferPkcs1, const uint16_t *path);

	// This method is deprecated. Applications should call SaveDerFile with preference
	// for PKCS8 instead.
	// 
	// Saves the public key to an PKCS8 DER format file.
	// 
	bool SaveOpenSslDerFile(const uint16_t *path);

	// This method is deprecated. Applications should call SavePemFile with preference
	// for PKCS8 instead.
	// 
	// Saves the public key to an PKCS8 PEM format file.
	// 
	bool SaveOpenSslPemFile(const uint16_t *path);

	// Saves the public key to a file in PEM format. If the key type (such as RSA)
	// supports both PKCS1 and PKCS8 formats, then preferPkcs1 determine which format is
	// returned.
	bool SavePemFile(bool preferPkcs1, const uint16_t *path);

	// This method is deprecated. Applications should call SaveDerFile with preference
	// for PKCS1 instead.
	// 
	// Saves the public key to an PKCS1 DER format file.
	// 
	bool SaveRsaDerFile(const uint16_t *path);

	// Saves the public key to an XML file.
	bool SaveXmlFile(const uint16_t *path);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
