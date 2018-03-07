// CkXmlCertVaultU.h: interface for the CkXmlCertVaultU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkXmlCertVaultU_H
#define _CkXmlCertVaultU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkCertU;
class CkByteData;
class CkCertChainU;
class CkPfxU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkXmlCertVaultU
class CK_VISIBLE_PUBLIC CkXmlCertVaultU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkXmlCertVaultU(const CkXmlCertVaultU &);
	CkXmlCertVaultU &operator=(const CkXmlCertVaultU &);

    public:
	CkXmlCertVaultU(void);
	virtual ~CkXmlCertVaultU(void);

	static CkXmlCertVaultU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The master password for the vault. Certificates are stored unencrypted, but
	// private keys are stored 256-bit AES encrypted using the individual PFX
	// passwords. The PFX passwords are stored 256-bit AES encrypted using the master
	// password. The master password is required to acces any of the private keys
	// stored within the XML vault.
	void get_MasterPassword(CkString &str);
	// The master password for the vault. Certificates are stored unencrypted, but
	// private keys are stored 256-bit AES encrypted using the individual PFX
	// passwords. The PFX passwords are stored 256-bit AES encrypted using the master
	// password. The master password is required to acces any of the private keys
	// stored within the XML vault.
	const uint16_t *masterPassword(void);
	// The master password for the vault. Certificates are stored unencrypted, but
	// private keys are stored 256-bit AES encrypted using the individual PFX
	// passwords. The PFX passwords are stored 256-bit AES encrypted using the master
	// password. The master password is required to acces any of the private keys
	// stored within the XML vault.
	void put_MasterPassword(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a certificate to the XML vault.
	bool AddCert(CkCertU &cert);

	// Adds a certificate to the XML vault from any binary format, such as DER.
	bool AddCertBinary(CkByteData &certBytes);

	// Adds a chain of certificates to the XML vault.
	bool AddCertChain(CkCertChainU &certChain);

	// Adds a certificate to the XML vault where certificate is passed directly from
	// encoded bytes (such as Base64, Hex, etc.). The encoding is indicated by encoding.
	bool AddCertEncoded(const uint16_t *encodedBytes, const uint16_t *encoding);

	// Adds a certificate to the XML vault.
	bool AddCertFile(const uint16_t *path);

	// Adds a certificate from any string representation format such as PEM.
	bool AddCertString(const uint16_t *certData);

	// Adds the contents of a PEM file to the XML vault. The PEM file may be encrypted,
	// and it may contain one or more certificates and/or private keys. The password is
	// optional and only required if the PEM file contains encrypted content that
	// requires a password.
	bool AddPemFile(const uint16_t *path, const uint16_t *password);

	// Adds a PFX (PKCS12) to the XML vault.
	bool AddPfx(CkPfxU &pfx);

	// Adds a PFX to the XML vault where PFX is passed directly from in-memory binary
	// bytes.
	bool AddPfxBinary(CkByteData &pfxBytes, const uint16_t *password);

	// Adds a PFX to the XML vault where PFX is passed directly from encoded bytes
	// (such as Base64, Hex, etc.). The encoding is indicated by encoding.
	bool AddPfxEncoded(const uint16_t *encodedBytes, const uint16_t *encoding, const uint16_t *password);

	// Adds a PFX file to the XML vault.
	bool AddPfxFile(const uint16_t *path, const uint16_t *password);

	// Returns the contents of the cert vault as an XML string.
	bool GetXml(CkString &outStr);
	// Returns the contents of the cert vault as an XML string.
	const uint16_t *getXml(void);
	// Returns the contents of the cert vault as an XML string.
	const uint16_t *xml(void);

	// Loads from an XML string.
	bool LoadXml(const uint16_t *xml);

	// Loads from an XML file.
	bool LoadXmlFile(const uint16_t *path);

	// Saves the contents to an XML file.
	bool SaveXml(const uint16_t *path);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
