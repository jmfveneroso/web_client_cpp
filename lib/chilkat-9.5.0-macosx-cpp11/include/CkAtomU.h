// CkAtomU.h: interface for the CkAtomU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkAtomU_H
#define _CkAtomU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkDateTimeU;
class CkTaskU;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkAtomU
class CK_VISIBLE_PUBLIC CkAtomU  : public CkClassWithCallbacksU
{
    private:
	bool m_cbOwned;

	// Don't allow assignment or copying these objects.
	CkAtomU(const CkAtomU &);
	CkAtomU &operator=(const CkAtomU &);

    public:
	CkAtomU(void);
	virtual ~CkAtomU(void);

	static CkAtomU *createNew(void);
	

	CkAtomU(bool bCallbackOwned);
	static CkAtomU *createNew(bool bCallbackOwned);

	
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
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	bool get_AbortCurrent(void);

	// Number of entries in the Atom document.
	int get_NumEntries(void);



	// ----------------------
	// Methods
	// ----------------------
	// Adds a new element to the Atom document. The tag is a string such as "title",
	// "subtitle", "summary", etc. Returns the index of the element added, or -1 for
	// failure.
	int AddElement(const uint16_t *tag, const uint16_t *value);

	// Adds a new date-formatted element to the Atom document. The tag is a string
	// such as "created", "modified", "issued", etc. Returns the index of the element
	// added, or -1 for failure.
	int AddElementDate(const uint16_t *tag, SYSTEMTIME &dateTime);

	// Adds a new date-formatted element to the Atom document. The tag is a string
	// such as "created", "modified", "issued", etc. The dateTimeStr should be an RFC822
	// formatted date/time string such as "Tue, 25 Sep 2012 12:25:32 -0500". Returns
	// the index of the element added, or -1 for failure.
	int AddElementDateStr(const uint16_t *tag, const uint16_t *dateTimeStr);

	// Adds a new date-formatted element to the Atom document. The tag is a string such
	// as "created", "modified", "issued", etc. Returns the index of the element added,
	// or -1 for failure.
	int AddElementDt(const uint16_t *tag, CkDateTimeU &dateTime);

	// Adds a new HTML formatted element to the Atom document. Returns the index of the
	// element added, or -1 for failure.
	int AddElementHtml(const uint16_t *tag, const uint16_t *htmlStr);

	// Adds a new XHTML formatted element to the Atom document. Returns the index of
	// the element added, or -1 for failure.
	int AddElementXHtml(const uint16_t *tag, const uint16_t *xmlStr);

	// Adds a new XML formatted element to the Atom document. Returns the index of the
	// element added, or -1 for failure.
	int AddElementXml(const uint16_t *tag, const uint16_t *xmlStr);

	// Adds an "entry" Atom XML document to the caller's Atom document.
	void AddEntry(const uint16_t *xmlStr);

	// Adds a link to the Atom document.
	void AddLink(const uint16_t *rel, const uint16_t *href, const uint16_t *title, const uint16_t *typ);

	// Adds a person to the Atom document. The tag should be a string such as "author",
	// "contributor", etc. If a piece of information is not known, an empty string or
	// NULL value may be passed.
	void AddPerson(const uint16_t *tag, const uint16_t *name, const uint16_t *uri, const uint16_t *email);

	// Removes the Nth occurrence of a given element from the Atom document. Indexing
	// begins at 0. For example, to remove the 2nd category, set tag = "category" and
	// index = 1.
	void DeleteElement(const uint16_t *tag, int index);

	// Remove an attribute from an element.The index should be 0 unless there are
	// multiple elements having the same tag, in which case it selects the Nth
	// occurrence based on the index ( 0 = first occurrence ).
	void DeleteElementAttr(const uint16_t *tag, int index, const uint16_t *attrName);

	// Deletes a person from the Atom document. The tag is a string such as "author".
	// The index should be 0 unless there are multiple elements having the same tag, in
	// which case it selects the Nth occurrence based on the index. For example,
	// DeletePerson("author",2) deletes the 3rd author.
	void DeletePerson(const uint16_t *tag, int index);

	// Download an Atom feed from the Internet and load it into the Atom object.
	bool DownloadAtom(const uint16_t *url);

	// Creates an asynchronous task to call the DownloadAtom method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadAtomAsync(const uint16_t *url);

	// Returns the content of the Nth element having a specified tag.
	bool GetElement(const uint16_t *tag, int index, CkString &outStr);
	// Returns the content of the Nth element having a specified tag.
	const uint16_t *getElement(const uint16_t *tag, int index);
	// Returns the content of the Nth element having a specified tag.
	const uint16_t *element(const uint16_t *tag, int index);

	// Returns the value of an element's attribute. The element is selected by the tag
	// name and the index (the Nth element having a specific tag) and the attribute is
	// selected by name.
	bool GetElementAttr(const uint16_t *tag, int index, const uint16_t *attrName, CkString &outStr);
	// Returns the value of an element's attribute. The element is selected by the tag
	// name and the index (the Nth element having a specific tag) and the attribute is
	// selected by name.
	const uint16_t *getElementAttr(const uint16_t *tag, int index, const uint16_t *attrName);
	// Returns the value of an element's attribute. The element is selected by the tag
	// name and the index (the Nth element having a specific tag) and the attribute is
	// selected by name.
	const uint16_t *elementAttr(const uint16_t *tag, int index, const uint16_t *attrName);

