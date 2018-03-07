// CkJwtU.h: interface for the CkJwtU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkJwtU_H
#define _CkJwtU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkPrivateKeyU;
class CkPublicKeyU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkJwtU
class CK_VISIBLE_PUBLIC CkJwtU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkJwtU(const CkJwtU &);
	CkJwtU &operator=(const CkJwtU &);

    public:
	CkJwtU(void);
	virtual ~CkJwtU(void);

	static CkJwtU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// If true, the JSON passed to CreateJwt and CreateJwtPk will be compacted to
	// remove unnecessary whitespace. This will result in the smallest possible JWT.
	// The default value is true.
	bool get_AutoCompact(void);
	// If true, the JSON passed to CreateJwt and CreateJwtPk will be compacted to
	// remove unnecessary whitespace. This will result in the smallest possible JWT.
	// The default value is true.
	void put_AutoCompact(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Creates a JWT. The header is the JOSE JSON header. It can be the full JOSE JSON,
	// or it can be a shorthand string such as "HS256", "HS384", or "HS512", in which
	// case the standard JOSE header for the given algorithm will be used.
	// 
	// The payload is the JSON payload that contains the claims. The password is the secret.
	// Given that the secret is a shared passwod string, this method should only be
	// called for creating JWT's where the JOSE header's "alg" is HS256, HS384, or
	// HS512. For RS256, RS384, RS512, ES256, ES384, and ES512, call CreateJwtPk
	// instead.
	// 
	// When successful, this method returns a JWT with the format xxxxx.yyyyy.zzzzz,
	// where xxxxx is the base64url encoded JOSE header, yyyyy is the base64url encoded
	// payload, and zzzzz is the base64url signature.
	// 
	bool CreateJwt(const uint16_t *header, const uint16_t *payload, const uint16_t *password, CkString &outStr);
	// Creates a JWT. The header is the JOSE JSON header. It can be the full JOSE JSON,
	// or it can be a shorthand string such as "HS256", "HS384", or "HS512", in which
	// case the standard JOSE header for the given algorithm will be used.
	// 
	// The payload is the JSON payload that contains the claims. The password is the secret.
	// Given that the secret is a shared passwod string, this method should only be
	// called for creating JWT's where the JOSE header's "alg" is HS256, HS384, or
	// HS512. For RS256, RS384, RS512, ES256, ES384, and ES512, call CreateJwtPk
	// instead.
	// 
	// When successful, this method returns a JWT with the format xxxxx.yyyyy.zzzzz,
	// where xxxxx is the base64url encoded JOSE header, yyyyy is the base64url encoded
	// payload, and zzzzz is the base64url signature.
	// 
	const uint16_t *createJwt(const uint16_t *header, const uint16_t *payload, const uint16_t *password);

	// Creates a JWT using an RSA or ECC private key. The header is the JOSE JSON header.
	// It can be the full JOSE JSON, or it can be a shorthand string such as "RS256",
	// "RS384", "RS512", "ES256", "ES384", or "ES512", in which case the standard JOSE
	// header for the given algorithm will be used.
	// 
	// The payload is the JSON payload that contains the claims. The key is the private
	// key. This method should only be called for creating JWT's where the JOSE
	// header's "alg" is RS256, RS384, RS512, ES256, ES384, and ES512. If the secret is
	// a shared password string, then call CreateJwt instead.
	// 
	// When successful, this method returns a JWT with the format xxxxx.yyyyy.zzzzz,
	// where xxxxx is the base64url encoded JOSE header, yyyyy is the base64url encoded
	// payload, and zzzzz is the base64url signature.
	// 
	bool CreateJwtPk(const uint16_t *header, const uint16_t *payload, CkPrivateKeyU &key, CkString &outStr);
	// Creates a JWT using an RSA or ECC private key. The header is the JOSE JSON header.
	// It can be the full JOSE JSON, or it can be a shorthand string such as "RS256",
	// "RS384", "RS512", "ES256", "ES384", or "ES512", in which case the standard JOSE
	// header for the given algorithm will be used.
	// 
	// The payload is the JSON payload that contains the claims. The key is the private
	// key. This method should only be called for creating JWT's where the JOSE
	// header's "alg" is RS256, RS384, RS512, ES256, ES384, and ES512. If the secret is
	// a shared password string, then call CreateJwt instead.
	// 
	// When successful, this method returns a JWT with the format xxxxx.yyyyy.zzzzz,
	// where xxxxx is the base64url encoded JOSE header, yyyyy is the base64url encoded
	// payload, and zzzzz is the base64url signature.
	// 
	const uint16_t *createJwtPk(const uint16_t *header, const uint16_t *payload, CkPrivateKeyU &key);

	// Generates a JSON numeric value representing the number of seconds from
	// 1970-01-01T00:00:00Z UTC until the specified UTC date/time, ignoring leap
	// seconds. The date/time generated is equal to the current system time plus the
	// number of seconds specified by numSecOffset. The numSecOffset can be negative.
	int GenNumericDate(int numSecOffset);

	// Decodes the first part of a JWT (the "xxxxx" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the JOSE header of the JWT.
	bool GetHeader(const uint16_t *token, CkString &outStr);
	// Decodes the first part of a JWT (the "xxxxx" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the JOSE header of the JWT.
	const uint16_t *getHeader(const uint16_t *token);
	// Decodes the first part of a JWT (the "xxxxx" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the JOSE header of the JWT.
	const uint16_t *header(const uint16_t *token);

	// Decodes the second part of a JWT (the "yyyyy" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the claims payload of the JWT.
	bool GetPayload(const uint16_t *token, CkString &outStr);
	// Decodes the second part of a JWT (the "yyyyy" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the claims payload of the JWT.
	const uint16_t *getPayload(const uint16_t *token);
	// Decodes the second part of a JWT (the "yyyyy" part of the "xxxxx.yyyyy.zzzzz"
	// JWT) and returns the JSON string. This is the claims payload of the JWT.
	const uint16_t *payload(const uint16_t *token);

	// Verifies the "exp" and/or "nbf" claims and returns true if the current system
	// date/time is within range. Returns false if the current system date/time is
	// outside the allowed range of time. The leeway may be set to a non-zero number of
	// seconds to allow for some small leeway (usually no more than a few minutes) to
	// account for clock skew.
	bool IsTimeValid(const uint16_t *jwt, int leeway);

	// Verifies a JWT that requires a shared password string for verification. The token
	// should be a JWT with the format xxxxx.yyyyy.zzzzz. This method should only be
	// called for JWT's using the HS256, HS384, or HS512 algorithms. The VerifyJwtPk
	// method should be called for verifying JWT's requiring an RSA or ECC key.
	// 
	// Returns true if the signature was verified. Returns false if the signature
	// was not successfully verified.
	// 
	bool VerifyJwt(const uint16_t *token, const uint16_t *password);

	// Verifies a JWT that requires an RSA or ECC public key for verification. The token
	// should be a JWT with the format xxxxx.yyyyy.zzzzz. This method should only be
	// called for JWT's using the RS256, RS384, RS512, ES256, ES384, or ES512
	// algorithms.
	// 
	// Returns true if the signature was verified. Returns false if the signature
	// was not successfully verified.
	// 
	bool VerifyJwtPk(const uint16_t *token, CkPublicKeyU &key);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
