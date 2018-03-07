// CkRssU.h: interface for the CkRssU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkRssU_H
#define _CkRssU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkTaskU;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkRssU
class CK_VISIBLE_PUBLIC CkRssU  : public CkClassWithCallbacksU
{
    private:
	bool m_cbOwned;

	// Don't allow assignment or copying these objects.
	CkRssU(const CkRssU &);
	CkRssU &operator=(const CkRssU &);

    public:
	CkRssU(void);
	virtual ~CkRssU(void);

	static CkRssU *createNew(void);
	

	CkRssU(bool bCallbackOwned);
	static CkRssU *createNew(bool bCallbackOwned);

	
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
	// The number of channels in the RSS document.
	int get_NumChannels(void);

	// The number of items in the channel.
	int get_NumItems(void);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a new channel to the RSS document. Returns the Rss object representing the
	// Channel which can then be edited.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *AddNewChannel(void);

	// Adds a new image to the RSS document. Returns the Rss object representing the
	// image, which can then be edited.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *AddNewImage(void);

	// Adds a new Item to an Rss channel. Returns the Rss object representing the item
	// which can then be edited.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *AddNewItem(void);

	// Downloads an RSS document from the Internet and populates the Rss object with
	// the contents.
	bool DownloadRss(const uint16_t *url);

	// Creates an asynchronous task to call the DownloadRss method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadRssAsync(const uint16_t *url);

	// Returns the value of a sub-element attribute. For example, to get the value of
	// the "isPermaLink" attribute of the "guid" sub-element, call
	// item.GetAttr("guid","isPermaLink").
	bool GetAttr(const uint16_t *tag, const uint16_t *attrName, CkString &outStr);
	// Returns the value of a sub-element attribute. For example, to get the value of
	// the "isPermaLink" attribute of the "guid" sub-element, call
	// item.GetAttr("guid","isPermaLink").
	const uint16_t *getAttr(const uint16_t *tag, const uint16_t *attrName);
	// Returns the value of a sub-element attribute. For example, to get the value of
	// the "isPermaLink" attribute of the "guid" sub-element, call
	// item.GetAttr("guid","isPermaLink").
	const uint16_t *attr(const uint16_t *tag, const uint16_t *attrName);

	// Returns the Nth channel of an RSS document. Usually there is only 1 channel per
	// document, so the index argument should be set to 0.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *GetChannel(int index);

	// Return the number of sub-elements with a specific tag.
	int GetCount(const uint16_t *tag);

	// Return the value of a sub-element in date/time format.
	bool GetDate(const uint16_t *tag, SYSTEMTIME &outSysTime);

	// The same as GetDate, except the date/time is returned in RFC822 string format.
	bool GetDateStr(const uint16_t *tag, CkString &outStr);
	// The same as GetDate, except the date/time is returned in RFC822 string format.
	const uint16_t *getDateStr(const uint16_t *tag);
	// The same as GetDate, except the date/time is returned in RFC822 string format.
	const uint16_t *dateStr(const uint16_t *tag);

	// Return the image associated with the channel.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *GetImage(void);

	// Return the value of a numeric sub-element as an integer.
	int GetInt(const uint16_t *tag);

	// Return the Nth item of a channel as an RSS object.
	// The caller is responsible for deleting the object returned by this method.
	CkRssU *GetItem(int index);

	// Return the value of an sub-element as a string.
	bool GetString(const uint16_t *tag, CkString &outStr);
	// Return the value of an sub-element as a string.
	const uint16_t *getString(const uint16_t *tag);
	// Return the value of an sub-element as a string.
	const uint16_t *string(const uint16_t *tag);

	// Load an RSS document from a file.
	bool LoadRssFile(const uint16_t *filePath);

	// Loads an RSS feed document from an in-memory string.
	bool LoadRssString(const uint16_t *rssString);

	// Get an attribute value for the Nth sub-element having a specific tag. As an
	// example, an RSS item may have several "category" sub-elements. To get the value
	// of the "domain" attribute for the 3rd category, call
	// MGetAttr("category",2,"domain").
	bool MGetAttr(const uint16_t *tag, int index, const uint16_t *attrName, CkString &outStr);
	// Get an attribute value for the Nth sub-element having a specific tag. As an
	// example, an RSS item may have several "category" sub-elements. To get the value
	// of the "domain" attribute for the 3rd category, call
	// MGetAttr("category",2,"domain").
	const uint16_t *mGetAttr(const uint16_t *tag, int index, const uint16_t *attrName);

	// Get the value of the Nth occurrence of a sub-element. Indexing begins at 0.
	bool MGetString(const uint16_t *tag, int index, CkString &outStr);
	// Get the value of the Nth occurrence of a sub-element. Indexing begins at 0.
	const uint16_t *mGetString(const uint16_t *tag, int index);

	// Set an attribute on the Nth occurrence of a sub-element.
	bool MSetAttr(const uint16_t *tag, int idx, const uint16_t *attrName, const uint16_t *value);

	// Set the value of the Nth occurrence of a sub-element. Indexing begins at 0.
	bool MSetString(const uint16_t *tag, int idx, const uint16_t *value);

	// Clears the RSS document.
	void NewRss(void);

	// Removes a sub-element from the RSS document.
	void Remove(const uint16_t *tag);

	// Sets the value of a sub-element attribute.
	void SetAttr(const uint16_t *tag, const uint16_t *attrName, const uint16_t *value);

	// Sets the value of a date/time sub-element.
	void SetDate(const uint16_t *tag, SYSTEMTIME &dateTime);

	// Sets the value of a date/time sub-element to the current system date/time.
	void SetDateNow(const uint16_t *tag);

	// The same as SetDate, except the date/time is passed as an RFC822 string.
	void SetDateStr(const uint16_t *tag, const uint16_t *dateTimeStr);

	// Sets the value of an integer sub-element.
	void SetInt(const uint16_t *tag, int value);

	// Sets the value of a sub-element.
	void SetString(const uint16_t *tag, const uint16_t *value);

	// Returns the RSS document as an XML string.
	bool ToXmlString(CkString &outStr);
	// Returns the RSS document as an XML string.
	const uint16_t *toXmlString(void);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
