// CkAuthAzureADU.h: interface for the CkAuthAzureADU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkAuthAzureADU_H
#define _CkAuthAzureADU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkSocketU;
class CkTaskU;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAuthAzureADU
class CK_VISIBLE_PUBLIC CkAuthAzureADU  : public CkClassWithCallbacksU
{
    private:
	bool m_cbOwned;

	// Don't allow assignment or copying these objects.
	CkAuthAzureADU(const CkAuthAzureADU &);
	CkAuthAzureADU &operator=(const CkAuthAzureADU &);

    public:
	CkAuthAzureADU(void);
	virtual ~CkAuthAzureADU(void);

	static CkAuthAzureADU *createNew(void);
	

	CkAuthAzureADU(bool bCallbackOwned);
	static CkAuthAzureADU *createNew(bool bCallbackOwned);

	
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
	// The access token to be used in Azure AD REST API requests. This property is set
	// on a successful call to ObtainAccessToken.
	void get_AccessToken(CkString &str);
	// The access token to be used in Azure AD REST API requests. This property is set
	// on a successful call to ObtainAccessToken.
	const uint16_t *accessToken(void);
	// The access token to be used in Azure AD REST API requests. This property is set
	// on a successful call to ObtainAccessToken.
	void put_AccessToken(const uint16_t *newVal);

	// Specifies the Azure AD client id of the calling web service. To find the calling
	// application's client ID, in the Azure Management Portal, click Active Directory,
	// click the directory, click the application, and then click Configure.
	void get_ClientId(CkString &str);
	// Specifies the Azure AD client id of the calling web service. To find the calling
	// application's client ID, in the Azure Management Portal, click Active Directory,
	// click the directory, click the application, and then click Configure.
	const uint16_t *clientId(void);
	// Specifies the Azure AD client id of the calling web service. To find the calling
	// application's client ID, in the Azure Management Portal, click Active Directory,
	// click the directory, click the application, and then click Configure.
	void put_ClientId(const uint16_t *newVal);

	// A key registered for the calling web service in Azure AD. To create a key, in
	// the Azure Management Portal, click Active Directory, click the directory, click
	// the application, and then click Configure.
	void get_ClientSecret(CkString &str);
	// A key registered for the calling web service in Azure AD. To create a key, in
	// the Azure Management Portal, click Active Directory, click the directory, click
	// the application, and then click Configure.
	const uint16_t *clientSecret(void);
	// A key registered for the calling web service in Azure AD. To create a key, in
	// the Azure Management Portal, click Active Directory, click the directory, click
	// the application, and then click Configure.
	void put_ClientSecret(const uint16_t *newVal);

	// If the access token is valid, contains the number of seconds remaining until it
	// expires. A value of 0 indicates an invalid or expired access token.
	int get_NumSecondsRemaining(void);

	// The App ID URI of the receiving web service. To find the App ID URI, in the
	// Azure Management Portal, click Active Directory, click the directory, click the
	// application, and then click Configure.
	void get_Resource(CkString &str);
	// The App ID URI of the receiving web service. To find the App ID URI, in the
	// Azure Management Portal, click Active Directory, click the directory, click the
	// application, and then click Configure.
	const uint16_t *resource(void);
	// The App ID URI of the receiving web service. To find the App ID URI, in the
	// Azure Management Portal, click Active Directory, click the directory, click the
	// application, and then click Configure.
	void put_Resource(const uint16_t *newVal);

	// true if the AccessToken property contains a valid non-expired access token
	// obtained via the call to ObtainAccessToken.
	void get_TenantId(CkString &str);
	// true if the AccessToken property contains a valid non-expired access token
	// obtained via the call to ObtainAccessToken.
	const uint16_t *tenantId(void);
	// true if the AccessToken property contains a valid non-expired access token
	// obtained via the call to ObtainAccessToken.
	void put_TenantId(const uint16_t *newVal);

	// true if the AccessToken property contains a valid non-expired access token
	// obtained via the call to ObtainAccessToken.
	bool get_Valid(void);



	// ----------------------
	// Methods
	// ----------------------
	// Sends the HTTP request to fetch the access token. When this method completes
	// successfully, the access token is available in the AccessToken property. The
	// connection is an existing connection to login.microsoftonline.com.
	bool ObtainAccessToken(CkSocketU &connection);

	// Creates an asynchronous task to call the ObtainAccessToken method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *ObtainAccessTokenAsync(CkSocketU &connection);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
