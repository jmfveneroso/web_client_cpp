// CkAuthFacebookU.h: interface for the CkAuthFacebookU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkAuthFacebookU_H
#define _CkAuthFacebookU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAuthFacebookU
class CK_VISIBLE_PUBLIC CkAuthFacebookU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkAuthFacebookU(const CkAuthFacebookU &);
	CkAuthFacebookU &operator=(const CkAuthFacebookU &);

    public:
	CkAuthFacebookU(void);
	virtual ~CkAuthFacebookU(void);

	static CkAuthFacebookU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The Facebook application ID. For example, "5312537625104".
	void get_AppId(CkString &str);
	// The Facebook application ID. For example, "5312537625104".
	const uint16_t *appId(void);
	// The Facebook application ID. For example, "5312537625104".
	void put_AppId(const uint16_t *newVal);

	// The Facebook application secret. For example,
	// "27ac8bce48035e4f525f5bb370b6eada".
	void get_AppSecret(CkString &str);
	// The Facebook application secret. For example,
	// "27ac8bce48035e4f525f5bb370b6eada".
	const uint16_t *appSecret(void);
	// The Facebook application secret. For example,
	// "27ac8bce48035e4f525f5bb370b6eada".
	void put_AppSecret(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------




	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
