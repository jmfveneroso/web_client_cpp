// CkHtmlToXmlU.h: interface for the CkHtmlToXmlU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkHtmlToXmlU_H
#define _CkHtmlToXmlU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkHtmlToXmlU
class CK_VISIBLE_PUBLIC CkHtmlToXmlU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkHtmlToXmlU(const CkHtmlToXmlU &);
	CkHtmlToXmlU &operator=(const CkHtmlToXmlU &);

    public:
	CkHtmlToXmlU(void);
	virtual ~CkHtmlToXmlU(void);

	static CkHtmlToXmlU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// If set to true, then any non-standard HTML tags will be dropped when converting
	// to XML.
	bool get_DropCustomTags(void);
	// If set to true, then any non-standard HTML tags will be dropped when converting
	// to XML.
	void put_DropCustomTags(bool newVal);

	// The HTML to be converted by the ToXml method. To convert HTML to XML, first set
	// this property to the HTML string and then call ToXml. The ConvertFile method can
	// do file-to-file conversions.
	void get_Html(CkString &str);
	// The HTML to be converted by the ToXml method. To convert HTML to XML, first set
	// this property to the HTML string and then call ToXml. The ConvertFile method can
	// do file-to-file conversions.
	const uint16_t *html(void);
	// The HTML to be converted by the ToXml method. To convert HTML to XML, first set
	// this property to the HTML string and then call ToXml. The ConvertFile method can
	// do file-to-file conversions.
	void put_Html(const uint16_t *newVal);

	// Determines how to handle   HTML entities. The default value, 0 will cause
	// _AMP_nbsp; entites to be convert to normal space characters (ASCII value 32). If
	// this property is set to 1, then _AMP_nbsp;'s will be converted to _AMP_#160. If
	// set to 2, then _AMP_nbps;'s are dropped. If set to 3, then _AMP_nbsp's are left
	// unmodified.
	int get_Nbsp(void);
	// Determines how to handle   HTML entities. The default value, 0 will cause
	// _AMP_nbsp; entites to be convert to normal space characters (ASCII value 32). If
	// this property is set to 1, then _AMP_nbsp;'s will be converted to _AMP_#160. If
	// set to 2, then _AMP_nbps;'s are dropped. If set to 3, then _AMP_nbsp's are left
	// unmodified.
	void put_Nbsp(int newVal);

	// The charset, such as "utf-8" or "iso-8859-1" of the XML to be created. If
	// XmlCharset is empty, the XML is created in the same character encoding as the
	// HTML. Otherwise the HTML is converted XML and converted to this charset.
	void get_XmlCharset(CkString &str);
	// The charset, such as "utf-8" or "iso-8859-1" of the XML to be created. If
	// XmlCharset is empty, the XML is created in the same character encoding as the
	// HTML. Otherwise the HTML is converted XML and converted to this charset.
	const uint16_t *xmlCharset(void);
	// The charset, such as "utf-8" or "iso-8859-1" of the XML to be created. If
	// XmlCharset is empty, the XML is created in the same character encoding as the
	// HTML. Otherwise the HTML is converted XML and converted to this charset.
	void put_XmlCharset(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Converts an HTML file to a well-formed XML file that can be parsed for the
	// purpose of programmatically extracting information.
	bool ConvertFile(const uint16_t *inHtmlPath, const uint16_t *destXmlPath);

	// Allows for any specified tag to be dropped from the output XML. To drop more
	// than one tag, call this method once for each tag type to be dropped.
	void DropTagType(const uint16_t *tagName);

	// Causes text formatting tags to be dropped from the XML output. Text formatting
	// tags are: b, font, i, u, br, center, em, strong, big, tt, s, small, strike, sub,
	// and sup.
	void DropTextFormattingTags(void);

	// Returns true if the component is already unlocked. Otherwise returns false.
	bool IsUnlocked(void);

	// Convenience method for reading a complete file into a byte array.
	bool ReadFile(const uint16_t *path, CkByteData &outBytes);

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

	// Sets the Html property from a byte array.
	void SetHtmlBytes(CkByteData &inData);

	// Sets the Html property by loading the HTML from a file.
	bool SetHtmlFromFile(const uint16_t *filename);

	// Converts the HTML in the "Html" property to XML and returns the XML string.
	bool ToXml(CkString &outStr);
	// Converts the HTML in the "Html" property to XML and returns the XML string.
	const uint16_t *toXml(void);

	// Causes a specified type of tag to NOT be dropped in the output XML.
	void UndropTagType(const uint16_t *tagName);

	// Causes text formatting tags to NOT be dropped from the XML output. Text
	// formatting tags are: b, font, i, u, br, center, em, strong, big, tt, s, small,
	// strike, sub, and sup.
	// 
	// Important: Text formatting tags are dropped by default. Call this method to
	// prevent text formatting tags from being dropped.
	// 
	void UndropTextFormattingTags(void);

	// Unlocks the component. An arbitrary unlock code may be passed to automatically
	// begin a 30-day trial.
	bool UnlockComponent(const uint16_t *unlockCode);

	// Convenience method for saving a byte array to a file.
	bool WriteFile(const uint16_t *path, CkByteData &fileData);

	// Convenience method for saving a string to a file. The character encoding of the
	// output text file is specified by charset (the string is converted to this charset
	// when writing). Valid values, such as "iso-8895-1" or "utf-8" are listed at: List
	// of Charsets
	// <http://blog.chilkatsoft.com/?p=463> .
	bool WriteStringToFile(const uint16_t *stringToWrite, const uint16_t *filename, const uint16_t *charset);

	// This is the same as the "ToXml" method. It converts the HTML in the "Html"
	// property to XML and returns the XML string.
	bool Xml(CkString &outStr);
	// This is the same as the "ToXml" method. It converts the HTML in the "Html"
	// property to XML and returns the XML string.
	const uint16_t *xml(void);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