	// The number of elements having a specific tag.
	int GetElementCount(const uint16_t *tag);

	// Returns an element's value as a date/time.
	bool GetElementDate(const uint16_t *tag, int index, SYSTEMTIME &outSysTime);

	// Returns an element's value as a date/time in an RFC822 formatted string, such as
	// such as "Tue, 25 Sep 2012 12:25:32 -0500".
	bool GetElementDateStr(const uint16_t *tag, int index, CkString &outStr);
	// Returns an element's value as a date/time in an RFC822 formatted string, such as
	// such as "Tue, 25 Sep 2012 12:25:32 -0500".
	const uint16_t *getElementDateStr(const uint16_t *tag, int index);
	// Returns an element's value as a date/time in an RFC822 formatted string, such as
	// such as "Tue, 25 Sep 2012 12:25:32 -0500".
	const uint16_t *elementDateStr(const uint16_t *tag, int index);

	// Returns an element's value as a date/time object.
	// The caller is responsible for deleting the object returned by this method.
	CkDateTimeU *GetElementDt(const uint16_t *tag, int index);

	// Returns the Nth entry as an Atom object. (Indexing begins at 0)
	// The caller is responsible for deleting the object returned by this method.
	CkAtomU *GetEntry(int index);

	// Returns the href attribute of the link having a specified "rel" attribute (such
	// as "service.feed", "alternate", etc.).
	bool GetLinkHref(const uint16_t *relName, CkString &outStr);
	// Returns the href attribute of the link having a specified "rel" attribute (such
	// as "service.feed", "alternate", etc.).
	const uint16_t *getLinkHref(const uint16_t *relName);
	// Returns the href attribute of the link having a specified "rel" attribute (such
	// as "service.feed", "alternate", etc.).
	const uint16_t *linkHref(const uint16_t *relName);

	// Returns a piece of information about a person. To get the 2nd author's name,
	// call GetPersonInfo("author",1,"name").
	bool GetPersonInfo(const uint16_t *tag, int index, const uint16_t *tag2, CkString &outStr);
	// Returns a piece of information about a person. To get the 2nd author's name,
	// call GetPersonInfo("author",1,"name").
	const uint16_t *getPersonInfo(const uint16_t *tag, int index, const uint16_t *tag2);
	// Returns a piece of information about a person. To get the 2nd author's name,
	// call GetPersonInfo("author",1,"name").
	const uint16_t *personInfo(const uint16_t *tag, int index, const uint16_t *tag2);

	// Returns the value of an attribute on the top-level XML node. The tag of a
	// top-level Atom XML node is typically "feed" or "entry", and it might have
	// attributes such as "xmlns" and "xml:lang".
	bool GetTopAttr(const uint16_t *attrName, CkString &outStr);
	// Returns the value of an attribute on the top-level XML node. The tag of a
	// top-level Atom XML node is typically "feed" or "entry", and it might have
	// attributes such as "xmlns" and "xml:lang".
	const uint16_t *getTopAttr(const uint16_t *attrName);
	// Returns the value of an attribute on the top-level XML node. The tag of a
	// top-level Atom XML node is typically "feed" or "entry", and it might have
	// attributes such as "xmlns" and "xml:lang".
	const uint16_t *topAttr(const uint16_t *attrName);

	// True (1) if the element exists in the Atom document. Otherwise 0.
	bool HasElement(const uint16_t *tag);

	// Loads the Atom document from an XML string.
	bool LoadXml(const uint16_t *xmlStr);

	// Initializes the Atom document to be a new "entry".
	void NewEntry(void);

	// Initializes the Atom document to be a new "feed".
	void NewFeed(void);

	// Adds or replaces an attribute on an element.
	void SetElementAttr(const uint16_t *tag, int index, const uint16_t *attrName, const uint16_t *attrValue);

	// Adds or replaces an attribute on the top-level XML node of the Atom document.
	void SetTopAttr(const uint16_t *attrName, const uint16_t *value);

	// Serializes the Atom document to an XML string.
	bool ToXmlString(CkString &outStr);
	// Serializes the Atom document to an XML string.
	const uint16_t *toXmlString(void);

	// Replaces the content of an element.
	void UpdateElement(const uint16_t *tag, int index, const uint16_t *value);

	// Replaces the content of a date-formatted element.
	void UpdateElementDate(const uint16_t *tag, int index, SYSTEMTIME &dateTime);

	// Replaces the content of a date-formatted element. The index should be an RFC822
	// formatted date/time string.
	void UpdateElementDateStr(const uint16_t *tag, int index, const uint16_t *dateTimeStr);

	// Replaces the content of a date-formatted element.
	void UpdateElementDt(const uint16_t *tag, int index, CkDateTimeU &dateTime);

	// Replaces the content of an HTML element.
	void UpdateElementHtml(const uint16_t *tag, int index, const uint16_t *htmlStr);

	// Replaces the content of an XHTML element.
	void UpdateElementXHtml(const uint16_t *tag, int index, const uint16_t *xmlStr);

	// Replaces the content of an XML element.
	void UpdateElementXml(const uint16_t *tag, int index, const uint16_t *xmlStr);

	// Replaces the content of a person. To update the 3rd author, call
	// UpdatePerson("author",2,"new name","new URL","new email"). If a piece of
	// information is not known, pass an empty string or a NULL.
	void UpdatePerson(const uint16_t *tag, int index, const uint16_t *name, const uint16_t *uri, const uint16_t *email);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
