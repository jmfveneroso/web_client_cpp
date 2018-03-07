// CkBounceU.h: interface for the CkBounceU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkBounceU_H
#define _CkBounceU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkEmailU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkBounceU
class CK_VISIBLE_PUBLIC CkBounceU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkBounceU(const CkBounceU &);
	CkBounceU &operator=(const CkBounceU &);

    public:
	CkBounceU(void);
	virtual ~CkBounceU(void);

	static CkBounceU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The bounced email address when a bounced email is recognized.
	void get_BounceAddress(CkString &str);
	// The bounced email address when a bounced email is recognized.
	const uint16_t *bounceAddress(void);

	// The raw body of the bounced mail.
	void get_BounceData(CkString &str);
	// The raw body of the bounced mail.
	const uint16_t *bounceData(void);

	// A number representing the type of bounce that was recognized.
	// A value of 0 indicates "No Bounce". Other values are:
	// 
	// 1. Hard Bounce. The email could not be delivered and BounceAddress contains the
	// failed email address.
	// 2. Soft Bounce. A temporary condition exists causing the email delivery to fail.
	// The BounceAddress property contains the failed email address.
	// 3. General Bounced Mail, cannot determine if it is hard or soft, and the email
	// address is not available.
	// 4. General Bounced Mail, cannot determine if it is hard or soft, but an email
	// address is available.
	// 5. Mail Block. A bounce occured because the sender was blocked.
	// 6. Auto-Reply/Out-of-Office email.
	// 7. Transient message, such as "Delivery Status / No Action Required".
	// 8. Subscribe request.
	// 9. Unsubscribe request.
	// 10. Virus email notification.
	// 11. Suspected Bounce, but no other information is available
	// 12. Challenge/Response - Auto-reply message sent by SPAM software where only
	// verified email addresses are accepted.
	// 13. Address Change Notification Messages.
	// 14. Success DSN indicating that the message was successfully relayed.
	// 15. Abuse/fraud feedback report.
	int get_BounceType(void);



	// ----------------------
	// Methods
	// ----------------------
	// Examines an email and sets the properties (BounceType, BounceAddress,
	// BounceData) according to how the email is classified. This feature can only be
	// used if Chilkat Mail is downloaded and installed, and it also requires Chilkat
	// Mail to be licensed in addition to Chilkat Bounce.
	bool ExamineEmail(CkEmailU &email);

	// Examines an email from a .eml file and sets the properties (BounceType,
	// BounceAddress, BounceData) according to how the email is classified.
	bool ExamineEml(const uint16_t *emlFilename);

	// Examines an email represented as raw MIME text and sets the properties
	// (BounceType, BounceAddress, BounceData) according to how the email is
	// classified. The return value is 1 for a successful classification, or 0 for a
	// failure.
	bool ExamineMime(const uint16_t *mimeText);

	// Unlocks the component. This must be called once at the beginning of your program
	// to unlock the component. A purchased unlock code is provided when the Bounce
	// component is licensed.
	// 
	// A purchased unlock code for the bounce component/library will included the
	// substring "BOUNCE", or can be a Bundle unlock code.
	// 
	bool UnlockComponent(const uint16_t *unlockCode);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
