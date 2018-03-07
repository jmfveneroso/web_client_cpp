// CkHtmlToTextU.h: interface for the CkHtmlToTextU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkHtmlToTextU_H
#define _CkHtmlToTextU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"




#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkHtmlToTextU
class CK_VISIBLE_PUBLIC CkHtmlToTextU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkHtmlToTextU(const CkHtmlToTextU &);
	CkHtmlToTextU &operator=(const CkHtmlToTextU &);

    public:
	CkHtmlToTextU(void);
	virtual ~CkHtmlToTextU(void);

	static CkHtmlToTextU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// If true, then HTML entities are automatically decoded. For example _AMP_amp;
	// is automatically decoded to _AMP_. If this property is set to false, then HTML
	// entities are not decoded. The default value is true.
	bool get_DecodeHtmlEntities(void);
	// If true, then HTML entities are automatically decoded. For example _AMP_amp;
	// is automatically decoded to _AMP_. If this property is set to false, then HTML
	// entities are not decoded. The default value is true.
	void put_DecodeHtmlEntities(bool newVal);

	// Used to control wrapping of text. The default value is 80. When the text gets
	// close to this margin, the converter will try to break the line at a SPACE
	// character.
	int get_RightMargin(void);
	// Used to control wrapping of text. The default value is 80. When the text gets
	// close to this margin, the converter will try to break the line at a SPACE
	// character.
	void put_RightMargin(int newVal);

	// If true, then link URL's are preserved inline. For example, the following HTML
	// fragment:
	// 
	// _LT_p>Test _LT_a href="http://www.chilkatsoft.com/">chilkat_LT_/a>_LT_/p>
	// 
	// converts to:
	// Test chilkat _LT_http://www.chilkatsoft.com/>
	// If this property is false, the above HTML would convert to:
	// Test chilkat
	// The default value of this property is true.
	// 
	bool get_SuppressLinks(void);
	// If true, then link URL's are preserved inline. For example, the following HTML
	// fragment:
	// 
	// _LT_p>Test _LT_a href="http://www.chilkatsoft.com/">chilkat_LT_/a>_LT_/p>
	// 
	// converts to:
	// Test chilkat _LT_http://www.chilkatsoft.com/>
	// If this property is false, the above HTML would convert to:
	// Test chilkat
	// The default value of this property is true.
	// 
	void put_SuppressLinks(bool newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Returns true if the component is already unlocked. Otherwise returns false.
	bool IsUnlocked(void);

	// Convenience method for reading a text file into a string. The character encoding
	// of the text file is specified by srcCharset. Valid values, such as "iso-8895-1" or
	// "utf-8" are listed at: List of Charsets
	// <http://blog.chilkatsoft.com/?p=463> .
	bool ReadFileToString(const uint16_t *filename, const uint16_t *srcCharset, CkString &outStr);
	// Convenience method for reading a text file into a string. The character encoding
	// of the text file is specified by srcCharset. Valid values, such as "iso-8895-1" or
	// "utf-8" are listed at: List of Charsets
	// <http://blog.chilkatsoft.com/?p=463> .
	const uint16_t *readFileToString(const uint16_t *filename, const uint16_t *srcCharset);

	// Converts HTML to plain-text.
	bool ToText(const uint16_t *html, CkString &outStr);
	// Converts HTML to plain-text.
	const uint16_t *toText(const uint16_t *html);

	// Unlocks the component. An arbitrary unlock code may be passed to automatically
	// begin a 30-day trial.
	// 
	// This class is included with the Chilkat HTML-to-XML conversion component
	// license.
	// 
	bool UnlockComponent(const uint16_t *code);

	// Convenience method for saving a string to a file. The character encoding of the
	// output text file is specified by charset (the string is converted to this charset
	// when writing). Valid values, such as "iso-8895-1" or "utf-8" are listed at: List
	// of Charsets
	// <http://blog.chilkatsoft.com/?p=463> .
	bool WriteStringToFile(const uint16_t *stringToWrite, const uint16_t *filename, const uint16_t *charset);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
