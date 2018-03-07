// CkCsrU.h: interface for the CkCsrU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCsrU_H
#define _CkCsrU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkPrivateKeyU;
class CkBinDataU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCsrU
class CK_VISIBLE_PUBLIC CkCsrU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCsrU(const CkCsrU &);
	CkCsrU &operator=(const CkCsrU &);

    public:
	CkCsrU(void);
	virtual ~CkCsrU(void);

	static CkCsrU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The common name of the certificate to be generated. For SSL/TLS certificates,
	// this would be the domain name. For email certificates this would be the email
	// address.
	// 
	// It is the value for "CN" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.3")
	// 
	// This property is required for a CSR.
	// 
	void get_CommonName(CkString &str);
	// The common name of the certificate to be generated. For SSL/TLS certificates,
	// this would be the domain name. For email certificates this would be the email
	// address.
	// 
	// It is the value for "CN" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.3")
	// 
	// This property is required for a CSR.
	// 
	const uint16_t *commonName(void);
	// The common name of the certificate to be generated. For SSL/TLS certificates,
	// this would be the domain name. For email certificates this would be the email
	// address.
	// 
	// It is the value for "CN" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.3")
	// 
	// This property is required for a CSR.
	// 
	void put_CommonName(const uint16_t *newVal);

	// The company or organization name for the certificate to be generated.
	// 
	// It is the value for "O" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.10")
	// 
	// This property is optional. It may left empty.
	// 
	void get_Company(CkString &str);
	// The company or organization name for the certificate to be generated.
	// 
	// It is the value for "O" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.10")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *company(void);
	// The company or organization name for the certificate to be generated.
	// 
	// It is the value for "O" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.10")
	// 
	// This property is optional. It may left empty.
	// 
	void put_Company(const uint16_t *newVal);

	// The company division or organizational unit name for the certificate to be
	// generated.
	// 
	// It is the value for "OU" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.11")
	// 
	// This property is optional. It may left empty.
	// 
	void get_CompanyDivision(CkString &str);
	// The company division or organizational unit name for the certificate to be
	// generated.
	// 
	// It is the value for "OU" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.11")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *companyDivision(void);
	// The company division or organizational unit name for the certificate to be
	// generated.
	// 
	// It is the value for "OU" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.11")
	// 
	// This property is optional. It may left empty.
	// 
	void put_CompanyDivision(const uint16_t *newVal);

	// The two-letter uppercase country abbreviation, such as "US", for the certificate
	// to be generated.
	// 
	// It is the value for "C" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.6")
	// 
	// This property is optional. It may left empty.
	// 
	void get_Country(CkString &str);
	// The two-letter uppercase country abbreviation, such as "US", for the certificate
	// to be generated.
	// 
	// It is the value for "C" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.6")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *country(void);
	// The two-letter uppercase country abbreviation, such as "US", for the certificate
	// to be generated.
	// 
	// It is the value for "C" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.6")
	// 
	// This property is optional. It may left empty.
	// 
	void put_Country(const uint16_t *newVal);

	// The email address for the certificate to be generated.
	// 
	// It is the value for "E" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "1.2.840.113549.1.9.1")
	// 
	// This property is optional. It may left empty.
	// 
	void get_EmailAddress(CkString &str);
	// The email address for the certificate to be generated.
	// 
	// It is the value for "E" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "1.2.840.113549.1.9.1")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *emailAddress(void);
	// The email address for the certificate to be generated.
	// 
	// It is the value for "E" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "1.2.840.113549.1.9.1")
	// 
	// This property is optional. It may left empty.
	// 
	void put_EmailAddress(const uint16_t *newVal);

	// The locality (city or town) name for the certificate to be generated.
	// 
	// It is the value for "L" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.7")
	// 
	// This property is optional. It may left empty.
	// 
	void get_Locality(CkString &str);
	// The locality (city or town) name for the certificate to be generated.
	// 
	// It is the value for "L" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.7")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *locality(void);
	// The locality (city or town) name for the certificate to be generated.
	// 
	// It is the value for "L" in the certificate's Subject's distinguished name (DN).
	// (This is the value for OID "2.5.4.7")
	// 
	// This property is optional. It may left empty.
	// 
	void put_Locality(const uint16_t *newVal);

	// The state or province for the certificate to be generated.
	// 
	// It is the value for "S" (or "ST") in the certificate's Subject's distinguished
	// name (DN). (This is the value for OID "2.5.4.8")
	// 
	// This property is optional. It may left empty.
	// 
	void get_State(CkString &str);
	// The state or province for the certificate to be generated.
	// 
	// It is the value for "S" (or "ST") in the certificate's Subject's distinguished
	// name (DN). (This is the value for OID "2.5.4.8")
	// 
	// This property is optional. It may left empty.
	// 
	const uint16_t *state(void);
	// The state or province for the certificate to be generated.
	// 
	// It is the value for "S" (or "ST") in the certificate's Subject's distinguished
	// name (DN). (This is the value for OID "2.5.4.8")
	// 
	// This property is optional. It may left empty.
	// 
	void put_State(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Generate a CSR and return the binary DER in csrData.
	bool GenCsrBd(CkPrivateKeyU &privKey, CkBinDataU &csrData);

	// Generate a CSR and return it as a PEM string.
	bool GenCsrPem(CkPrivateKeyU &privKey, CkString &outStr);
	// Generate a CSR and return it as a PEM string.
	const uint16_t *genCsrPem(CkPrivateKeyU &privKey);

	// Gets a subject field by OID, such as "2.5.4.9". See
	// http://www.alvestrand.no/objectid/2.5.4.html for OID values and meanings.
	bool GetSubjectField(const uint16_t *oid, CkString &outStr);
	// Gets a subject field by OID, such as "2.5.4.9". See
	// http://www.alvestrand.no/objectid/2.5.4.html for OID values and meanings.
	const uint16_t *getSubjectField(const uint16_t *oid);
	// Gets a subject field by OID, such as "2.5.4.9". See
	// http://www.alvestrand.no/objectid/2.5.4.html for OID values and meanings.
	const uint16_t *subjectField(const uint16_t *oid);

	// Loads this CSR object with a CSR PEM. All properties are set to the values found
	// within the CSR.
	bool LoadCsrPem(const uint16_t *csrPemStr);

	// Sets a subject field by OID, such as "2.5.4.9". See
	// http://www.alvestrand.no/objectid/2.5.4.html for OID values and meanings.
	// 
	// The asnType can be "UTF8String", "IA5String", or "PrintableString". If you have no
	// specific requirement, or don't know, choose "UTF8String".
	// 
	bool SetSubjectField(const uint16_t *oid, const uint16_t *value, const uint16_t *asnType);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
